/* SPDX-License-Identifier: LGPL-2.1+ */

#include "plymouth-util.h"

#include <unistd.h>

bool plymouth_running(void)
{
    return access("/run/plymouth/pid", F_OK) >= 0;
}
