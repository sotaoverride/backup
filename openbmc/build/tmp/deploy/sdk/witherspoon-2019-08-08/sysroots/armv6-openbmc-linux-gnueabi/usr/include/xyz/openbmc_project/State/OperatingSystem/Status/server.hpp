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
namespace State
{
namespace OperatingSystem
{
namespace server
{

class Status
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
        Status() = delete;
        Status(const Status&) = delete;
        Status& operator=(const Status&) = delete;
        Status(Status&&) = delete;
        Status& operator=(Status&&) = delete;
        virtual ~Status() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Status(bus::bus& bus, const char* path);

        enum class OSStatus
        {
            CBoot,
            PXEBoot,
            DiagBoot,
            CDROMBoot,
            ROMBoot,
            BootComplete,
            Inactive,
            Standby,
        };

        using PropertiesVariant = std::variant<
                OSStatus>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        Status(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of OperatingSystemState */
        virtual OSStatus operatingSystemState() const;
        /** Set value of OperatingSystemState with option to skip sending signal */
        virtual OSStatus operatingSystemState(OSStatus value,
               bool skipSignal);
        /** Set value of OperatingSystemState */
        virtual OSStatus operatingSystemState(OSStatus value);

        /** @brief Sets a property by name.
         *  @param[in] _name - A string representation of the property name.
         *  @param[in] val - A variant containing the value to set.
         */
        void setPropertyByName(const std::string& _name,
                               const PropertiesVariant& val,
                               bool skipSignal = false);

        /** @brief Gets a property by name.
         *  @param[in] _name - A string representation of the property name.
         *  @return - A variant containing the value of the property.
         */
        PropertiesVariant getPropertyByName(const std::string& _name);

    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.State.OperatingSystem.Status.<value name>"
     *  @return - The enum value.
     */
    static OSStatus convertOSStatusFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for get-property 'OperatingSystemState' */
        static int _callback_get_OperatingSystemState(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'OperatingSystemState' */
        static int _callback_set_OperatingSystemState(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.State.OperatingSystem.Status";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_State_OperatingSystem_Status_interface;
        sdbusplus::SdBusInterface *_intf;

        OSStatus _operatingSystemState = OSStatus::Inactive;

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Status::OSStatus.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Status::OSStatus e);

} // namespace server
} // namespace OperatingSystem
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

