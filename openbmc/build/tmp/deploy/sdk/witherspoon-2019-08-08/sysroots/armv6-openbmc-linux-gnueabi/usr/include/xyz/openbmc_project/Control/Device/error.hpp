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
namespace Device
{
namespace Error
{

struct WriteFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Control.Device.Error.WriteFailure";
    static constexpr auto errDesc =
            "Failed to write to device.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Control.Device.Error.WriteFailure: Failed to write to device.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Device
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

