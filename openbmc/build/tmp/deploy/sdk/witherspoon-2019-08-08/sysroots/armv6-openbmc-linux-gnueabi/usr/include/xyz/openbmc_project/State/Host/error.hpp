#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace State
{
namespace Host
{
namespace Error
{

struct SoftOffTimeout final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.State.Host.Error.SoftOffTimeout";
    static constexpr auto errDesc =
            "Host did not shutdown within configured time.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.State.Host.Error.SoftOffTimeout: Host did not shutdown within configured time.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Host
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

