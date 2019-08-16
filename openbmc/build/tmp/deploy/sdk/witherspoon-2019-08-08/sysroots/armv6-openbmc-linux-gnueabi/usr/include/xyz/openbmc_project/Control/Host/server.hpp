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
namespace Control
{
namespace server
{

class Host
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
        Host() = delete;
        Host(const Host&) = delete;
        Host& operator=(const Host&) = delete;
        Host(Host&&) = delete;
        Host& operator=(Host&&) = delete;
        virtual ~Host() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Host(bus::bus& bus, const char* path);

        enum class Command
        {
            SoftOff,
            Heartbeat,
        };
        enum class Result
        {
            Success,
            Failure,
        };


        /** @brief Implementation for Execute
         *  Execute the requested command by the caller. This command will be processed in first in first out order. See the Command enum description below for details on all supported commands.
         *
         *  @param[in] command - Requested command to execute against the host
         */
        virtual void execute(
            Command command) = 0;


        /** @brief Send signal 'CommandComplete'
         *
         *  Signal indicating that a Command has completed
         *
         *  @param[in] command - Executed command
         *  @param[in] result - Result of the command execution
         */
        void commandComplete(
            Command command,
            Result result);


    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Control.Host.<value name>"
     *  @return - The enum value.
     */
    static Command convertCommandFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Control.Host.<value name>"
     *  @return - The enum value.
     */
    static Result convertResultFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for Execute
         */
        static int _callback_Execute(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Control.Host";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Control_Host_interface;
        sdbusplus::SdBusInterface *_intf;


};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Host::Command.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Host::Command e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Host::Result.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Host::Result e);

} // namespace server
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

