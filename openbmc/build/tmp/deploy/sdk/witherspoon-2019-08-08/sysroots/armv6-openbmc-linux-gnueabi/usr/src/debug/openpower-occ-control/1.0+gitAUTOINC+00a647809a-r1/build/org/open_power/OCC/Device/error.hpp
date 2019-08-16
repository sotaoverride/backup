#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace OCC
{
namespace Device
{
namespace Error
{

struct OpenFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.OCC.Device.Error.OpenFailure";
    static constexpr auto errDesc = "Opening OCC device failed.";
    static constexpr auto errWhat = "org.open_power.OCC.Device.Error."
                                    "OpenFailure: Opening OCC device failed.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct ReadFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.OCC.Device.Error.ReadFailure";
    static constexpr auto errDesc = "Reading from OCC failed.";
    static constexpr auto errWhat =
        "org.open_power.OCC.Device.Error.ReadFailure: Reading from OCC failed.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct WriteFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.OCC.Device.Error.WriteFailure";
    static constexpr auto errDesc = "Writing to OCC failed.";
    static constexpr auto errWhat =
        "org.open_power.OCC.Device.Error.WriteFailure: Writing to OCC failed.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct ConfigFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.OCC.Device.Error.ConfigFailure";
    static constexpr auto errDesc = "Configuring device failed.";
    static constexpr auto errWhat = "org.open_power.OCC.Device.Error."
                                    "ConfigFailure: Configuring device failed.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Device
} // namespace OCC
} // namespace open_power
} // namespace org
} // namespace sdbusplus
