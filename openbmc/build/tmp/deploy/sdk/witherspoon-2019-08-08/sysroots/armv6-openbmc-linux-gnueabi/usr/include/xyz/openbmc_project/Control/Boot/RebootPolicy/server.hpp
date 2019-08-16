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

class RebootPolicy
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
        RebootPolicy() = delete;
        RebootPolicy(const RebootPolicy&) = delete;
        RebootPolicy& operator=(const RebootPolicy&) = delete;
        RebootPolicy(RebootPolicy&&) = delete;
        RebootPolicy& operator=(RebootPolicy&&) = delete;
        virtual ~RebootPolicy() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        RebootPolicy(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                bool>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        RebootPolicy(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of AutoReboot */
        virtual bool autoReboot() const;
        /** Set value of AutoReboot with option to skip sending signal */
        virtual bool autoReboot(bool value,
               bool skipSignal);
        /** Set value of AutoReboot */
        virtual bool autoReboot(bool value);

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

        /** @brief sd-bus callback for get-property 'AutoReboot' */
        static int _callback_get_AutoReboot(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'AutoReboot' */
        static int _callback_set_AutoReboot(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Control.Boot.RebootPolicy";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Control_Boot_RebootPolicy_interface;
        sdbusplus::SdBusInterface *_intf;

        bool _autoReboot{};

};


} // namespace server
} // namespace Boot
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

