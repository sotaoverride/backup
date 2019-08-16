// This file was autogenerated.  Do not edit!
// See elog-gen.py for more details
#pragma once

#include <phosphor-logging/elog.hpp>
#include <phosphor-logging/log.hpp>
#include <sdbusplus/exception.hpp>
#include <string>
#include <tuple>
#include <type_traits>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace Error
{
struct GPIO;
} // namespace Error
} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Common
{
namespace Callout
{
namespace Error
{
struct Procedure;
} // namespace Error
} // namespace Callout
} // namespace Common
} // namespace open_power
} // namespace org
} // namespace sdbusplus

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace Error
{
struct Inventory;
} // namespace Error
} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace Error
{
struct IIC;
} // namespace Error
} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace OCC
{
namespace Metrics
{
namespace Error
{
struct Event;
} // namespace Error
} // namespace Metrics
} // namespace OCC
} // namespace open_power
} // namespace org
} // namespace sdbusplus

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace Error
{
struct Device;
} // namespace Error
} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Host
{
namespace Error
{
struct MaintenanceProcedure;
} // namespace Error
} // namespace Host
} // namespace open_power
} // namespace org
} // namespace sdbusplus

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Host
{
namespace Error
{
struct Event;
} // namespace Error
} // namespace Host
} // namespace open_power
} // namespace org
} // namespace sdbusplus

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace Error
{
struct IPMISensor;
} // namespace Error
} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

namespace phosphor
{

namespace logging
{

namespace org
{
namespace open_power
{
namespace Common
{
namespace Callout
{
namespace _Procedure
{

struct PROCEDURE
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "PROCEDURE";
    using type = std::tuple<std::decay_t<decltype("PROCEDURE=%u")>, uint32_t>;
    explicit constexpr PROCEDURE(uint32_t a) :
        _entry(entry("PROCEDURE=%u", a)){};
    type _entry;
};

} // namespace _Procedure

struct Procedure
{
    static constexpr auto L = level::ERR;
    using PROCEDURE = _Procedure::PROCEDURE;
    using metadata_types = std::tuple<PROCEDURE>;
};

} // namespace Callout
} // namespace Common
} // namespace open_power
} // namespace org

namespace details
{

template <>
struct map_exception_type<
    sdbusplus::org::open_power::Common::Callout::Error::Procedure>
{
    using type = org::open_power::Common::Callout::Procedure;
};

} // namespace details

namespace org
{
namespace open_power
{
namespace OCC
{
namespace Metrics
{
namespace _Event
{

struct ESEL
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "ESEL";
    using type = std::tuple<std::decay_t<decltype("ESEL=%s")>, const char*>;
    explicit constexpr ESEL(const char* a) : _entry(entry("ESEL=%s", a)){};
    type _entry;
};

} // namespace _Event

struct Event
{
    static constexpr auto L = level::INFO;
    using ESEL = _Event::ESEL;
    using metadata_types = std::tuple<ESEL>;
};

} // namespace Metrics
} // namespace OCC
} // namespace open_power
} // namespace org

namespace details
{

template <>
struct map_exception_type<
    sdbusplus::org::open_power::OCC::Metrics::Error::Event>
{
    using type = org::open_power::OCC::Metrics::Event;
};

} // namespace details

namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace _Device
{

struct CALLOUT_ERRNO
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "CALLOUT_ERRNO";
    using type =
        std::tuple<std::decay_t<decltype("CALLOUT_ERRNO=%d")>, int32_t>;
    explicit constexpr CALLOUT_ERRNO(int32_t a) :
        _entry(entry("CALLOUT_ERRNO=%d", a)){};
    type _entry;
};
struct CALLOUT_DEVICE_PATH
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "CALLOUT_DEVICE_PATH";
    using type = std::tuple<std::decay_t<decltype("CALLOUT_DEVICE_PATH=%s")>,
                            const char*>;
    explicit constexpr CALLOUT_DEVICE_PATH(const char* a) :
        _entry(entry("CALLOUT_DEVICE_PATH=%s", a)){};
    type _entry;
};

} // namespace _Device

