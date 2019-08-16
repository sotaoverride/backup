#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Software
{
namespace Version
{
namespace Error
{

struct Incompatible final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Software.Version.Error.Incompatible";
    static constexpr auto errDesc =
            "A system component has a software version that is incompatible as determined by the implementation and needs to be updated. Some usage examples for this error include creating logging events and providing information on implementation reactions such as when the system is prevented from powering on if a minimum version level is not met.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Software.Version.Error.Incompatible: A system component has a software version that is incompatible as determined by the implementation and needs to be updated. Some usage examples for this error include creating logging events and providing information on implementation reactions such as when the system is prevented from powering on if a minimum version level is not met.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Version
} // namespace Software
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

