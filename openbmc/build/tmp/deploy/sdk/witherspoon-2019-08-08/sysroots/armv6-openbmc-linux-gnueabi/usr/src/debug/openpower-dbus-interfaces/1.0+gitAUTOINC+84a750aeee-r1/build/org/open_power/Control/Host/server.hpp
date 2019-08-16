#pragma once
#include <systemd/sd-bus.h>

#include <map>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>

namespace sdbusplus
{
namespace org
{
namespace open_power
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
        OCCReset,
    };
    enum class Result
    {
        Success,
        Failure,
    };

    /** @brief Implementation for Execute
     *  Execute the requested command by the caller. This command will be
     * processed in first in first out order. See the Command enum description
     * below for details on all supported commands.
     *
     *  @param[in] command - Requested command to execute against the host
     *  @param[in] data - Data associated with the command.
     */
    virtual void execute(Command command, std::variant<uint8_t> data) = 0;

    /** @brief Send signal 'CommandComplete'
     *
     *  Signal indicating that a command has completed
     *
     *  @param[in] command - Executed command
     *  @param[in] result - Result of the command execution
     */
    void commandComplete(Command command, Result result);

    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "org.open_power.Control.Host.<value name>"
     *  @return - The enum value.
     */
    static Command convertCommandFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "org.open_power.Control.Host.<value name>"
     *  @return - The enum value.
     */
    static Result convertResultFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for Execute
     */
    static int _callback_Execute(sd_bus_message*, void*, sd_bus_error*);

    static constexpr auto _interface = "org.open_power.Control.Host";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _org_open_power_Control_Host_interface;
    sdbusplus::SdBusInterface* _intf;
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
} // namespace open_power
} // namespace org
} // namespace sdbusplus
