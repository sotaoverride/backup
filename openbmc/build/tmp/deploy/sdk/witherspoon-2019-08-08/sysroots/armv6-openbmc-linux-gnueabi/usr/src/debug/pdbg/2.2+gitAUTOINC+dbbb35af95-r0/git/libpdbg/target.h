/* Copyright 2016 IBM Corp.
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
#ifndef __TARGET_H
#define __TARGET_H

#include <ccan/container_of/container_of.h>
#include <ccan/list/list.h>
#include <ccan/short_types/short_types.h>
#include <ccan/str/str.h>
#include <stdint.h>

#include "compiler.h"
#include "libpdbg.h"

enum chip_type
{
    CHIP_UNKNOWN,
    CHIP_P8,
    CHIP_P8NV,
    CHIP_P9
};

struct pdbg_target_class
{
    char* name;
    struct list_head targets;
    struct list_node class_head_link;
};

struct pdbg_target
{
    char* name;
    char* compatible;
    char* class;
    int (*probe)(struct pdbg_target* target);
    void (*release)(struct pdbg_target* target);
    uint64_t (*translate)(struct pdbg_target* target, uint64_t addr);
    int index;
    enum pdbg_target_status status;
    const char* dn_name;
    struct list_node list;
    struct list_head properties;
    struct list_head children;
    struct pdbg_target* parent;
    u32 phandle;
    bool probed;
    struct list_node class_link;
    void* priv;
};

struct pdbg_target* require_target_parent(struct pdbg_target* target);
struct pdbg_target_class* find_target_class(const char* name);
struct pdbg_target_class* require_target_class(const char* name);
struct pdbg_target_class* get_target_class(const char* name);
bool pdbg_target_is_class(struct pdbg_target* target, const char* class);

extern struct list_head empty_list;
extern struct list_head target_classes;

const char* pdbg_get_backend_option(void);

struct sbefifo* pib_to_sbefifo(struct pdbg_target* target);

#endif
