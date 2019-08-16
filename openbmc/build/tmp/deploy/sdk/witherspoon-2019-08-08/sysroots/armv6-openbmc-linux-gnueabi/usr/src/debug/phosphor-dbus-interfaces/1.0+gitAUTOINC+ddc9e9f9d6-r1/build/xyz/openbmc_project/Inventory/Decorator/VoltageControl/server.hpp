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
namespace Decorator
{
namespace server
{

class VoltageControl
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
    VoltageControl() = delete;
    VoltageControl(const VoltageControl&) = delete;
    VoltageControl& operator=(const VoltageControl&) = delete;
    VoltageControl(VoltageControl&&) = delete;
    VoltageControl& operator=(VoltageControl&&) = delete;
    virtual ~VoltageControl() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    VoltageControl(bus::bus& bus, const char* path);

  private:
    static constexpr auto _interface =
        "xyz.openbmc_project.Inventory.Decorator.VoltageControl";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Inventory_Decorator_VoltageControl_interface;
    sdbusplus::SdBusInterface* _intf;
};

} // namespace server
} // namespace Decorator
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
