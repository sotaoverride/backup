#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Common
{
namespace File
{
namespace Error
{

struct Open final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.File.Error.Open";
    static constexpr auto errDesc =
            "Failed to open a file";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.File.Error.Open: Failed to open a file";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct Seek final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.File.Error.Seek";
    static constexpr auto errDesc =
            "Failed to seek a file";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.File.Error.Seek: Failed to seek a file";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct Write final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Common.File.Error.Write";
    static constexpr auto errDesc =
            "Failed to write a file";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Common.File.Error.Write: Failed to write a file";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace File
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

