/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

#include "bus-internal.h"
#include "sd-bus.h"

sd_bus_slot* bus_slot_allocate(sd_bus* bus, bool floating, BusSlotType type,
                               size_t extra, void* userdata);

void bus_slot_disconnect(sd_bus_slot* slot, bool unref);
