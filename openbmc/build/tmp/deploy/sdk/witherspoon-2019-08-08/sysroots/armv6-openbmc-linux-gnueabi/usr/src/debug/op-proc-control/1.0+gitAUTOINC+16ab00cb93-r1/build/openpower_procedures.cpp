#include "cfam_access.hpp"
#include "p9_cfam.hpp"
#include "registration.hpp"
#include "targeting.hpp"

#include <fstream>
#include <iostream>
#include <phosphor-logging/elog-errors.hpp>
#include <phosphor-logging/elog.hpp>
#include <sstream>
#include <xyz/openbmc_project/Common/error.hpp>

/* File /var/lib/obmc/cfam_overrides requires whitespace-separated parameters
Pos Address Data Mask with one register write per line. For example:
0 0x283F 0x12345678 0xF0F0F0F0
0 0x283F 0x87654321 0x0F0F0F0F
Blank lines and comment lines beginning with # will be ignored. */

namespace openpower
{
namespace p9
{

using namespace openpower::cfam::access;
using namespace openpower::targeting;
using namespace openpower::util;

void CFAMOverride()
{
    int pos = 0;
    cfam_address_t address = 0;
    cfam_data_t data = 0;
    cfam_mask_t mask = 0;

    Targeting targets;

    std::string line;

    std::ifstream overrides("/var/lib/obmc/cfam_overrides");

    if (overrides.is_open())
    {
        while (std::getline(overrides, line))
        {
            if (!line.empty())
            {
                line.erase(0, line.find_first_not_of(" \t\r\n"));
                if (!line.empty() && line.at(0) != '#')
                {
                    mask = 0xFFFFFFFF;
                    if (sscanf(line.c_str(), "%x %hx %x %x", &pos, &address,
                               &data, &mask) >= 3)
                    {
                        const auto& target = targets.getTarget(pos);
                        writeRegWithMask(target, address, data, mask);
                    }
                    else
                    {
                        namespace error =
                            sdbusplus::xyz::openbmc_project::Common::Error;
                        namespace metadata =
                            phosphor::logging::xyz::openbmc_project::Common;
                        phosphor::logging::elog<error::InvalidArgument>(
                            metadata::InvalidArgument::ARGUMENT_NAME("line"),
                            metadata::InvalidArgument::ARGUMENT_VALUE(
                                line.c_str()));
                    }
                }
            }
        }
        overrides.close();
    }

    return;
}

REGISTER_PROCEDURE("CFAMOverride", CFAMOverride);

} // namespace p9
} // namespace openpower
/**
 * Copyright (C) 2018 IBM Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "cfam_access.hpp"
#include "p9_cfam.hpp"
#include "registration.hpp"
#include "targeting.hpp"

#include <phosphor-logging/log.hpp>
#include <xyz/openbmc_project/Common/File/error.hpp>

namespace openpower
{
namespace p9
{

using namespace phosphor::logging;
using namespace openpower::cfam::access;
using namespace openpower::cfam::p9;
using namespace openpower::targeting;
namespace file_error = sdbusplus::xyz::openbmc_project::Common::File::Error;

/**
 * @brief Disables PCIE drivers and receiver in the PCIE root ctrl 1 register
 * @return void
 */
void cleanupPcie()
{
    try
    {
        Targeting targets;

        log<level::INFO>("Running P9 procedure cleanupPcie");

        // Disable the PCIE drivers and receiver on all CPUs
        for (const auto& target : targets)
        {
            try
            {
                writeReg(target, P9_ROOT_CTRL1_CLEAR, 0x00001C00);
            }
            catch (std::exception& e)
            {
                // Don't need an error log coming from the power off
                // path, just keep trying on the other processors.
                continue;
            }
        }
    }
    catch (file_error::Open& e)
    {
        // For this procedure we can ignore the ::Open error
    }
}

