#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Inventory
{
namespace Error
{

struct NotPresent final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Inventory.Error.NotPresent";
    static constexpr auto errDesc =
            "The inventory is not present.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Inventory.Error.NotPresent: The inventory is not present.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct Nonfunctional final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Inventory.Error.Nonfunctional";
    static constexpr auto errDesc =
            "The inventory is nonfunctional.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Inventory.Error.Nonfunctional: The inventory is nonfunctional.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