struct Device
{
    static constexpr auto L = level::ERR;
    using CALLOUT_ERRNO = _Device::CALLOUT_ERRNO;
    using CALLOUT_DEVICE_PATH = _Device::CALLOUT_DEVICE_PATH;
    using metadata_types = std::tuple<CALLOUT_ERRNO, CALLOUT_DEVICE_PATH>;
};

} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz

namespace details
{

template <>
struct map_exception_type<
    sdbusplus::xyz::openbmc_project::Common::Callout::Error::Device>
{
    using type = xyz::openbmc_project::Common::Callout::Device;
};

} // namespace details

namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace _GPIO
{

struct CALLOUT_GPIO_NUM
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "CALLOUT_GPIO_NUM";
    using type =
        std::tuple<std::decay_t<decltype("CALLOUT_GPIO_NUM=%u")>, uint32_t>;
    explicit constexpr CALLOUT_GPIO_NUM(uint32_t a) :
        _entry(entry("CALLOUT_GPIO_NUM=%u", a)){};
    type _entry;
};

} // namespace _GPIO

struct GPIO
{
    static constexpr auto L = level::ERR;
    using CALLOUT_GPIO_NUM = _GPIO::CALLOUT_GPIO_NUM;
    using CALLOUT_ERRNO =
        xyz::openbmc_project::Common::Callout::Device::CALLOUT_ERRNO;
    using CALLOUT_DEVICE_PATH =
        xyz::openbmc_project::Common::Callout::Device::CALLOUT_DEVICE_PATH;
    using metadata_types =
        std::tuple<CALLOUT_GPIO_NUM, CALLOUT_ERRNO, CALLOUT_DEVICE_PATH>;
};

} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz

namespace details
{

template <>
struct map_exception_type<
    sdbusplus::xyz::openbmc_project::Common::Callout::Error::GPIO>
{
    using type = xyz::openbmc_project::Common::Callout::GPIO;
};

} // namespace details

namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace _IIC
{

struct CALLOUT_IIC_BUS
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "CALLOUT_IIC_BUS";
    using type =
        std::tuple<std::decay_t<decltype("CALLOUT_IIC_BUS=%s")>, const char*>;
    explicit constexpr CALLOUT_IIC_BUS(const char* a) :
        _entry(entry("CALLOUT_IIC_BUS=%s", a)){};
    type _entry;
};
struct CALLOUT_IIC_ADDR
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "CALLOUT_IIC_ADDR";
    using type =
        std::tuple<std::decay_t<decltype("CALLOUT_IIC_ADDR=0x%hx")>, uint16_t>;
    explicit constexpr CALLOUT_IIC_ADDR(uint16_t a) :
        _entry(entry("CALLOUT_IIC_ADDR=0x%hx", a)){};
    type _entry;
};

} // namespace _IIC

struct IIC
{
    static constexpr auto L = level::ERR;
    using CALLOUT_IIC_BUS = _IIC::CALLOUT_IIC_BUS;
    using CALLOUT_IIC_ADDR = _IIC::CALLOUT_IIC_ADDR;
    using CALLOUT_ERRNO =
        xyz::openbmc_project::Common::Callout::Device::CALLOUT_ERRNO;
    using CALLOUT_DEVICE_PATH =
        xyz::openbmc_project::Common::Callout::Device::CALLOUT_DEVICE_PATH;
    using metadata_types = std::tuple<CALLOUT_IIC_BUS, CALLOUT_IIC_ADDR,
                                      CALLOUT_ERRNO, CALLOUT_DEVICE_PATH>;
};

} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz

namespace details
{

template <>
struct map_exception_type<
    sdbusplus::xyz::openbmc_project::Common::Callout::Error::IIC>
{
    using type = xyz::openbmc_project::Common::Callout::IIC;
};

} // namespace details

namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace _Inventory
{

struct CALLOUT_INVENTORY_PATH
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "CALLOUT_INVENTORY_PATH";
    using type = std::tuple<std::decay_t<decltype("CALLOUT_INVENTORY_PATH=%s")>,
                            const char*>;
    explicit constexpr CALLOUT_INVENTORY_PATH(const char* a) :
        _entry(entry("CALLOUT_INVENTORY_PATH=%s", a)){};
    type _entry;
};

} // namespace _Inventory

