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
namespace Device
{
namespace Error
{

struct ReadFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Sensor.Device.Error.ReadFailure";
    static constexpr auto errDesc =
            "Failed to read from device.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Sensor.Device.Error.ReadFailure: Failed to read from device.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Device
} // namespace Sensor
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