REGISTER_PROCEDURE("cleanupPcie", cleanupPcie);

} // namespace p9
} // namespace openpower
/**
 * Copyright (C) 2017 IBM Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "cfam_access.hpp"
#include "p9_cfam.hpp"
#include "registration.hpp"
#include "targeting.hpp"

#include <phosphor-logging/log.hpp>

namespace openpower
{
namespace p9
{
namespace debug
{
// SBE messaging register - cfam 2809
union sbeMsgReg_t
{
    uint32_t data32;

    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32_t reserved2 : 6;
        uint32_t minorStep : 6;
        uint32_t majorStep : 8;
        uint32_t currState : 4;
        uint32_t prevState : 4;
        uint32_t reserved1 : 2;
        uint32_t asyncFFDC : 1;
        uint32_t sbeBooted : 1;
#else
        uint32_t sbeBooted : 1;
        uint32_t asyncFFDC : 1;
        uint32_t reserved1 : 2;
        uint32_t prevState : 4;
        uint32_t currState : 4;
        uint32_t majorStep : 8;
        uint32_t minorStep : 6;
        uint32_t reserved2 : 6;
#endif
    } PACKED;
};

// HB mailbox scratch register 5 - cfam 283C
union MboxScratch5_HB_t
{
    uint32_t data32;
    struct
    {
#if __BYTE_ORDER == __LITTLE_ENDIAN
        uint32_t minorStep : 8;    // 24:31
        uint32_t majorStep : 8;    // 16:23
        uint32_t internalStep : 4; // 12:15
        uint32_t reserved : 2;     // 10:11
        uint32_t stepFinish : 1;   // 9
        uint32_t stepStart : 1;    // 8
        uint32_t magic : 8;        // 0:7
#else
        uint32_t magic : 8;        // 0:7
        uint32_t stepStart : 1;    // 8
        uint32_t stepFinish : 1;   // 9
        uint32_t reserved : 2;     // 10:11
        uint32_t internalStep : 4; // 12:15
        uint32_t majorStep : 8;    // 16:23
        uint32_t minorStep : 8;    // 24:31
#endif
    } PACKED;
};

static constexpr uint8_t HB_MBX5_VALID_FLAG = 0xAA;

/**
 * @brief Capture SBE and HB istep information on watchdog timeout
 * @return void
 */
void collectSBEHBData()
{
    using namespace openpower::targeting;
    using namespace openpower::cfam::p9;
    using namespace openpower::cfam::access;
    using namespace phosphor::logging;

    Targeting targets;

    for (const auto& proc : targets)
    {
        // Read and parse SBE messaging register
        try
        {
            auto readData = readReg(proc, P9_SBE_MSG_REGISTER);
            auto msg = reinterpret_cast<const sbeMsgReg_t*>(&readData);
            log<level::INFO>("SBE status register",
                             entry("PROC=%d", proc->getPos()),
                             entry("SBE_MAJOR_ISTEP=%d", msg->PACKED.majorStep),
                             entry("SBE_MINOR_ISTEP=%d", msg->PACKED.minorStep),
                             entry("REG_VAL=0x%08X", msg->data32));
        }
        catch (const std::exception& e)
        {
            log<level::ERR>(e.what());
            // We want to continue - capturing as much info as possible
        }
    }

    const auto& master = *(targets.begin());
    // Read and parse HB messaging register
    try
    {
        auto readData = readReg(master, P9_HB_MBX5_REG);
        auto msg = reinterpret_cast<const MboxScratch5_HB_t*>(&readData);
        if (HB_MBX5_VALID_FLAG == msg->PACKED.magic)
        {
            log<level::INFO>("HB MBOX 5 register",
                             entry("HB_MAJOR_ISTEP=%d", msg->PACKED.majorStep),
                             entry("HB_MINOR_ISTEP=%d", msg->PACKED.minorStep),
                             entry("REG_VAL=0x%08X", msg->data32));
        }
    }
    catch (const std::exception& e)
    {
        log<level::ERR>(e.what());
        // We want to continue - capturing as much info as possible
    }
}

REGISTER_PROCEDURE("collectSBEHBData", collectSBEHBData);

} // namespace debug
} // namespace p9
} // namespace openpower
/**
 * Copyright (C) 2017 IBM Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "cfam_access.hpp"
#include "p9_cfam.hpp"
#include "registration.hpp"
#include "targeting.hpp"

namespace openpower
{
namespace p9
{

using namespace openpower::cfam::access;
using namespace openpower::cfam::p9;
using namespace openpower::targeting;

/**
 * @Brief Sets the P9 FSI clock to synchronous mode.
 */
