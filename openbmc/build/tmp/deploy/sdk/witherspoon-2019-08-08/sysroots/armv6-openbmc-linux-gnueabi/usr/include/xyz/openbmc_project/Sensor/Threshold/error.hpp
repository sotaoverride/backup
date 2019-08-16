#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Sensor
{
namespace Threshold
{
namespace Error
{

struct CriticalHigh final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Sensor.Threshold.Error.CriticalHigh";
    static constexpr auto errDesc =
            "Sensor device has exceeded its upper bound.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Sensor.Threshold.Error.CriticalHigh: Sensor device has exceeded its upper bound.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct CriticalLow final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Sensor.Threshold.Error.CriticalLow";
    static constexpr auto errDesc =
            "Sensor device has exceeded its lower bound.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Sensor.Threshold.Error.CriticalLow: Sensor device has exceeded its lower bound.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Threshold
} // namespace Sensor
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

