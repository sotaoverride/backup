/* This is an auto generated file. Do not edit. */
#pragma once

#include "count.hpp"
#include "data_types.hpp"
#include "elog.hpp"
#include "errors.hpp"
#include "event.hpp"
#include "journal.hpp"
#include "method.hpp"
#include "pathwatchimpl.hpp"
#include "propertywatchimpl.hpp"
#include "resolve_errors.hpp"
#include "sdbusplus.hpp"
#include "snmp_trap.hpp"

#include <array>
#include <chrono>
#include <string>

using namespace std::string_literals;
using namespace std::chrono_literals;

namespace phosphor
{
namespace dbus
{
namespace monitoring
{

struct ConfigMeta
{
    using Meta = std::array<std::string, 12>;

    static auto& get()
    {
        static const Meta meta = {
            "FAN"s,        "CHASSISSTATE"s,  "CHASSIS"s,      "PRESENT"s,
            "FUNCTIONAL"s, "CHASSIS_STATE"s, "COOLING_TYPE"s, "PROPERTY"s,
            "PATH"s,       "POWER SUPPLY"s,  "SENSOR"s,       "TEMP"s,
        };
        return meta;
    }
};

struct ConfigPaths
{
    using Paths = std::array<std::string, 67>;

    static auto& get()
    {
        static const Paths paths = {
            "/org/freedesktop/systemd1"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan0"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan1"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan2"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan3"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan0/fan0_0"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan0/fan0_1"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan1/fan1_0"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan1/fan1_1"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan2/fan2_0"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan2/fan2_1"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan3/fan3_0"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/fan3/fan3_1"s,
            "/xyz/openbmc_project/state/chassis0"s,
            "/xyz/openbmc_project/inventory/system/chassis"s,
            "/org/open_power/control/occ0"s,
            "/xyz/openbmc_project/logging"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/powersupply0"s,
            "/xyz/openbmc_project/inventory/system/chassis/motherboard/powersupply1"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core0_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core1_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core2_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core3_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core4_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core5_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core6_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core7_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core8_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core9_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core10_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core11_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core12_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core13_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core14_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core15_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core16_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core17_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core18_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core19_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core20_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core21_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core22_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p0_core23_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core0_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core1_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core2_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core3_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core4_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core5_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core6_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core7_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core8_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core9_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core10_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core11_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core12_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core13_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core14_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core15_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core16_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core17_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core18_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core19_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core20_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core21_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core22_temp"s,
            "/xyz/openbmc_project/sensors/temperature/p1_core23_temp"s,
        };
        return paths;
    }
};

struct ConfigInterfaces
{
    using Interfaces = std::array<std::string, 8>;

    static auto& get()
    {
        static const Interfaces interfaces = {
            "org.freedesktop.systemd1"s,
            "org.freedesktop.systemd1.Manager"s,
            "xyz.openbmc_project.Inventory.Item"s,
            "xyz.openbmc_project.State.Decorator.OperationalStatus"s,
            "xyz.openbmc_project.State.Chassis"s,
            "xyz.openbmc_project.Inventory.Decorator.CoolingType"s,
            "org.open_power.OCC.Status"s,
            "xyz.openbmc_project.Sensor.Value"s,
        };
        return interfaces;
    }
};

struct ConfigIntfAddPaths
{
    using Paths = std::array<std::string, 1>;

    static auto& get()
    {
        static const Paths paths = {
            "/xyz/openbmc_project/logging"s,
        };
        return paths;
    }
};

struct ConfigProperties
{
    using Properties = std::array<std::string, 9>;

    static auto& get()
    {
        static const Properties properties = {
            "StartUnit"s,         "Present"s,         "Functional"s,
            "CurrentPowerState"s, "WaterCooled"s,     "ThrottleProcTemp"s,
            "ThrottleProcPower"s, "ThrottleMemTemp"s, "Value"s,
        };
        return properties;
    }
};

struct ConfigPropertyStorage
{
    using Storage = std::array<std::tuple<any_ns::any, any_ns::any>, 71>;

