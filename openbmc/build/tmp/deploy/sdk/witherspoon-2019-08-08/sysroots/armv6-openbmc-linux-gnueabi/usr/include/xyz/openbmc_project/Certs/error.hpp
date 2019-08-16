#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Certs
{
namespace Error
{

struct InvalidCertificate final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Certs.Error.InvalidCertificate";
    static constexpr auto errDesc =
            "Invalid certificate file.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Certs.Error.InvalidCertificate: Invalid certificate file.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Certs
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

