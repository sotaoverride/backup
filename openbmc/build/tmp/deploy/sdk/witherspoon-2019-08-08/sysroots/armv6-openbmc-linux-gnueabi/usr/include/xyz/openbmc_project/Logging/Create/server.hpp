#pragma once
#include <map>
#include <string>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <systemd/sd-bus.h>
#include <tuple>
#include <variant>

#include <xyz/openbmc_project/Logging/Entry/server.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Logging
{
namespace server
{

class Create
{
    public:
        /* Define all of the basic class operations:
         *     Not allowed:
         *         - Default constructor to avoid nullptrs.
         *         - Copy operations due to internal unique_ptr.
         *         - Move operations due to 'this' being registered as the
         *           'context' with sdbus.
         *     Allowed:
         *         - Destructor.
         */
        Create() = delete;
        Create(const Create&) = delete;
        Create& operator=(const Create&) = delete;
        Create(Create&&) = delete;
        Create& operator=(Create&&) = delete;
        virtual ~Create() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Create(bus::bus& bus, const char* path);



        /** @brief Implementation for Create
         *  Create a xyz.openbmc_project.Logging.Entry object.
         *
         *  @param[in] message - The Message property of the event entry.
         *  @param[in] severity - The Severity property of the event entry.
         *  @param[in] additionalData - The AdditionalData property of the event entry. e.g.:
  {
    "key1": "value1",
    "key2": "value2"
  }
ends up in AdditionaData like:
  ["KEY1=value1", "KEY2=value2"]
         */
        virtual void create(
            std::string message,
            xyz::openbmc_project::Logging::server::Entry::Level severity,
            std::map<std::string, std::string> additionalData) = 0;




    private:

        /** @brief sd-bus callback for Create
         */
        static int _callback_Create(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Logging.Create";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Logging_Create_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Logging
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

