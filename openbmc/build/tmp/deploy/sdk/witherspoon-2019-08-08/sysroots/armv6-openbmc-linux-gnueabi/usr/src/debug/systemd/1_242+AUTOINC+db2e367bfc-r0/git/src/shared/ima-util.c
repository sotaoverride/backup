/* SPDX-License-Identifier: LGPL-2.1+ */

#include "ima-util.h"

#include <unistd.h>

static int use_ima_cached = -1;

bool use_ima(void)
{

    if (use_ima_cached < 0)
        use_ima_cached = access("/sys/kernel/security/ima/", F_OK) >= 0;

    return use_ima_cached;
}
