#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Control
{
namespace Host
{
namespace Error
{

struct CommandNotSupported final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Control.Host.Error.CommandNotSupported";
    static constexpr auto errDesc =
            "Command is not supported";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Control.Host.Error.CommandNotSupported: Command is not supported";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Host
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