void setSynchronousFSIClock()
{
    Targeting targets;
    const auto& master = *(targets.begin());

    // Set bit 31 to 0
    writeRegWithMask(master, P9_LL_MODE_REG, 0x00000000, 0x00000001);
}

REGISTER_PROCEDURE("setSyncFSIClock", setSynchronousFSIClock);

} // namespace p9
} // namespace openpower
/**
 * Copyright (C) 2017 IBM Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "cfam_access.hpp"
#include "ext_interface.hpp"
#include "p9_cfam.hpp"
#include "registration.hpp"
#include "targeting.hpp"

#include <phosphor-logging/log.hpp>

namespace openpower
{
namespace p9
{

using namespace phosphor::logging;
using namespace openpower::cfam::access;
using namespace openpower::cfam::p9;
using namespace openpower::targeting;

/**
 * @brief Starts the self boot engine on P9 position 0 to kick off a boot.
 * @return void
 */
void startHost()
{
    Targeting targets;
    const auto& master = *(targets.begin());

    log<level::INFO>("Running P9 procedure startHost",
                     entry("NUM_PROCS=%d", targets.size()));

    // Ensure asynchronous clock mode is set
    writeReg(master, P9_LL_MODE_REG, 0x00000001);

    // Clock mux select override
    for (const auto& t : targets)
    {
        writeRegWithMask(t, P9_ROOT_CTRL8, 0x0000000C, 0x0000000C);
    }

    // Enable P9 checkstop to be reported to the BMC

    // Setup FSI2PIB to report checkstop
    writeReg(master, P9_FSI_A_SI1S, 0x20000000);

    // Enable Xstop/ATTN interrupt
    writeReg(master, P9_FSI2PIB_TRUE_MASK, 0x60000000);

    // Arm it
    writeReg(master, P9_FSI2PIB_INTERRUPT, 0xFFFFFFFF);

    // Kick off the SBE to start the boot

    // Choose seeprom side to boot from
    cfam_data_t sbeSide = 0;
    if (getBootCount() > 0)
    {
        sbeSide = 0;
        log<level::INFO>("Setting SBE seeprom side to 0",
                         entry("SBE_SIDE_SELECT=%d", 0));
    }
    else
    {
        sbeSide = 0x00004000;
        log<level::INFO>("Setting SBE seeprom side to 1",
                         entry("SBE_SIDE_SELECT=%d", 1));
    }
    // Bit 17 of the ctrl status reg indicates sbe seeprom boot side
    // 0 -> Side 0, 1 -> Side 1
    writeRegWithMask(master, P9_SBE_CTRL_STATUS, sbeSide, 0x00004000);

    // Start the SBE
    writeRegWithMask(master, P9_CBS_CS, 0x80000000, 0x80000000);
}

REGISTER_PROCEDURE("startHost", startHost);

} // namespace p9
} // namespace openpower
/**
 * Copyright (C) 2017 IBM Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "cfam_access.hpp"
#include "p9_cfam.hpp"
#include "registration.hpp"
#include "targeting.hpp"

#include <phosphor-logging/log.hpp>

namespace openpower
{
namespace p9
{

using namespace phosphor::logging;
using namespace openpower::cfam::access;
using namespace openpower::cfam::p9;
using namespace openpower::targeting;

/**
 * @brief Performs the 'VCS Workaround' on all P9s in the system.
 * @return void
 */
void vcsWorkaround()
{
    Targeting targets;
    const auto& master = *(targets.begin());

    // First determine if we need to run this workaround (not needed on chips
    // which are not DD1.0)
    // Mixing DD1.0 parts with other levels is not allowed so just look
    // at the first chip
    auto chipID = readReg(master, P9_FSI2PIB_CHIPID);
    if (chipID != P9_DD10_CHIPID)
    {
        log<level::INFO>("P9 procedure vcsWorkaround not needed",
                         entry("CHIPID=0x%08X", chipID));
        return;
    }

    log<level::INFO>("Running P9 procedure vcsWorkaround",
                     entry("NUM_PROCS=%d", targets.size()));

    // Set asynchronous clock mode
    writeReg(master, P9_LL_MODE_REG, 0x00000001);

    for (const auto& t : targets)
    {
        // Unfence PLL controls
        writeRegWithMask(t, P9_ROOT_CTRL0, 0x00000000, 0x00010000);

        // Assert Perv chiplet endpoint reset
        writeRegWithMask(t, P9_PERV_CTRL0, 0x40000000, 0x40000000);

        // Enable Nest PLL
        writeRegWithMask(t, P9_PERV_CTRL0, 0x00000001, 0x00000001);
    }
}

