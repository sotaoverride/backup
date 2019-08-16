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
namespace org
{
namespace open_power
{
namespace Logging
{
namespace server
{

class PEL
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
    PEL() = delete;
    PEL(const PEL&) = delete;
    PEL& operator=(const PEL&) = delete;
    PEL(PEL&&) = delete;
    PEL& operator=(PEL&&) = delete;
    virtual ~PEL() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    PEL(bus::bus& bus, const char* path);

    /** @brief Implementation for GetPEL
     *  Returns a file desciptor to a PEL.
     *
     *  @param[in] pelID - The PEL log ID of the PEL to retrieve.
     *
     *  @return data[sdbusplus::message::unix_fd] - A file descriptor for a file
     * that contains the PEL.
     */
    virtual sdbusplus::message::unix_fd getPEL(int32_t pelID) = 0;

    /** @brief Implementation for GetPELFromOBMCID
     *  Returns PEL data based on the OpenBMC event log ID.
     *
     *  @param[in] obmcLogID - The OpenBMC event log ID of the PEL to retrieve.
     *
     *  @return data[std::vector<uint8_t>] - The PEL data
     */
    virtual std::vector<uint8_t> getPELFromOBMCID(int32_t obmcLogID) = 0;

  private:
    /** @brief sd-bus callback for GetPEL
     */
    static int _callback_GetPEL(sd_bus_message*, void*, sd_bus_error*);

    /** @brief sd-bus callback for GetPELFromOBMCID
     */
    static int _callback_GetPELFromOBMCID(sd_bus_message*, void*,
                                          sd_bus_error*);

    static constexpr auto _interface = "org.open_power.Logging.PEL";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _org_open_power_Logging_PEL_interface;
    sdbusplus::SdBusInterface* _intf;
};

} // namespace server
} // namespace Logging
} // namespace open_power
} // namespace org
} // namespace sdbusplus
