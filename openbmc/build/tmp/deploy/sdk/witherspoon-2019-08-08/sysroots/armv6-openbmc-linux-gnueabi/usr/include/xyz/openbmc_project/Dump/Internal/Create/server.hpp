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
namespace Dump
{
namespace Internal
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

        enum class Type
        {
            ApplicationCored,
            UserRequested,
            InternalFailure,
            Checkstop,
        };


        /** @brief Implementation for Create
         *  Create BMC Dump based on the Dump type.
         *
         *  @param[in] type - Type of the Dump.
         *  @param[in] fullPaths - A list of paths (file paths or d-bus object paths) that must be processed to derive the dump content.
         */
        virtual void create(
            Type type,
            std::vector<std::string> fullPaths) = 0;



    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Dump.Internal.Create.<value name>"
     *  @return - The enum value.
     */
    static Type convertTypeFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for Create
         */
        static int _callback_Create(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Dump.Internal.Create";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Dump_Internal_Create_interface;
        sdbusplus::SdBusInterface *_intf;


};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Create::Type.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Create::Type e);

} // namespace server
} // namespace Internal
} // namespace Dump
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

