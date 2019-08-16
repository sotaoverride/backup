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
namespace Item
{
namespace server
{

class Ethernet
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
        Ethernet() = delete;
        Ethernet(const Ethernet&) = delete;
        Ethernet& operator=(const Ethernet&) = delete;
        Ethernet(Ethernet&&) = delete;
        Ethernet& operator=(Ethernet&&) = delete;
        virtual ~Ethernet() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Ethernet(bus::bus& bus, const char* path);






    private:


        static constexpr auto _interface = "xyz.openbmc_project.Inventory.Item.Ethernet";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Inventory_Item_Ethernet_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Item
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

