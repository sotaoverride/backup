#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Witherspoon
{
namespace Fault
{
namespace Error
{

struct PowerSupplyInputFault final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyInputFault";
    static constexpr auto errDesc =
        "The power supply has indicated an input or under voltage condition. "
        "Check the power supply cabling and/or input power source.";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyInputFault: The "
        "power supply has indicated an input or under voltage condition. Check "
        "the power supply cabling and/or input power source.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PowerSupplyShouldBeOn final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyShouldBeOn";
    static constexpr auto errDesc =
        "The power supply indicated that it is not on when it should be.";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyShouldBeOn: The "
        "power supply indicated that it is not on when it should be.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PowerSupplyOutputOvercurrent final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyOutputOvercurrent";
    static constexpr auto errDesc =
        "The power supply detected an output overcurrent fault condition.";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyOutputOvercurrent: "
        "The power supply detected an output overcurrent fault condition.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PowerSupplyOutputOvervoltage final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyOutputOvervoltage";
    static constexpr auto errDesc =
        "The power supply detected an output overvoltage fault condition.";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyOutputOvervoltage: "
        "The power supply detected an output overvoltage fault condition.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PowerSupplyFanFault final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyFanFault";
    static constexpr auto errDesc =
        "The power supply detected bad fan operation.";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyFanFault: The power "
        "supply detected bad fan operation.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PowerSupplyTemperatureFault final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyTemperatureFault";
    static constexpr auto errDesc =
        "The power supply has had an over temperature condition.";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerSupplyTemperatureFault: "
        "The power supply has had an over temperature condition.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct Shutdown final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.Shutdown";
    static constexpr auto errDesc =
        "A power off was issued because a power fault was detected";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.Shutdown: A power off was "
        "issued because a power fault was detected";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PowerOnFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerOnFailure";
    static constexpr auto errDesc = "System power failed to turn on";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerOnFailure: System power "
        "failed to turn on";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PowerSequencerVoltageFault final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerSequencerVoltageFault";
    static constexpr auto errDesc =
        "The power sequencer chip detected a voltage fault";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerSequencerVoltageFault: "
        "The power sequencer chip detected a voltage fault";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PowerSequencerPGOODFault final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerSequencerPGOODFault";
    static constexpr auto errDesc =
        "The power sequencer chip detected a PGOOD fault";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerSequencerPGOODFault: The "
        "power sequencer chip detected a PGOOD fault";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PowerSequencerFault final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.PowerSequencerFault";
    static constexpr auto errDesc = "The power sequencer chip detected a fault";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.PowerSequencerFault: The power "
        "sequencer chip detected a fault";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct GPUPowerFault final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.GPUPowerFault";
    static constexpr auto errDesc = "A GPU suffered a power fault";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.GPUPowerFault: A GPU suffered "
        "a power fault";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct GPUOverTemp final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.GPUOverTemp";
    static constexpr auto errDesc = "A GPU suffered an over-temperature fault";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.GPUOverTemp: A GPU suffered an "
        "over-temperature fault";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct MemoryPowerFault final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Witherspoon.Fault.Error.MemoryPowerFault";
    static constexpr auto errDesc = "A memory device suffered a power fault";
    static constexpr auto errWhat =
        "org.open_power.Witherspoon.Fault.Error.MemoryPowerFault: A memory "
        "device suffered a power fault";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Fault
} // namespace Witherspoon
} // namespace open_power
} // namespace org
} // namespace sdbusplus
