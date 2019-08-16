#pragma once

#include <sdbusplus/exception.hpp>

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

struct Device final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.Callout.Error.Device";
    static constexpr auto errDesc =
            "Generic device callout";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.Callout.Error.Device: Generic device callout";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct GPIO final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.Callout.Error.GPIO";
    static constexpr auto errDesc =
            "Callout GPIO pin";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.Callout.Error.GPIO: Callout GPIO pin";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct IIC final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.Callout.Error.IIC";
    static constexpr auto errDesc =
            "Callout IIC device";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.Callout.Error.IIC: Callout IIC device";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct Inventory final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.Callout.Error.Inventory";
    static constexpr auto errDesc =
            "Inventory item callout";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.Callout.Error.Inventory: Inventory item callout";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct IPMISensor final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.Callout.Error.IPMISensor";
    static constexpr auto errDesc =
            "Callout IPMI sensor";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.Callout.Error.IPMISensor: Callout IPMI sensor";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Callout
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

