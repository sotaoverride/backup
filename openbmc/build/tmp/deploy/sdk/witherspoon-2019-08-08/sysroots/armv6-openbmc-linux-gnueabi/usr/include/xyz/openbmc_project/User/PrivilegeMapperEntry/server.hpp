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
namespace User
{
namespace server
{

class PrivilegeMapperEntry
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
        PrivilegeMapperEntry() = delete;
        PrivilegeMapperEntry(const PrivilegeMapperEntry&) = delete;
        PrivilegeMapperEntry& operator=(const PrivilegeMapperEntry&) = delete;
        PrivilegeMapperEntry(PrivilegeMapperEntry&&) = delete;
        PrivilegeMapperEntry& operator=(PrivilegeMapperEntry&&) = delete;
        virtual ~PrivilegeMapperEntry() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        PrivilegeMapperEntry(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                std::string>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        PrivilegeMapperEntry(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of GroupName */
        virtual std::string groupName() const;
        /** Set value of GroupName with option to skip sending signal */
        virtual std::string groupName(std::string value,
               bool skipSignal);
        /** Set value of GroupName */
        virtual std::string groupName(std::string value);
        /** Get value of Privilege */
        virtual std::string privilege() const;
        /** Set value of Privilege with option to skip sending signal */
        virtual std::string privilege(std::string value,
               bool skipSignal);
        /** Set value of Privilege */
        virtual std::string privilege(std::string value);

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

        /** @brief sd-bus callback for get-property 'GroupName' */
        static int _callback_get_GroupName(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'GroupName' */
        static int _callback_set_GroupName(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Privilege' */
        static int _callback_get_Privilege(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Privilege' */
        static int _callback_set_Privilege(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.User.PrivilegeMapperEntry";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_User_PrivilegeMapperEntry_interface;
        sdbusplus::SdBusInterface *_intf;

        std::string _groupName{};
        std::string _privilege{};

};


} // namespace server
} // namespace User
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

