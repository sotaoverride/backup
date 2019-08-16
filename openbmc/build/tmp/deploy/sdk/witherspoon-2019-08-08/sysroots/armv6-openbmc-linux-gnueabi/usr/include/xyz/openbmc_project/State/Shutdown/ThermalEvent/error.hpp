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
namespace ThermalEvent
{
namespace Error
{

struct Processor final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.State.Shutdown.ThermalEvent.Error.Processor";
    static constexpr auto errDesc =
            "The system shut down due to processor overtemp.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.State.Shutdown.ThermalEvent.Error.Processor: The system shut down due to processor overtemp.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct GPU final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.State.Shutdown.ThermalEvent.Error.GPU";
    static constexpr auto errDesc =
            "The system shut down due to a GPU overtemp.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.State.Shutdown.ThermalEvent.Error.GPU: The system shut down due to a GPU overtemp.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct Ambient final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.State.Shutdown.ThermalEvent.Error.Ambient";
    static constexpr auto errDesc =
            "System shutdown due to a high ambient temperature.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.State.Shutdown.ThermalEvent.Error.Ambient: System shutdown due to a high ambient temperature.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace ThermalEvent
} // namespace Shutdown
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

