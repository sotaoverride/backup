/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

#include "output-mode.h"
#include "sd-bus.h"

int unit_show_processes(sd_bus* bus, const char* unit, const char* cgroup_path,
                        const char* prefix, unsigned n_columns,
                        OutputFlags flags, sd_bus_error* error);
