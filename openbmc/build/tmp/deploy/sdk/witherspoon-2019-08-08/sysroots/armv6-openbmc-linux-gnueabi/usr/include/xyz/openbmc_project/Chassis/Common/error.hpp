#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Chassis
{
namespace Common
{
namespace Error
{

struct UnsupportedCommand final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Chassis.Common.Error.UnsupportedCommand";
    static constexpr auto errDesc =
            "An unsupported command was attempted.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Chassis.Common.Error.UnsupportedCommand: An unsupported command was attempted.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct IOError final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Chassis.Common.Error.IOError";
    static constexpr auto errDesc =
            "An IO error occurred.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Chassis.Common.Error.IOError: An IO error occurred.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Common
} // namespace Chassis
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

