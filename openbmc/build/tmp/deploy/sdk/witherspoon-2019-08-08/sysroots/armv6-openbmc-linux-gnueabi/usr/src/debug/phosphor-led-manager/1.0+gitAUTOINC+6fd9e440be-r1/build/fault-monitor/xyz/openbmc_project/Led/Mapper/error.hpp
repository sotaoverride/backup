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
namespace Mapper
{
namespace Error
{

struct MethodError final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "xyz.openbmc_project.Led.Mapper.Error.MethodError";
    static constexpr auto errDesc = "Failed to invoke ObjectMapper method";
    static constexpr auto errWhat =
        "xyz.openbmc_project.Led.Mapper.Error.MethodError: Failed to invoke "
        "ObjectMapper method";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct ObjectNotFoundError final : public sdbusplus::exception_t
{
    static constexpr auto errName =
        "xyz.openbmc_project.Led.Mapper.Error.ObjectNotFoundError";
    static constexpr auto errDesc = "Failed to get response from the method.";
    static constexpr auto errWhat =
        "xyz.openbmc_project.Led.Mapper.Error.ObjectNotFoundError: Failed to "
        "get response from the method.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Mapper
} // namespace Led
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
