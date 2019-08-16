#pragma once
#include <systemd/sd-bus.h>

#include <map>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
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

class PowerSupply
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
    PowerSupply() = delete;
    PowerSupply(const PowerSupply&) = delete;
    PowerSupply& operator=(const PowerSupply&) = delete;
    PowerSupply(PowerSupply&&) = delete;
    PowerSupply& operator=(PowerSupply&&) = delete;
    virtual ~PowerSupply() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    PowerSupply(bus::bus& bus, const char* path);

  private:
    static constexpr auto _interface =
        "xyz.openbmc_project.Inventory.Item.PowerSupply";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Inventory_Item_PowerSupply_interface;
    sdbusplus::SdBusInterface* _intf;
};

} // namespace server
} // namespace Item
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
