#include <xyz/openbmc_project/Led/Fru/Monitor/error.hpp>

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
const char* InventoryPathError::name() const noexcept
{
    return errName;
}
const char* InventoryPathError::description() const noexcept
{
    return errDesc;
}
const char* InventoryPathError::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace Monitor
} // namespace Fru
} // namespace Led
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
