/* Copyright 2017 IBM Corp.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * 	http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
 * implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <assert.h>
#include <errno.h>
#include <inttypes.h>
#include <libpdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"
#include "optcmd.h"
#include "path.h"

#define REG_CR -5
#define REG_XER -4
#define REG_MEM -3
#define REG_MSR -2
#define REG_NIA -1
#define REG_R31 31

static void print_proc_reg(struct pdbg_target* target, int reg, uint64_t* value,
                           int rc)
{
    int proc_index, chip_index, thread_index;

    thread_index = pdbg_target_index(target);
    chip_index = pdbg_parent_index(target, "core");
    proc_index = pdbg_parent_index(target, "pib");
    printf("p%d:c%d:t%d: ", proc_index, chip_index, thread_index);

    if (reg == REG_MSR)
        printf("msr: ");
    else if (reg == REG_NIA)
        printf("nia: ");
    else if (reg == REG_XER)
        printf("xer: ");
    else if (reg == REG_CR)
        printf("cr: ");
    else if (reg > REG_R31)
        printf("spr%03d: ", reg - REG_R31);
    else if (reg >= 0 && reg <= 31)
        printf("gpr%02d: ", reg);

    if (rc == 1)
    {
        printf("Check threadstatus - not all threads on this chiplet are "
               "quiesced\n");
    }
    else if (rc == 2)
        printf("Thread in incorrect state\n");
    else
        printf("0x%016" PRIx64 "\n", *value);
}

static int putprocreg(struct pdbg_target* target, int reg, uint64_t* value)
{
    uint32_t u32;
    int rc;

    if (reg == REG_MSR)
        rc = thread_putmsr(target, *value);
    else if (reg == REG_NIA)
        rc = thread_putnia(target, *value);
    else if (reg == REG_XER)
        rc = thread_putxer(target, *value);
    else if (reg == REG_CR)
    {
        u32 = *value;
        rc = thread_putcr(target, u32);
    }
    else if (reg > REG_R31)
        rc = thread_putspr(target, reg - REG_R31, *value);
    else if (reg >= 0 && reg <= 31)
        rc = thread_putgpr(target, reg, *value);
    else
        assert(0);

    return rc;
}

static int getprocreg(struct pdbg_target* target, uint32_t reg, uint64_t* value)
{
    uint32_t u32 = 0;
    int rc;

    if (reg == REG_MSR)
        rc = thread_getmsr(target, value);
    else if (reg == REG_NIA)
        rc = thread_getnia(target, value);
    else if (reg == REG_XER)
        rc = thread_getxer(target, value);
    else if (reg == REG_CR)
    {
        rc = thread_getcr(target, &u32);
        *value = u32;
    }
    else if (reg > REG_R31)
        rc = thread_getspr(target, reg - REG_R31, value);
    else if (reg >= 0 && reg <= 31)
        rc = thread_getgpr(target, reg, value);
    else
        assert(0);

    return rc;
}

static int getreg(int reg)
{
    struct pdbg_target* target;
    int count = 0;

    for_each_path_target_class("thread", target)
    {
        uint64_t value = 0;
        int rc;

        if (pdbg_target_status(target) != PDBG_TARGET_ENABLED)
            continue;

        rc = getprocreg(target, reg, &value);
        print_proc_reg(target, reg, &value, rc);

        if (!rc)
            count++;
    }

    return count;
}

static int putreg(int reg, uint64_t* value)
{
    struct pdbg_target* target;
    int count = 0;

    for_each_path_target_class("thread", target)
    {
        int rc;

        if (pdbg_target_status(target) != PDBG_TARGET_ENABLED)
            continue;

        rc = putprocreg(target, reg, value);
        print_proc_reg(target, reg, value, rc);

        if (!rc)
            count++;
    }

    return count;
}

static int getgpr(int gpr)
{
    return getreg(gpr);
}
OPTCMD_DEFINE_CMD_WITH_ARGS(getgpr, getgpr, (GPR));

static int putgpr(int gpr, uint64_t data)
{
    return putreg(gpr, &data);
}
OPTCMD_DEFINE_CMD_WITH_ARGS(putgpr, putgpr, (GPR, DATA));

static int getnia(void)
{
    return getreg(REG_NIA);
}
OPTCMD_DEFINE_CMD(getnia, getnia);

static int putnia(uint64_t nia)
{
    return putreg(REG_NIA, &nia);
}
OPTCMD_DEFINE_CMD_WITH_ARGS(putnia, putnia, (DATA));

static int getspr(int spr)
{
    return getreg(spr + REG_R31);
}
OPTCMD_DEFINE_CMD_WITH_ARGS(getspr, getspr, (SPR));

static int putspr(int spr, uint64_t data)
{
    return putreg(spr + REG_R31, &data);
}
OPTCMD_DEFINE_CMD_WITH_ARGS(putspr, putspr, (SPR, DATA));

static int getmsr(void)
{
    return getreg(REG_MSR);
}
OPTCMD_DEFINE_CMD(getmsr, getmsr);

static int putmsr(uint64_t data)
{
    return putreg(REG_MSR, &data);
}
OPTCMD_DEFINE_CMD_WITH_ARGS(putmsr, putmsr, (DATA));

static int getxer(void)
{
    return getreg(REG_XER);
}
OPTCMD_DEFINE_CMD(getxer, getxer);

static int putxer(uint64_t data)
{
    return putreg(REG_XER, &data);
}
OPTCMD_DEFINE_CMD_WITH_ARGS(putxer, putxer, (DATA));

static int getcr(void)
{
    return getreg(REG_CR);
}
OPTCMD_DEFINE_CMD(getcr, getcr);

static int putcr(uint32_t data)
{
    uint64_t u64 = data;
    return putreg(REG_CR, &u64);
}
OPTCMD_DEFINE_CMD_WITH_ARGS(putcr, putcr, (DATA32));
