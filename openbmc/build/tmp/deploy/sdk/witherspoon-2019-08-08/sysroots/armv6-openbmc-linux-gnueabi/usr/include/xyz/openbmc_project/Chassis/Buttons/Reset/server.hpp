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
namespace Chassis
{
namespace Buttons
{
namespace server
{

class Reset
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
        Reset() = delete;
        Reset(const Reset&) = delete;
        Reset& operator=(const Reset&) = delete;
        Reset(Reset&&) = delete;
        Reset& operator=(Reset&&) = delete;
        virtual ~Reset() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Reset(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                bool>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        Reset(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);


        /** @brief Implementation for simPress
         *  Emulate reset button press.
         */
        virtual void simPress(
            ) = 0;


        /** @brief Send signal 'Released'
         *
         *  Reset button released signal
         */
        void released(
            );

        /** @brief Send signal 'Pressed'
         *
         *  Reset button pressed signal
         */
        void pressed(
            );

        /** Get value of Enabled */
        virtual bool enabled() const;
        /** Set value of Enabled with option to skip sending signal */
        virtual bool enabled(bool value,
               bool skipSignal);
        /** Set value of Enabled */
        virtual bool enabled(bool value);

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


    private:

        /** @brief sd-bus callback for simPress
         */
        static int _callback_SimPress(
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Enabled' */
        static int _callback_get_Enabled(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Enabled' */
        static int _callback_set_Enabled(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Chassis.Buttons.Reset";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Chassis_Buttons_Reset_interface;
        sdbusplus::SdBusInterface *_intf;

        bool _enabled = true;

};


} // namespace server
} // namespace Buttons
} // namespace Chassis
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

