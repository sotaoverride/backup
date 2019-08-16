#pragma once
#include <map>
#include <string>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <systemd/sd-bus.h>
#include <tuple>
#include <variant>



namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Logging
{
namespace Internal
{
namespace server
{

class Manager
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
        Manager() = delete;
        Manager(const Manager&) = delete;
        Manager& operator=(const Manager&) = delete;
        Manager(Manager&&) = delete;
        Manager& operator=(Manager&&) = delete;
        virtual ~Manager() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Manager(bus::bus& bus, const char* path);



        /** @brief Implementation for Commit
         *  Write the requested error/event entry with its associated metadata fields to flash. The "level" of the committed error log is same as the level defined in error YAML definitions.
         *
         *  @param[in] transactionId - The unique identifier of the journal entry(ies) to be committed.
         *  @param[in] errMsg - The error exception message associated with the error event log to be committed.
         */
        virtual void commit(
            uint64_t transactionId,
            std::string errMsg) = 0;

        /** @brief Implementation for CommitWithLvl
         *  Write the requested error/event entry with its associated metadata fields to flash. This interface allows the caller to override the error level specified in the error YAML definition.
         *
         *  @param[in] transactionId - The unique identifier of the journal entry(ies) to be committed.
         *  @param[in] errMsg - The error exception message associated with the error event log to be committed.
         *  @param[in] errLvl - The error level/severity indicator.
         */
        virtual void commitWithLvl(
            uint64_t transactionId,
            std::string errMsg,
            uint32_t errLvl) = 0;




    private:

        /** @brief sd-bus callback for Commit
         */
        static int _callback_Commit(
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for CommitWithLvl
         */
        static int _callback_CommitWithLvl(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Logging.Internal.Manager";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Logging_Internal_Manager_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Internal
} // namespace Logging
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
