// !!! WARNING: This is a GENERATED Code..Please do NOT Edit !!!
#include <map>
using EType = std::string;
using Error = std::string;
using ErrorList = std::vector<Error>;
using ErrorMap = std::map<EType, std::vector<Error>>;

const ErrorMap errorMap = {
    {"elog",
     {
         "xyz.openbmc_project.Common.Error.InternalFailure",
     }},
    {"checkstop",
     {
         "org.open_power.Host.Boot.Error.Checkstop",
         "org.open_power.Host.Boot.Error.WatchdogTimedOut",
     }},
};
