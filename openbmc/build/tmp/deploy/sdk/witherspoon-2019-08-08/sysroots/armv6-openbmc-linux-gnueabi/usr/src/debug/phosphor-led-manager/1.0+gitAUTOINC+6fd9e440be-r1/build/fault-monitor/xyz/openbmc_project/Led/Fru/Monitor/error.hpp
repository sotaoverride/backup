#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Led
{
namespace Fru
{
namespace Monitor
{
namespace Error
{

struct InventoryPathError final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "xyz.openbmc_project.Led.Fru.Monitor.Error.InventoryPathError";
    static constexpr auto errDesc = "Invalid Inventory Path.";
    static constexpr auto errWhat =
        "xyz.openbmc_project.Led.Fru.Monitor.Error.InventoryPathError: Invalid "
        "Inventory Path.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Monitor
} // namespace Fru
} // namespace Led
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
