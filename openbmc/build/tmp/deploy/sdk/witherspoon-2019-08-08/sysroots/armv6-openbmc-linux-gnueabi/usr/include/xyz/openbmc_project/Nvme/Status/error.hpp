#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Nvme
{
namespace Status
{
namespace Error
{

struct CapacityFault final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Nvme.Status.Error.CapacityFault";
    static constexpr auto errDesc =
            "The available spare capacity has fallen below the threshold";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Nvme.Status.Error.CapacityFault: The available spare capacity has fallen below the threshold";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct TemperatureFault final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Nvme.Status.Error.TemperatureFault";
    static constexpr auto errDesc =
            "A temperature is above an over temperature threshold or below an under temperature threshold";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Nvme.Status.Error.TemperatureFault: A temperature is above an over temperature threshold or below an under temperature threshold";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct DegradesFault final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Nvme.Status.Error.DegradesFault";
    static constexpr auto errDesc =
            "The NVM subsystem reliability has been degraded due to significant media related errors or any internal error that degrades NVM subsystem reliability.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Nvme.Status.Error.DegradesFault: The NVM subsystem reliability has been degraded due to significant media related errors or any internal error that degrades NVM subsystem reliability.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct MediaFault final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Nvme.Status.Error.MediaFault";
    static constexpr auto errDesc =
            "The media has been placed in read only mode.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Nvme.Status.Error.MediaFault: The media has been placed in read only mode.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct BackupDeviceFault final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Nvme.Status.Error.BackupDeviceFault";
    static constexpr auto errDesc =
            "The volatile memory backup device has failed.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Nvme.Status.Error.BackupDeviceFault: The volatile memory backup device has failed.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Status
} // namespace Nvme
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