struct Inventory
{
    static constexpr auto L = level::ERR;
    using CALLOUT_INVENTORY_PATH = _Inventory::CALLOUT_INVENTORY_PATH;
    using metadata_types = std::tuple<CALLOUT_INVENTORY_PATH>;
};

} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz

namespace details
{

template <>
struct map_exception_type<
    sdbusplus::xyz::openbmc_project::Common::Callout::Error::Inventory>
{
    using type = xyz::openbmc_project::Common::Callout::Inventory;
};

} // namespace details

namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace Callout
{
namespace _IPMISensor
{

struct CALLOUT_IPMI_SENSOR_NUM
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "CALLOUT_IPMI_SENSOR_NUM";
    using type =
        std::tuple<std::decay_t<decltype("CALLOUT_IPMI_SENSOR_NUM=%u")>,
                   uint32_t>;
    explicit constexpr CALLOUT_IPMI_SENSOR_NUM(uint32_t a) :
        _entry(entry("CALLOUT_IPMI_SENSOR_NUM=%u", a)){};
    type _entry;
};

} // namespace _IPMISensor

struct IPMISensor
{
    static constexpr auto L = level::ERR;
    using CALLOUT_IPMI_SENSOR_NUM = _IPMISensor::CALLOUT_IPMI_SENSOR_NUM;
    using metadata_types = std::tuple<CALLOUT_IPMI_SENSOR_NUM>;
};

} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz

namespace details
{

template <>
struct map_exception_type<
    sdbusplus::xyz::openbmc_project::Common::Callout::Error::IPMISensor>
{
    using type = xyz::openbmc_project::Common::Callout::IPMISensor;
};

} // namespace details

namespace org
{
namespace open_power
{
namespace Host
{
namespace _Event
{

struct ESEL
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "ESEL";
    using type = std::tuple<std::decay_t<decltype("ESEL=%s")>, const char*>;
    explicit constexpr ESEL(const char* a) : _entry(entry("ESEL=%s", a)){};
    type _entry;
};

} // namespace _Event

struct Event
{
    static constexpr auto L = level::ERR;
    using ESEL = _Event::ESEL;
    using CALLOUT_INVENTORY_PATH = xyz::openbmc_project::Common::Callout::
        Inventory::CALLOUT_INVENTORY_PATH;
    using metadata_types = std::tuple<ESEL, CALLOUT_INVENTORY_PATH>;
};

} // namespace Host
} // namespace open_power
} // namespace org

namespace details
{

template <>
struct map_exception_type<sdbusplus::org::open_power::Host::Error::Event>
{
    using type = org::open_power::Host::Event;
};

} // namespace details

namespace org
{
namespace open_power
{
namespace Host
{
namespace _MaintenanceProcedure
{

struct ESEL
{
    /*
     * We can't use -fsanitize=undefined if we declare a
     * 'static constexpr auto str' member, so don't. Instead, open-code the
     * mako template lookups.
     */
    static constexpr auto str_short = "ESEL";
    using type = std::tuple<std::decay_t<decltype("ESEL=%s")>, const char*>;
    explicit constexpr ESEL(const char* a) : _entry(entry("ESEL=%s", a)){};
    type _entry;
};

} // namespace _MaintenanceProcedure

struct MaintenanceProcedure
{
    static constexpr auto L = level::ERR;
    using ESEL = _MaintenanceProcedure::ESEL;
    using PROCEDURE = org::open_power::Common::Callout::Procedure::PROCEDURE;
    using metadata_types = std::tuple<ESEL, PROCEDURE>;
};

} // namespace Host
} // namespace open_power
} // namespace org

namespace details
{

template <>
struct map_exception_type<
    sdbusplus::org::open_power::Host::Error::MaintenanceProcedure>
{
    using type = org::open_power::Host::MaintenanceProcedure;
};

} // namespace details

} // namespace logging

} // namespace phosphor