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

class Manager
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
        Manager() = delete;
        Manager(const Manager&) = delete;
        Manager& operator=(const Manager&) = delete;
        Manager(Manager&&) = delete;
        Manager& operator=(Manager&&) = delete;
        virtual ~Manager() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Manager(bus::bus& bus, const char* path);



        /** @brief Implementation for Notify
         *  Signal the implementing service that an item is ready to have its state managed.
         *
         *  @param[in] object - A dictionary of fully enumerated items to be managed.
         */
        virtual void notify(
            std::map<sdbusplus::message::object_path, std::map<std::string, std::map<std::string, std::variant<bool, int64_t, std::string>>>> object) = 0;




    private:

        /** @brief sd-bus callback for Notify
         */
        static int _callback_Notify(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Inventory.Manager";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Inventory_Manager_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

