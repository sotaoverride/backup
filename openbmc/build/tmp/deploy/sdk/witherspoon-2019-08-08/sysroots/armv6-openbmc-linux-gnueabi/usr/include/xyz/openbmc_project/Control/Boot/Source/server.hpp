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
namespace Boot
{
namespace server
{

class Source
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
        Source() = delete;
        Source(const Source&) = delete;
        Source& operator=(const Source&) = delete;
        Source(Source&&) = delete;
        Source& operator=(Source&&) = delete;
        virtual ~Source() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Source(bus::bus& bus, const char* path);

        enum class Sources
        {
            Disk,
            ExternalMedia,
            Network,
            Default,
            RemovableMedia,
        };

        using PropertiesVariant = std::variant<
                Sources>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        Source(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of BootSource */
        virtual Sources bootSource() const;
        /** Set value of BootSource with option to skip sending signal */
        virtual Sources bootSource(Sources value,
               bool skipSignal);
        /** Set value of BootSource */
        virtual Sources bootSource(Sources value);

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
     *                 "xyz.openbmc_project.Control.Boot.Source.<value name>"
     *  @return - The enum value.
     */
    static Sources convertSourcesFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for get-property 'BootSource' */
        static int _callback_get_BootSource(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'BootSource' */
        static int _callback_set_BootSource(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Control.Boot.Source";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Control_Boot_Source_interface;
        sdbusplus::SdBusInterface *_intf;

        Sources _bootSource{};

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Source::Sources.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Source::Sources e);

} // namespace server
} // namespace Boot
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

