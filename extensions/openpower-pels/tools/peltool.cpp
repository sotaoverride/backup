#include "peltool.hpp"
#include "peltool_utility.hpp"
#include <iostream>
#include <iterator>
#include <map>
#include <phosphor-logging/log.hpp>
#include <fstream>
#include <filesystem>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
#include "../pel.hpp"
namespace openpower
{
namespace pels
{

using namespace phosphor::logging;
namespace fs = std::filesystem;

#define SECTION_VERSION "Section Version"
//--------------UH------------------------
#define SCOPE "Scope"                   //       
#define SEVERITY "Severity"             //  
#define EVENT_TYPE "Event Type"         //  
#define PROBLEM_DOMAIN "Problem Domain" //
#define PROBLEM_VECTOR "Problem Vector" //
#define ACTION_FLAGS "Action Flags"     //
//----------------------------------------
//-------------PH---------------------------//
#define CREATE_TIME_STAMP "Created at"     //
#define COMMIT_TIME_STAMP "Commited at"   //
#define CREATOR_ID        "Creator id"   // 
#define LOG_TYPE          "Log type"    //
#define SECTION_COUNT     "Section count" //
#define OBMC_LOG_ID       "Log id"       //
#define CREATOR_VERSION   "Creator version"// 
#define ID                "id"            //
#define PLID              "plid"         //
//--------------------------------------- 

#define SUBSECTION_TYPE "Subsection Type"//
#define CREATED_BY "Created by"         // 
#define CREATED_AT "Created at"        //
#define COMMITED_AT "Commited at"    
#define CREATOR_SUBSYSTEM "Creator Subsytemm"
#define CSSVER "CSSVER"
#define PLATFORM_LOG_ID "Platform Log Id"
#define ENTRY_ID "Entry ID"
#define LOG_SIZE "Total Log Size"

/*void PelTool::parseRawPEL(const std::string& rawPelPath, uint32_t obmcLogID)
{
    if (fs::exists(rawPelPath))
    {
        std::ifstream file(rawPelPath, std::ios::in | std::ios::binary);

        auto data = std::vector<uint8_t>(std::istreambuf_iterator<char>(file),
                                         std::istreambuf_iterator<char>());
        if (file.fail())
        {
            log<level::ERR>("Filesystem error reading a raw PEL",
                            entry("PELFILE=%s", rawPelPath.c_str()),
                            entry("OBMCLOGID=%d", obmcLogID));
            // TODO, Decide what to do here. Maybe nothing.
            return;
        }

        file.close();

        auto pel = std::make_unique<PEL>(data, obmcLogID);
        if (pel->valid())
        {
            // PELs created by others still need these fields set by us.
            pel->assignID();
            pel->setCommitTime();

            try
            {
                _repo.add(pel);
            }
            catch (std::exception& e)
            {
                // Probably a full or r/o filesystem, not much we can do.
                log<level::ERR>("Unable to add PEL to Repository",
                                entry("PEL_ID=0x%X", pel->id()));
            }
	    //start parsing here.
            //std::stringstream ss;
            //user header
            PelTool::ss <<  CREATOR_SUBSYSTEM << pel->userHeader()->subsystem() << SCOPE << pel->userHeader()->scope()
            << SEVERITY << pel->userHeader()->severity() << EVENT_TYPE << pel->userHeader()->eventType()
            << PROBLEM_DOMAIN << pel->userHeader()->problemDomain() << PROBLEM_VECTOR << pel->userHeader()->problemVector()
            << ACTION_FLAGS << pel->userHeader()->actionFlags()
            //private header
            << CREATE_TIME_STAMP 
            << pel->privateHeader()->createTimestamp().yearMSB 
            << pel->privateHeader()->createTimestamp().yearLSB
            << pel->privateHeader()->createTimestamp().month
            << pel->privateHeader()->createTimestamp().day
            << pel->privateHeader()->createTimestamp().hour
            << pel->privateHeader()->createTimestamp().minutes
            << pel->privateHeader()->createTimestamp().seconds 
            << pel->privateHeader()->createTimestamp().hundredths
            << COMMIT_TIME_STAMP
            << pel->privateHeader()->commitTimestamp().yearMSB 
            << pel->privateHeader()->commitTimestamp().yearLSB 
            << pel->privateHeader()->commitTimestamp().month 
            << pel->privateHeader()->commitTimestamp().day 
            << pel->privateHeader()->commitTimestamp().hour
            << pel->privateHeader()->commitTimestamp().minutes 
            << pel->privateHeader()->commitTimestamp().seconds 
            << pel->privateHeader()->commitTimestamp().hundredths 
            << CREATOR_ID << pel->privateHeader()->creatorID() 
            << LOG_TYPE << pel->privateHeader()->logType() << SECTION_COUNT << pel->privateHeader()->sectionCount()
            << OBMC_LOG_ID << pel->privateHeader()->obmcLogID() 
           // << CREATOR_VERSION << pel->privateHeader()->creatorVersion()
            << ID << pel->privateHeader()->id() << PLID << pel->privateHeader()->plid();
        }
        else
        {
            log<level::ERR>("Invalid PEL found",
                            entry("PELFILE=%s", rawPelPath.c_str()),
                            entry("OBMCLOGID=%d", obmcLogID));
            // TODO, make a whole new OpenBMC event log + PEL
        }
    }
    else
    {
        log<level::ERR>("Raw PEL file from BMC event log does not exist",
                        entry("PELFILE=%s", (rawPelPath).c_str()),
                        entry("OBMCLOGID=%d", obmcLogID));

    }
}*/
} // namespace peltool
} // namespace openpower