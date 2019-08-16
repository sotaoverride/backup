#include <xyz/openbmc_project/Led/Mapper/error.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Led
{
namespace Mapper
{
namespace Error
{
const char* MethodError::name() const noexcept
{
    return errName;
}
const char* MethodError::description() const noexcept
{
    return errDesc;
}
const char* MethodError::what() const noexcept
{
    return errWhat;
}
const char* ObjectNotFoundError::name() const noexcept
{
    return errName;
}
const char* ObjectNotFoundError::description() const noexcept
{
    return errDesc;
}
const char* ObjectNotFoundError::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace Mapper
} // namespace Led
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
