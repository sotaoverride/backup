#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Dump
{
namespace Create
{
namespace Error
{

struct Disabled final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Dump.Create.Error.Disabled";
    static constexpr auto errDesc =
            "Dump is disabled on this system.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Dump.Create.Error.Disabled: Dump is disabled on this system.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct QuotaExceeded final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Dump.Create.Error.QuotaExceeded";
    static constexpr auto errDesc =
            "Dump not captured due to a cap.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Dump.Create.Error.QuotaExceeded: Dump not captured due to a cap.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Create
} // namespace Dump
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

