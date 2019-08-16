#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Host
{
namespace Boot
{
namespace Error
{

struct Checkstop final : public sdbusplus::exception_t
{
    static constexpr auto errName = "org.open_power.Host.Boot.Error.Checkstop";
    static constexpr auto errDesc =
            "Host checkstop condition detected";
    static constexpr auto errWhat =
            "org.open_power.Host.Boot.Error.Checkstop: Host checkstop condition detected";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct WatchdogTimedOut final : public sdbusplus::exception_t
{
    static constexpr auto errName = "org.open_power.Host.Boot.Error.WatchdogTimedOut";
    static constexpr auto errDesc =
            "Host watchdog timed out";
    static constexpr auto errWhat =
            "org.open_power.Host.Boot.Error.WatchdogTimedOut: Host watchdog timed out";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Boot
} // namespace Host
} // namespace open_power
} // namespace org
} // namespace sdbusplus

