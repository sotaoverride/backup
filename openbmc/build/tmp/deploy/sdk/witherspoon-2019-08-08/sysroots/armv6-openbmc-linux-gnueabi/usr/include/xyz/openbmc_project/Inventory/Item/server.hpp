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
namespace server
{

class Item
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
        Item() = delete;
        Item(const Item&) = delete;
        Item& operator=(const Item&) = delete;
        Item(Item&&) = delete;
        Item& operator=(Item&&) = delete;
        virtual ~Item() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Item(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                bool,
                std::string>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        Item(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of PrettyName */
        virtual std::string prettyName() const;
        /** Set value of PrettyName with option to skip sending signal */
        virtual std::string prettyName(std::string value,
               bool skipSignal);
        /** Set value of PrettyName */
        virtual std::string prettyName(std::string value);
        /** Get value of Present */
        virtual bool present() const;
        /** Set value of Present with option to skip sending signal */
        virtual bool present(bool value,
               bool skipSignal);
        /** Set value of Present */
        virtual bool present(bool value);

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

        /** @brief sd-bus callback for get-property 'PrettyName' */
        static int _callback_get_PrettyName(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'PrettyName' */
        static int _callback_set_PrettyName(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Present' */
        static int _callback_get_Present(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Present' */
        static int _callback_set_Present(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Inventory.Item";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Inventory_Item_interface;
        sdbusplus::SdBusInterface *_intf;

        std::string _prettyName{};
        bool _present{};

};


} // namespace server
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

