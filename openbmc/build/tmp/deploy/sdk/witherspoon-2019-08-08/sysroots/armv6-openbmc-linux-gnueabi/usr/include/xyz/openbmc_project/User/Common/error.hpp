#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace User
{
namespace Common
{
namespace Error
{

struct UserNameExists final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.User.Common.Error.UserNameExists";
    static constexpr auto errDesc =
            "Specified user name already exists.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.User.Common.Error.UserNameExists: Specified user name already exists.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct UserNameDoesNotExist final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.User.Common.Error.UserNameDoesNotExist";
    static constexpr auto errDesc =
            "Specified user name does not exist.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.User.Common.Error.UserNameDoesNotExist: Specified user name does not exist.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct UserNameGroupFail final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.User.Common.Error.UserNameGroupFail";
    static constexpr auto errDesc =
            "Specified Group related restriction failure for user name.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.User.Common.Error.UserNameGroupFail: Specified Group related restriction failure for user name.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct UserNamePrivFail final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.User.Common.Error.UserNamePrivFail";
    static constexpr auto errDesc =
            "Specified privilege related restriction failure for user name.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.User.Common.Error.UserNamePrivFail: Specified privilege related restriction failure for user name.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct NoResource final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.User.Common.Error.NoResource";
    static constexpr auto errDesc =
            "No resource available.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.User.Common.Error.NoResource: No resource available.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct PrivilegeMappingExists final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.User.Common.Error.PrivilegeMappingExists";
    static constexpr auto errDesc =
            "Specified privilege mapping already exists.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.User.Common.Error.PrivilegeMappingExists: Specified privilege mapping already exists.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace Common
} // namespace User
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

