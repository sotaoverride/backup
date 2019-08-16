#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Host
{
namespace Access
{
namespace Error
{

struct WriteCFAM final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "org.open_power.Host.Access.Error.WriteCFAM";
    static constexpr auto errDesc = "Failed to do a CFAM register write";
    static constexpr auto errWhat =
        "org.open_power.Host.Access.Error.WriteCFAM: Failed to do a CFAM "
        "register write";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct ReadCFAM final : public sdbusplus::exception_t
{
    static constexpr auto errName = "org.open_power.Host.Access.Error.ReadCFAM";
    static constexpr auto errDesc = "Failed to do a CFAM register read";
    static constexpr auto errWhat = "org.open_power.Host.Access.Error.ReadCFAM:"
                                    " Failed to do a CFAM register read";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Access
} // namespace Host
} // namespace open_power
} // namespace org
} // namespace sdbusplus
