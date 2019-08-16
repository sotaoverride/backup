#include <org/open_power/Host/Boot/error.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Host
{
namespace Boot
{
namespace Error
{
const char* Checkstop::name() const noexcept
{
    return errName;
}
const char* Checkstop::description() const noexcept
{
    return errDesc;
}
const char* Checkstop::what() const noexcept
{
    return errWhat;
}
const char* WatchdogTimedOut::name() const noexcept
{
    return errName;
}
const char* WatchdogTimedOut::description() const noexcept
{
    return errDesc;
}
const char* WatchdogTimedOut::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace Boot
} // namespace Host
} // namespace open_power
} // namespace org
} // namespace sdbusplus
