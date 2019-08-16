#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Common
{
namespace Callout
{
namespace Error
{

struct Procedure final : public sdbusplus::exception_t
{
    static constexpr auto errName = "org.open_power.Common.Callout.Error.Procedure";
    static constexpr auto errDesc =
            "Procedure callout";
    static constexpr auto errWhat =
            "org.open_power.Common.Callout.Error.Procedure: Procedure callout";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Callout
} // namespace Common
} // namespace open_power
} // namespace org
} // namespace sdbusplus

