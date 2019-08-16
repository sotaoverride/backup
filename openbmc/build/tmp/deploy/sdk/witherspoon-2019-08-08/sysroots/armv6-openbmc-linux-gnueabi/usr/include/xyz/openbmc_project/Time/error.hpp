#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Time
{
namespace Error
{

struct NotAllowed final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Time.Error.NotAllowed";
    static constexpr auto errDesc =
            "The operation is not allowed";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Time.Error.NotAllowed: The operation is not allowed";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct Failed final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Time.Error.Failed";
    static constexpr auto errDesc =
            "The operation failed";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Time.Error.Failed: The operation failed";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Time
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

