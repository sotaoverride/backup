#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Proc
{
namespace FSI
{
namespace Error
{

struct MasterDetectionFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Proc.FSI.Error.MasterDetectionFailure";
    static constexpr auto errDesc =
        "Failed while detecting the master processor";
    static constexpr auto errWhat =
        "org.open_power.Proc.FSI.Error.MasterDetectionFailure: Failed while "
        "detecting the master processor";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct SlaveDetectionFailure final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Proc.FSI.Error.SlaveDetectionFailure";
    static constexpr auto errDesc =
        "Failed while detecting the slave processors";
    static constexpr auto errWhat =
        "org.open_power.Proc.FSI.Error.SlaveDetectionFailure: Failed while "
        "detecting the slave processors";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace FSI
} // namespace Proc
} // namespace open_power
} // namespace org
} // namespace sdbusplus
