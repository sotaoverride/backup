#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace State
{
namespace Shutdown
{
namespace Power
{
namespace Error
{

struct Fault final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.State.Shutdown.Power.Error.Fault";
    static constexpr auto errDesc =
            "The system was shut down because a power fault was detected.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.State.Shutdown.Power.Error.Fault: The system was shut down because a power fault was detected.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct Blackout final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.State.Shutdown.Power.Error.Blackout";
    static constexpr auto errDesc =
            "The system suffered a power blackout.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.State.Shutdown.Power.Error.Blackout: The system suffered a power blackout.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Power
} // namespace Shutdown
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