    static auto& get()
    {
        static Storage storage;
        return storage;
    }
};

struct ConfigPropertyIndicies
{
    using PropertyIndicies = std::array<PropertyIndex, 32>;

    static auto& get()
    {
        static const PropertyIndicies propertyIndicies = {{
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[13],
                                            ConfigInterfaces::get()[4],
                                            ConfigProperties::get()[3]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[1],
                                               ConfigMeta::get()[5],
                                               ConfigPropertyStorage::get()[0]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[1],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[1]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[2],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[2]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[3],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[3]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[4],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[4]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[1],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[5]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[2],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[6]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[3],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[7]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[4],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[8]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[5],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[9]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[6],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[10]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[7],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[11]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[8],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[12]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[9],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[13]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[10],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[14]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[11],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[15]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[12],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[16]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[14],
                                            ConfigInterfaces::get()[5],
                                            ConfigProperties::get()[4]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[2], ConfigMeta::get()[6],
                        ConfigPropertyStorage::get()[17]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[15],
                                            ConfigInterfaces::get()[6],
                                            ConfigProperties::get()[5]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[8], ConfigMeta::get()[7],
                        ConfigPropertyStorage::get()[18]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[15],
                                            ConfigInterfaces::get()[6],
                                            ConfigProperties::get()[6]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[8], ConfigMeta::get()[7],
                        ConfigPropertyStorage::get()[19]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[15],
                                            ConfigInterfaces::get()[6],
                                            ConfigProperties::get()[7]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[8], ConfigMeta::get()[7],
                        ConfigPropertyStorage::get()[20]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[1],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[1]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[1],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[5]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[2],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[2]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[2],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[6]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[3],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[3]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[3],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[7]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[4],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[4]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[4],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[8]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[1],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[1]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[1],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[5]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[2],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[2]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[2],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[6]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[3],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[3]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[3],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[7]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[4],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[4]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[4],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[8]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[13],
                                            ConfigInterfaces::get()[4],
                                            ConfigProperties::get()[3]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[1],
                                               ConfigMeta::get()[5],
                                               ConfigPropertyStorage::get()[0]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[14],
                                            ConfigInterfaces::get()[5],
                                            ConfigProperties::get()[4]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[2], ConfigMeta::get()[6],
                        ConfigPropertyStorage::get()[17]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[17],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[9], ConfigMeta::get()[3],
                        ConfigPropertyStorage::get()[21]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[18],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[9], ConfigMeta::get()[3],
                        ConfigPropertyStorage::get()[22]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[17],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[9], ConfigMeta::get()[3],
                        ConfigPropertyStorage::get()[21]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[18],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[9], ConfigMeta::get()[3],
                        ConfigPropertyStorage::get()[22]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[13],
                                            ConfigInterfaces::get()[4],
                                            ConfigProperties::get()[3]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[1],
                                               ConfigMeta::get()[5],
                                               ConfigPropertyStorage::get()[0]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[19],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[23]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[20],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[24]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[21],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[25]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[22],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[26]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[23],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[27]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[24],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[28]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[25],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[29]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[26],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[30]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[27],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[31]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[28],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[32]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[29],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[33]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[30],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[34]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[31],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[35]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[32],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[36]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[33],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[37]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[34],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[38]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[35],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[39]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[36],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[40]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[37],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[41]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[38],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[42]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[39],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[43]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[40],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[44]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[41],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[45]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[42],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[46]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[43],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[47]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[44],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[48]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[45],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[49]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[46],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[50]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[47],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[51]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[48],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[52]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[49],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[53]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[50],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[54]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[51],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[55]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[52],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[56]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[53],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[57]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[54],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[58]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[55],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[59]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[56],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[60]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[57],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[61]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[58],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[62]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[59],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[63]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[60],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[64]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[61],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[65]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[62],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[66]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[63],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[67]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[64],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[68]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[65],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[69]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[66],
                                            ConfigInterfaces::get()[7],
                                            ConfigProperties::get()[8]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[10],
                        ConfigMeta::get()[11],
                        ConfigPropertyStorage::get()[70]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[13],
                                            ConfigInterfaces::get()[4],
                                            ConfigProperties::get()[3]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[1],
                                               ConfigMeta::get()[5],
                                               ConfigPropertyStorage::get()[0]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[1],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[1]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[3],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[3]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[4],
                                            ConfigInterfaces::get()[2],
                                            ConfigProperties::get()[1]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[3],
                                               ConfigPropertyStorage::get()[4]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[1],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[5]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[3],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[7]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[4],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[8]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[5],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{ConfigMeta::get()[0],
                                               ConfigMeta::get()[4],
                                               ConfigPropertyStorage::get()[9]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[6],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[10]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[9],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[13]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[10],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[14]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[11],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[15]},
                },
                {
                    PropertyIndex::key_type{ConfigPaths::get()[12],
                                            ConfigInterfaces::get()[3],
                                            ConfigProperties::get()[2]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[0], ConfigMeta::get()[4],
                        ConfigPropertyStorage::get()[16]},
                },
            },
            {
                {
                    PropertyIndex::key_type{ConfigPaths::get()[14],
                                            ConfigInterfaces::get()[5],
                                            ConfigProperties::get()[4]},
                    PropertyIndex::mapped_type{
                        ConfigMeta::get()[2], ConfigMeta::get()[6],
                        ConfigPropertyStorage::get()[17]},
                },
            },
        }};
        return propertyIndicies;
    }
};

struct ConfigPropertyCallbackGroups
{
    using CallbackGroups = std::array<std::vector<size_t>, 49>;
    static auto& get()
    {
        static const CallbackGroups propertyCallbackGraph = {{
            {10, 11, 12},
            {3, 5, 7},
            {4, 6, 7},
            {9},
            {0},
            {2},
            {1},
            {13},
            {14},
            {15},
            {41, 43, 45, 47, 42, 44, 46, 48},
            {19},
            {41},
            {42},
            {43},
            {44},
            {45},
            {46},
            {47},
            {48},
            {20},
            {21},
            {50},
            {49},
            {24},
            {25},
            {26},
            {27},
            {23},
            {22},
            {28},
            {29},
            {30},
            {31},
            {61, 62},
            {55},
            {56},
            {57},
            {58},
            {59},
            {66, 67, 68},
            {65},
            {80, 81, 82},
            {73, 75, 77},
            {74, 76, 77},
            {79},
            {70},
            {72},
            {71},
        }};
        return propertyCallbackGraph;
    }
};

struct ConfigConditions
{
    using Conditions = std::array<std::unique_ptr<Conditional>, 42>;

