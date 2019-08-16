/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

#include "sd-bus-vtable.h"
#include "sd-bus.h"
#include "unit.h"

extern const sd_bus_vtable bus_mount_vtable[];

int bus_mount_set_property(Unit* u, const char* name, sd_bus_message* message,
                           UnitWriteFlags flags, sd_bus_error* error);
int bus_mount_commit_properties(Unit* u);
