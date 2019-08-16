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
namespace Security
{
namespace server
{

class RestrictionMode
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
        RestrictionMode() = delete;
        RestrictionMode(const RestrictionMode&) = delete;
        RestrictionMode& operator=(const RestrictionMode&) = delete;
        RestrictionMode(RestrictionMode&&) = delete;
        RestrictionMode& operator=(RestrictionMode&&) = delete;
        virtual ~RestrictionMode() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        RestrictionMode(bus::bus& bus, const char* path);

        enum class Modes
        {
            None,
            Whitelist,
            Blacklist,
        };

        using PropertiesVariant = std::variant<
                Modes>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        RestrictionMode(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of RestrictionMode */
        virtual Modes restrictionMode() const;
        /** Set value of RestrictionMode with option to skip sending signal */
        virtual Modes restrictionMode(Modes value,
               bool skipSignal);
        /** Set value of RestrictionMode */
        virtual Modes restrictionMode(Modes value);

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
     *                 "xyz.openbmc_project.Control.Security.RestrictionMode.<value name>"
     *  @return - The enum value.
     */
    static Modes convertModesFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for get-property 'RestrictionMode' */
        static int _callback_get_RestrictionMode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'RestrictionMode' */
        static int _callback_set_RestrictionMode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Control.Security.RestrictionMode";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Control_Security_RestrictionMode_interface;
        sdbusplus::SdBusInterface *_intf;

        Modes _restrictionMode{};

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type RestrictionMode::Modes.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(RestrictionMode::Modes e);

} // namespace server
} // namespace Security
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

