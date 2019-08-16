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
namespace Shutdown
{
namespace Inventory
{
namespace Error
{

struct Fan final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.State.Shutdown.Inventory.Error.Fan";
    static constexpr auto errDesc =
            "The system shut down due to not enough functional fans.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.State.Shutdown.Inventory.Error.Fan: The system shut down due to not enough functional fans.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Inventory
} // namespace Shutdown
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

