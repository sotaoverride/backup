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
namespace Inventory
{
namespace Decorator
{
namespace server
{

class MeetsMinimumShipLevel
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
        MeetsMinimumShipLevel() = delete;
        MeetsMinimumShipLevel(const MeetsMinimumShipLevel&) = delete;
        MeetsMinimumShipLevel& operator=(const MeetsMinimumShipLevel&) = delete;
        MeetsMinimumShipLevel(MeetsMinimumShipLevel&&) = delete;
        MeetsMinimumShipLevel& operator=(MeetsMinimumShipLevel&&) = delete;
        virtual ~MeetsMinimumShipLevel() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        MeetsMinimumShipLevel(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                bool>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        MeetsMinimumShipLevel(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of MeetsMinimumShipLevel */
        virtual bool meetsMinimumShipLevel() const;
        /** Set value of MeetsMinimumShipLevel with option to skip sending signal */
        virtual bool meetsMinimumShipLevel(bool value,
               bool skipSignal);
        /** Set value of MeetsMinimumShipLevel */
        virtual bool meetsMinimumShipLevel(bool value);

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

        /** @brief sd-bus callback for get-property 'MeetsMinimumShipLevel' */
        static int _callback_get_MeetsMinimumShipLevel(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'MeetsMinimumShipLevel' */
        static int _callback_set_MeetsMinimumShipLevel(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Inventory.Decorator.MeetsMinimumShipLevel";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Inventory_Decorator_MeetsMinimumShipLevel_interface;
        sdbusplus::SdBusInterface *_intf;

        bool _meetsMinimumShipLevel{};

};


} // namespace server
} // namespace Decorator
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