    static auto& get()
    {
        static const Conditions propertyConditions = {
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[4],
                [](const auto& item) { return item == 0; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[0],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[1],
                [](const auto& item) { return item < 3; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[2],
                [](const auto& item) { return item > 1; },
                [](const auto& item) { return item == false; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[3],
                [](const auto& item) { return item > 2; },
                [](const auto& item) { return item == false; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[5],
                [](const auto& item) { return item == 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[6],
                [](const auto& item) { return item == 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[7],
                [](const auto& item) { return item == 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[20],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[20],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[20],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[20],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[20],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[20],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[20],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[20],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[20],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[8],
                [](const auto& item) { return item < 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[9],
                [](const auto& item) { return item > 0; },
                [](const auto& item) { return item == false; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[10],
                [](const auto& item) { return item < 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[11],
                [](const auto& item) { return item > 0; },
                [](const auto& item) { return item == false; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[12],
                [](const auto& item) { return item < 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[13],
                [](const auto& item) { return item > 0; },
                [](const auto& item) { return item == false; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[14],
                [](const auto& item) { return item < 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[15],
                [](const auto& item) { return item > 0; },
                [](const auto& item) { return item == false; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[21],
                [](const auto& item) { return item == 0; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[21],
                [](const auto& item) { return item == 0; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[16],
                [](const auto& item) { return item == 2; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[17],
                [](const auto& item) { return item == 2; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[18],
                [](const auto& item) { return item == 2; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[19],
                [](const auto& item) { return item == 2; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[25],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[22],
                [](const auto& item) { return item < 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[23],
                [](const auto& item) { return item < 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[22],
                [](const auto& item) { return item > 0; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[23],
                [](const auto& item) { return item > 0; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<int64_t>>(
                ConfigPropertyIndicies::get()[26],
                [](const auto& item) { return item >= 3; },
                [](const auto& item) {
                    return item >= static_cast<int64_t>(115000ll);
                },
                true),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[31],
                [](const auto& item) { return item == 1; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<std::string>>(
                ConfigPropertyIndicies::get()[27],
                [](const auto& item) { return item > 0; },
                [](const auto& item) {
                    return item ==
                           "xyz.openbmc_project.State.Chassis.PowerState.On"s;
                },
                false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[28],
                [](const auto& item) { return item < 2; },
                [](const auto& item) { return item == true; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[29],
                [](const auto& item) { return item > 1; },
                [](const auto& item) { return item == false; }, false),
            std::make_unique<CountCondition<bool>>(
                ConfigPropertyIndicies::get()[30],
                [](const auto& item) { return item > 2; },
                [](const auto& item) { return item == false; }, false),
        };
        return propertyConditions;
    }
};

struct ConfigPropertyCallbacks
{
    using Callbacks = std::array<std::unique_ptr<Callback>, 83>;

    static auto& get()
    {
        static const Callbacks propertyCallbacks = {
            std::make_unique<GroupOfCallbacks<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[0]),
            std::make_unique<GroupOfCallbacks<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[1]),
            std::make_unique<GroupOfCallbacks<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[2]),
            makeMethod<SDBusPlus>(
                ConfigInterfaces::get()[0], ConfigPaths::get()[0],
                ConfigInterfaces::get()[1], ConfigProperties::get()[0],
                "obmc-chassis-hard-poweroff@0.target"s, "replace"s),
            makeMethod<SDBusPlus>(
                ConfigInterfaces::get()[0], ConfigPaths::get()[0],
                ConfigInterfaces::get()[1], ConfigProperties::get()[0],
                "obmc-host-shutdown@0.target"s, "replace"s),
            std::make_unique<
                Journal<std::string, phosphor::logging::level::ERR>>(
                "Immediate poweroff of system. There are not enough functional "
                "fans.",
                ConfigPropertyIndicies::get()[0]),
            std::make_unique<
                Journal<std::string, phosphor::logging::level::ERR>>(
                "Request shutdown of system. There are not enough functional "
                "fans.",
                ConfigPropertyIndicies::get()[0]),
            makeElog<sdbusplus::xyz::openbmc_project::State::Shutdown::
                         Inventory::Error::Fan>(),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[3],
                *ConfigConditions::get()[0]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[4],
                *ConfigConditions::get()[1]),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[5],
                *ConfigConditions::get()[2], 25000000us),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[5],
                *ConfigConditions::get()[3], 5000000us),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[6],
                *ConfigConditions::get()[4], 5000000us),
            std::make_unique<Event<bool>>(
                "occ"s,
                "Processor throttled due to an over temperature condition."s,
                ConfigPropertyIndicies::get()[5]),
            std::make_unique<Event<bool>>(
                "occ"s,
                "Processor throttled due to reaching the power cap limit."s,
                ConfigPropertyIndicies::get()[6]),
            std::make_unique<Event<bool>>(
                "occ"s,
                "Memory throttled due to an over temperature condition."s,
                ConfigPropertyIndicies::get()[7]),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[7],
                *ConfigConditions::get()[5], 1000us),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[8],
                *ConfigConditions::get()[6], 1000us),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[9],
                *ConfigConditions::get()[7], 1000us),
            std::make_unique<GroupOfCallbacks<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[10]),
            makeElog<
                sdbusplus::xyz::openbmc_project::Inventory::Error::NotPresent>(
                phosphor::logging::xyz::openbmc_project::Inventory::NotPresent::
                    CALLOUT_INVENTORY_PATH("/xyz/openbmc_project/inventory/"
                                           "system/chassis/motherboard/fan0")),
            makeElog<sdbusplus::xyz::openbmc_project::Inventory::Error::
                         Nonfunctional>(
                phosphor::logging::xyz::openbmc_project::Inventory::
                    Nonfunctional::CALLOUT_INVENTORY_PATH(
                        "/xyz/openbmc_project/inventory/system/chassis/"
                        "motherboard/fan0")),
            makeElog<
                sdbusplus::xyz::openbmc_project::Inventory::Error::NotPresent>(
                phosphor::logging::xyz::openbmc_project::Inventory::NotPresent::
                    CALLOUT_INVENTORY_PATH("/xyz/openbmc_project/inventory/"
                                           "system/chassis/motherboard/fan1")),
            makeElog<sdbusplus::xyz::openbmc_project::Inventory::Error::
                         Nonfunctional>(
                phosphor::logging::xyz::openbmc_project::Inventory::
                    Nonfunctional::CALLOUT_INVENTORY_PATH(
                        "/xyz/openbmc_project/inventory/system/chassis/"
                        "motherboard/fan1")),
            makeElog<
                sdbusplus::xyz::openbmc_project::Inventory::Error::NotPresent>(
                phosphor::logging::xyz::openbmc_project::Inventory::NotPresent::
                    CALLOUT_INVENTORY_PATH("/xyz/openbmc_project/inventory/"
                                           "system/chassis/motherboard/fan2")),
            makeElog<sdbusplus::xyz::openbmc_project::Inventory::Error::
                         Nonfunctional>(
                phosphor::logging::xyz::openbmc_project::Inventory::
                    Nonfunctional::CALLOUT_INVENTORY_PATH(
                        "/xyz/openbmc_project/inventory/system/chassis/"
                        "motherboard/fan2")),
            makeElog<
                sdbusplus::xyz::openbmc_project::Inventory::Error::NotPresent>(
                phosphor::logging::xyz::openbmc_project::Inventory::NotPresent::
                    CALLOUT_INVENTORY_PATH("/xyz/openbmc_project/inventory/"
                                           "system/chassis/motherboard/fan3")),
            makeElog<sdbusplus::xyz::openbmc_project::Inventory::Error::
                         Nonfunctional>(
                phosphor::logging::xyz::openbmc_project::Inventory::
                    Nonfunctional::CALLOUT_INVENTORY_PATH(
                        "/xyz/openbmc_project/inventory/system/chassis/"
                        "motherboard/fan3")),
            std::make_unique<ResolveCallout>("/xyz/openbmc_project/inventory/"
                                             "system/chassis/motherboard/fan0"),
            std::make_unique<ResolveCallout>("/xyz/openbmc_project/inventory/"
                                             "system/chassis/motherboard/fan1"),
            std::make_unique<ResolveCallout>("/xyz/openbmc_project/inventory/"
                                             "system/chassis/motherboard/fan2"),
            std::make_unique<ResolveCallout>("/xyz/openbmc_project/inventory/"
                                             "system/chassis/motherboard/fan3"),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[11],
                *ConfigConditions::get()[8]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[12],
                *ConfigConditions::get()[9]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[13],
                *ConfigConditions::get()[10]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[14],
                *ConfigConditions::get()[11]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[15],
                *ConfigConditions::get()[12]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[16],
                *ConfigConditions::get()[13]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[17],
                *ConfigConditions::get()[14]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[18],
                *ConfigConditions::get()[15]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[19],
                *ConfigConditions::get()[16]),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[20],
                *ConfigConditions::get()[17], 20000000us),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[21],
                *ConfigConditions::get()[18]),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[22],
                *ConfigConditions::get()[19], 20000000us),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[23],
                *ConfigConditions::get()[20]),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[24],
                *ConfigConditions::get()[21], 20000000us),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[25],
                *ConfigConditions::get()[22]),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[26],
                *ConfigConditions::get()[23], 20000000us),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[27],
                *ConfigConditions::get()[24]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[28],
                *ConfigConditions::get()[25]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[29],
                *ConfigConditions::get()[26]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[30],
                *ConfigConditions::get()[27]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[31],
                *ConfigConditions::get()[28]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[32],
                *ConfigConditions::get()[29]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[33],
                *ConfigConditions::get()[30]),
            std::make_unique<GroupOfCallbacks<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[34]),
            makeElog<
                sdbusplus::xyz::openbmc_project::Inventory::Error::NotPresent>(
                phosphor::logging::xyz::openbmc_project::Inventory::NotPresent::
                    CALLOUT_INVENTORY_PATH(
                        "/xyz/openbmc_project/inventory/system/chassis/"
                        "motherboard/powersupply0")),
            makeElog<
                sdbusplus::xyz::openbmc_project::Inventory::Error::NotPresent>(
                phosphor::logging::xyz::openbmc_project::Inventory::NotPresent::
                    CALLOUT_INVENTORY_PATH(
                        "/xyz/openbmc_project/inventory/system/chassis/"
                        "motherboard/powersupply1")),
            std::make_unique<ResolveCallout>(
                "/xyz/openbmc_project/inventory/system/chassis/motherboard/"
                "powersupply0"),
            std::make_unique<ResolveCallout>(
                "/xyz/openbmc_project/inventory/system/chassis/motherboard/"
                "powersupply1"),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[35],
                *ConfigConditions::get()[31]),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[36],
                *ConfigConditions::get()[32], 5000000us),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[37],
                *ConfigConditions::get()[33], 5000000us),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[38],
                *ConfigConditions::get()[34]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[39],
                *ConfigConditions::get()[35]),
            std::make_unique<GroupOfCallbacks<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[40]),
            makeMethod<SDBusPlus>(
                ConfigInterfaces::get()[0], ConfigPaths::get()[0],
                ConfigInterfaces::get()[1], ConfigProperties::get()[0],
                "obmc-chassis-hard-poweroff@0.target"s, "replace"s),
            std::make_unique<ElogWithMetadataCapture<
                sdbusplus::xyz::openbmc_project::Sensor::Threshold::Error::
                    CriticalHigh,
                phosphor::logging::xyz::openbmc_project::Sensor::Threshold::
                    CriticalHigh::SENSOR_DATA,
                int64_t>>(ConfigPropertyIndicies::get()[26]),
            makeElog<sdbusplus::xyz::openbmc_project::State::Shutdown::
                         ThermalEvent::Error::Processor>(),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[41],
                *ConfigConditions::get()[36]),
            std::make_unique<GroupOfCallbacks<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[42]),
            std::make_unique<GroupOfCallbacks<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[43]),
            std::make_unique<GroupOfCallbacks<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[44]),
            makeMethod<SDBusPlus>(
                ConfigInterfaces::get()[0], ConfigPaths::get()[0],
                ConfigInterfaces::get()[1], ConfigProperties::get()[0],
                "obmc-chassis-hard-poweroff@0.target"s, "replace"s),
            makeMethod<SDBusPlus>(
                ConfigInterfaces::get()[0], ConfigPaths::get()[0],
                ConfigInterfaces::get()[1], ConfigProperties::get()[0],
                "obmc-host-shutdown@0.target"s, "replace"s),
            std::make_unique<
                Journal<std::string, phosphor::logging::level::ERR>>(
                "Immediate poweroff of system. There are not enough functional "
                "fans.",
                ConfigPropertyIndicies::get()[27]),
            std::make_unique<
                Journal<std::string, phosphor::logging::level::ERR>>(
                "Request shutdown of system. There are not enough functional "
                "fans.",
                ConfigPropertyIndicies::get()[27]),
            makeElog<sdbusplus::xyz::openbmc_project::State::Shutdown::
                         Inventory::Error::Fan>(),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[45],
                *ConfigConditions::get()[37]),
            std::make_unique<ConditionalCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[46],
                *ConfigConditions::get()[38]),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[47],
                *ConfigConditions::get()[39], 25000000us),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[47],
                *ConfigConditions::get()[40], 5000000us),
            std::make_unique<DeferrableCallback<ConfigPropertyCallbacks>>(
                ConfigPropertyCallbackGroups::get()[48],
                *ConfigConditions::get()[41], 5000000us),
        };
        return propertyCallbacks;
    }
};

