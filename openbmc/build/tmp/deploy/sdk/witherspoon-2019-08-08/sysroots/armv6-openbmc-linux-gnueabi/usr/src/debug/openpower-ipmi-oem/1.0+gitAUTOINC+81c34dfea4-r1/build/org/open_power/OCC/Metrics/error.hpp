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
namespace Metrics
{
namespace Error
{

struct Event final : public sdbusplus::exception_t
{
    static constexpr auto errName = "org.open_power.OCC.Metrics.Error.Event";
    static constexpr auto errDesc = "OCC Metrics Data";
    static constexpr auto errWhat =
        "org.open_power.OCC.Metrics.Error.Event: OCC Metrics Data";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Metrics
} // namespace OCC
} // namespace open_power
} // namespace org
} // namespace sdbusplus
