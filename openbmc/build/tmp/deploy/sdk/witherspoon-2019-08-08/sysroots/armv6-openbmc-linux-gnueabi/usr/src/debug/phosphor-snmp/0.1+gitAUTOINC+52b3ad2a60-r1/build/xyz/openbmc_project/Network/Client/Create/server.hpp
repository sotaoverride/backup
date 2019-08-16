#pragma once
#include "xyz/openbmc_project/Network/Client/server.hpp"

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
namespace Network
{
namespace Client
{
namespace server
{

class Create
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
    Create() = delete;
    Create(const Create&) = delete;
    Create& operator=(const Create&) = delete;
    Create(Create&&) = delete;
    Create& operator=(Create&&) = delete;
    virtual ~Create() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Create(bus::bus& bus, const char* path);

    /** @brief Implementation for Client
     *  Create network client endpoint.
     *
     *  @param[in] address - IP Address/Hostname
     *  @param[in] port - Network port.
     *
     *  @return path[std::string] - Path of the object which has been created.
     */
    virtual std::string client(std::string address, uint16_t port) = 0;

  private:
    /** @brief sd-bus callback for Client
     */
    static int _callback_Client(sd_bus_message*, void*, sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Network.Client.Create";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Network_Client_Create_interface;
    sdbusplus::SdBusInterface* _intf;
};

} // namespace server
} // namespace Client
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
