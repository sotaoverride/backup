#include <org/open_power/OCC/Metrics/error.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace OCC
{
namespace Metrics
{
namespace Error
{
const char* Event::name() const noexcept
{
    return errName;
}
const char* Event::description() const noexcept
{
    return errDesc;
}
const char* Event::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace Metrics
} // namespace OCC
} // namespace open_power
} // namespace org
} // namespace sdbusplus