struct ConfigPathCallbacks
{
    using Callbacks = std::array<std::unique_ptr<Callback>, 1>;

    static auto& get()
    {
        static const Callbacks pathCallbacks = {
            std::make_unique<SNMPTrap<ErrorTrap>>(),
        };
        return pathCallbacks;
    }
};

struct ConfigPropertyWatches
{
    using PropertyWatches = std::array<std::unique_ptr<Watch>, 31>;

    static auto& get()
    {
        static const PropertyWatches propertyWatches = {
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[1],
                *ConfigPropertyCallbacks::get()[8]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[2],
                *ConfigPropertyCallbacks::get()[8]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[3],
                *ConfigPropertyCallbacks::get()[8]),
            std::make_unique<PropertyWatchOfType<std::string, SDBusPlus>>(
                ConfigPropertyIndicies::get()[0],
                *ConfigPropertyCallbacks::get()[8]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[4]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[5],
                *ConfigPropertyCallbacks::get()[16]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[6],
                *ConfigPropertyCallbacks::get()[17]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[7],
                *ConfigPropertyCallbacks::get()[18]),
            std::make_unique<PropertyWatchOfType<std::string, SDBusPlus>>(
                ConfigPropertyIndicies::get()[20],
                *ConfigPropertyCallbacks::get()[32]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[8],
                *ConfigPropertyCallbacks::get()[33]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[9],
                *ConfigPropertyCallbacks::get()[34]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[10],
                *ConfigPropertyCallbacks::get()[35]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[11],
                *ConfigPropertyCallbacks::get()[36]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[12],
                *ConfigPropertyCallbacks::get()[37]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[13],
                *ConfigPropertyCallbacks::get()[38]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[14],
                *ConfigPropertyCallbacks::get()[39]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[15],
                *ConfigPropertyCallbacks::get()[40]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[16],
                *ConfigPropertyCallbacks::get()[51]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[17],
                *ConfigPropertyCallbacks::get()[52]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[18],
                *ConfigPropertyCallbacks::get()[53]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[19],
                *ConfigPropertyCallbacks::get()[54]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[24],
                *ConfigPropertyCallbacks::get()[60]),
            std::make_unique<PropertyWatchOfType<std::string, SDBusPlus>>(
                ConfigPropertyIndicies::get()[25],
                *ConfigPropertyCallbacks::get()[60]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[22],
                *ConfigPropertyCallbacks::get()[63]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[23],
                *ConfigPropertyCallbacks::get()[64]),
            std::make_unique<PropertyWatchOfType<int64_t, SDBusPlus>>(
                ConfigPropertyIndicies::get()[26],
                *ConfigPropertyCallbacks::get()[69]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[28],
                *ConfigPropertyCallbacks::get()[78]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[29],
                *ConfigPropertyCallbacks::get()[78]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[30],
                *ConfigPropertyCallbacks::get()[78]),
            std::make_unique<PropertyWatchOfType<std::string, SDBusPlus>>(
                ConfigPropertyIndicies::get()[27],
                *ConfigPropertyCallbacks::get()[78]),
            std::make_unique<PropertyWatchOfType<bool, SDBusPlus>>(
                ConfigPropertyIndicies::get()[31]),
        };
        return propertyWatches;
    }
};

struct ConfigPathWatches
{
    using PathWatches = std::array<std::unique_ptr<Watch>, 1>;

    static auto& get()
    {
        static const PathWatches pathWatches = {
            std::make_unique<PathWatch<SDBusPlus>>(
                ConfigIntfAddPaths::get()[0], *ConfigPathCallbacks::get()[0]),
        };
        return pathWatches;
    }
};
} // namespace monitoring
} // namespace dbus
} // namespace phosphor