REGISTER_PROCEDURE("vcsWorkaround", vcsWorkaround);

} // namespace p9
} // namespace openpower
/**
 * Copyright (C) 2017 IBM Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "registration.hpp"

#include <experimental/filesystem>
#include <fstream>
#include <org/open_power/Proc/FSI/error.hpp>
#include <phosphor-logging/log.hpp>

namespace openpower
{
namespace openfsi
{

using namespace phosphor::logging;
namespace fs = std::experimental::filesystem;
namespace fsi_error = sdbusplus::org::open_power::Proc::FSI::Error;

constexpr auto masterScanPath =
    "/sys/bus/platform/devices/gpio-fsi/fsi0/rescan";

constexpr auto hubScanPath = "/sys/devices/platform/gpio-fsi/fsi0/slave@00:00/"
                             "00:00:00:0a/fsi1/rescan";

constexpr auto masterCalloutPath =
    "/sys/devices/platform/gpio-fsi/fsi0/slave@00:00/raw";

/**
 * Writes a 1 to the sysfs file passed in to trigger
 * the device driver to do an FSI scan.
 *
 * @param[in] path - the sysfs path to write a 1 to
 */
static void doScan(const std::string& path)
{
    std::ofstream file;

    file.exceptions(std::ofstream::failbit | // logic error on operation
                    std::ofstream::badbit |  // read/write error on operation
                    std::ofstream::eofbit);  // end of file reached
    try
    {
        file.open(path);
        file << "1";
    }
    catch (std::exception& e)
    {
        auto err = errno;
        throw std::system_error(err, std::generic_category());
    }
}

/**
 * Performs an FSI master scan followed by an FSI hub scan.
 * This is where the device driver detects which chips are present.
 *
 * This is unrelated to scanning a ring out of a chip.
 */
void scan()
{
    // Note: Currently the FSI device driver will always return success on both
    // the master and hub scans.  The only way we can detect something
    // went wrong is if the master scan didn't create the hub scan file, so
    // we will check for that.
    // It is possible the driver will be updated in the future to actually
    // return a failure so the code will still check for them.

    try
    {
        doScan(masterScanPath);
    }
    catch (std::system_error& e)
    {
        log<level::ERR>("Failed to run the FSI master scan");

        using metadata = org::open_power::Proc::FSI::MasterDetectionFailure;

        elog<fsi_error::MasterDetectionFailure>(
            metadata::CALLOUT_ERRNO(e.code().value()),
            metadata::CALLOUT_DEVICE_PATH(masterCalloutPath));
    }

    if (!fs::exists(hubScanPath))
    {
        log<level::ERR>("The FSI master scan did not create a hub scan file");

        using metadata = org::open_power::Proc::FSI::MasterDetectionFailure;

        elog<fsi_error::MasterDetectionFailure>(
            metadata::CALLOUT_ERRNO(0),
            metadata::CALLOUT_DEVICE_PATH(masterCalloutPath));
    }

    try
    {
        doScan(hubScanPath);
    }
    catch (std::system_error& e)
    {
        // If the device driver is ever updated in the future to fail the sysfs
        // write call on a scan failure then it should also provide some hints
        // about which hardware failed so we can do an appropriate callout
        // here.  At this point in time, the driver shouldn't ever fail so
        // we won't worry about guessing at the callout.

        log<level::ERR>("Failed to run the FSI hub scan");

        using metadata = org::open_power::Proc::FSI::SlaveDetectionFailure;

        elog<fsi_error::SlaveDetectionFailure>(
            metadata::ERRNO(e.code().value()));
    }
}

REGISTER_PROCEDURE("scanFSI", scan);

} // namespace openfsi
} // namespace openpower
