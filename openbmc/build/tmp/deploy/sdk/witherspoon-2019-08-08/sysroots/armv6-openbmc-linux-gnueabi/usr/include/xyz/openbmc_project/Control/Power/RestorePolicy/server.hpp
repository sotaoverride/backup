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
namespace Power
{
namespace server
{

class RestorePolicy
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
        RestorePolicy() = delete;
        RestorePolicy(const RestorePolicy&) = delete;
        RestorePolicy& operator=(const RestorePolicy&) = delete;
        RestorePolicy(RestorePolicy&&) = delete;
        RestorePolicy& operator=(RestorePolicy&&) = delete;
        virtual ~RestorePolicy() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        RestorePolicy(bus::bus& bus, const char* path);

        enum class Policy
        {
            AlwaysOn,
            AlwaysOff,
            Restore,
        };

        using PropertiesVariant = std::variant<
                Policy>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        RestorePolicy(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of PowerRestorePolicy */
        virtual Policy powerRestorePolicy() const;
        /** Set value of PowerRestorePolicy with option to skip sending signal */
        virtual Policy powerRestorePolicy(Policy value,
               bool skipSignal);
        /** Set value of PowerRestorePolicy */
        virtual Policy powerRestorePolicy(Policy value);

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
     *                 "xyz.openbmc_project.Control.Power.RestorePolicy.<value name>"
     *  @return - The enum value.
     */
    static Policy convertPolicyFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for get-property 'PowerRestorePolicy' */
        static int _callback_get_PowerRestorePolicy(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'PowerRestorePolicy' */
        static int _callback_set_PowerRestorePolicy(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Control.Power.RestorePolicy";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Control_Power_RestorePolicy_interface;
        sdbusplus::SdBusInterface *_intf;

        Policy _powerRestorePolicy{};

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type RestorePolicy::Policy.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(RestorePolicy::Policy e);

} // namespace server
} // namespace Power
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

