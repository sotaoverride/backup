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
namespace Board
{
namespace server
{

class IOBoard
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
    IOBoard() = delete;
    IOBoard(const IOBoard&) = delete;
    IOBoard& operator=(const IOBoard&) = delete;
    IOBoard(IOBoard&&) = delete;
    IOBoard& operator=(IOBoard&&) = delete;
    virtual ~IOBoard() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    IOBoard(bus::bus& bus, const char* path);

  private:
    static constexpr auto _interface =
        "xyz.openbmc_project.Inventory.Item.Board.IOBoard";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Inventory_Item_Board_IOBoard_interface;
    sdbusplus::SdBusInterface* _intf;
};

} // namespace server
} // namespace Board
} // namespace Item
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
