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
namespace Device
{
namespace Error
{

struct ReadFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.Device.Error.ReadFailure";
    static constexpr auto errDesc =
            "Failed to read from the device. This can be used by any application that gets a failure reading from a device. It is up to the implementation on how to react to this error based on the use-case. Refer to the interface specification that references this for additional information.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.Device.Error.ReadFailure: Failed to read from the device. This can be used by any application that gets a failure reading from a device. It is up to the implementation on how to react to this error based on the use-case. Refer to the interface specification that references this for additional information.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct WriteFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.Device.Error.WriteFailure";
    static constexpr auto errDesc =
            "Failed to write to device. This can be used by any application that gets a failure writing to a device. It is up to the implementation on how to react to this error based on the use-case. Refer to the interface specification that references this for additional information.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.Device.Error.WriteFailure: Failed to write to device. This can be used by any application that gets a failure writing to a device. It is up to the implementation on how to react to this error based on the use-case. Refer to the interface specification that references this for additional information.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Device
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

