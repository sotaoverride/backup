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
namespace org
{
namespace open_power
{
namespace OCC
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


        using PropertiesVariant = std::variant<
                bool>;

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



        /** Get value of OccActive */
        virtual bool occActive() const;
        /** Set value of OccActive with option to skip sending signal */
        virtual bool occActive(bool value,
               bool skipSignal);
        /** Set value of OccActive */
        virtual bool occActive(bool value);
        /** Get value of ThrottleProcTemp */
        virtual bool throttleProcTemp() const;
        /** Set value of ThrottleProcTemp with option to skip sending signal */
        virtual bool throttleProcTemp(bool value,
               bool skipSignal);
        /** Set value of ThrottleProcTemp */
        virtual bool throttleProcTemp(bool value);
        /** Get value of ThrottleProcPower */
        virtual bool throttleProcPower() const;
        /** Set value of ThrottleProcPower with option to skip sending signal */
        virtual bool throttleProcPower(bool value,
               bool skipSignal);
        /** Set value of ThrottleProcPower */
        virtual bool throttleProcPower(bool value);
        /** Get value of ThrottleMemTemp */
        virtual bool throttleMemTemp() const;
        /** Set value of ThrottleMemTemp with option to skip sending signal */
        virtual bool throttleMemTemp(bool value,
               bool skipSignal);
        /** Set value of ThrottleMemTemp */
        virtual bool throttleMemTemp(bool value);

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

        /** @brief sd-bus callback for get-property 'OccActive' */
        static int _callback_get_OccActive(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'OccActive' */
        static int _callback_set_OccActive(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'ThrottleProcTemp' */
        static int _callback_get_ThrottleProcTemp(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'ThrottleProcTemp' */
        static int _callback_set_ThrottleProcTemp(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'ThrottleProcPower' */
        static int _callback_get_ThrottleProcPower(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'ThrottleProcPower' */
        static int _callback_set_ThrottleProcPower(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'ThrottleMemTemp' */
        static int _callback_get_ThrottleMemTemp(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'ThrottleMemTemp' */
        static int _callback_set_ThrottleMemTemp(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "org.open_power.OCC.Status";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _org_open_power_OCC_Status_interface;
        sdbusplus::SdBusInterface *_intf;

        bool _occActive{};
        bool _throttleProcTemp = 0;
        bool _throttleProcPower = 0;
        bool _throttleMemTemp = 0;

};


} // namespace server
} // namespace OCC
} // namespace open_power
} // namespace org
} // namespace sdbusplus

