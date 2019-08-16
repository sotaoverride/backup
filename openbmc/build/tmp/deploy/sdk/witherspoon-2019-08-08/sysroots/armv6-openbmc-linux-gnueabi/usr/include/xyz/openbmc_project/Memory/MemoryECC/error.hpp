#pragma once

#include <sdbusplus/exception.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Memory
{
namespace MemoryECC
{
namespace Error
{

struct isLoggingLimitReached final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Memory.MemoryECC.Error.isLoggingLimitReached";
    static constexpr auto errDesc =
            "ECC collection limit is reached.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Memory.MemoryECC.Error.isLoggingLimitReached: ECC collection limit is reached.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct ceCount final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Memory.MemoryECC.Error.ceCount";
    static constexpr auto errDesc =
            "Correctable ECC/other correctable memory error.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Memory.MemoryECC.Error.ceCount: Correctable ECC/other correctable memory error.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

struct ueCount final : public sdbusplus::exception_t
{
    static constexpr auto errName = "xyz.openbmc_project.Memory.MemoryECC.Error.ueCount";
    static constexpr auto errDesc =
            "Uncorrectable ECC/other uncorrectable memory error.";
    static constexpr auto errWhat =
            "xyz.openbmc_project.Memory.MemoryECC.Error.ueCount: Uncorrectable ECC/other uncorrectable memory error.";

    const char* name() const noexcept override;
    const char* description() const noexcept override;
    const char* what() const noexcept override;
};

} // namespace Error
} // namespace MemoryECC
} // namespace Memory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

