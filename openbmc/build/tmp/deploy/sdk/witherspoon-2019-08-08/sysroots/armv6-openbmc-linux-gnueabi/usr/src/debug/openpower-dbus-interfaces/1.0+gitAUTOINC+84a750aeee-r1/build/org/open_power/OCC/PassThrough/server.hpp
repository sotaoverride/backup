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
namespace OCC
{
namespace server
{

class PassThrough
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
    PassThrough() = delete;
    PassThrough(const PassThrough&) = delete;
    PassThrough& operator=(const PassThrough&) = delete;
    PassThrough(PassThrough&&) = delete;
    PassThrough& operator=(PassThrough&&) = delete;
    virtual ~PassThrough() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    PassThrough(bus::bus& bus, const char* path);

    /** @brief Implementation for Send
     *  Pass through a command to the OCC.
     *
     *  @param[in] command - An array of integers representing the command and
     * payload. This should still be bytes worth of data (as though using
     * array[byte]), so each entry in the array should pack as many bytes as
     * possible.
     *
     *  @return response[std::vector<int32_t>] - An array of integers
     * representing the response. This should still be bytes worth of data (as
     * though using array[byte]), so each entry in the array should pack as many
     * bytes as possible.
     */
    virtual std::vector<int32_t> send(std::vector<int32_t> command) = 0;

  private:
    /** @brief sd-bus callback for Send
     */
    static int _callback_Send(sd_bus_message*, void*, sd_bus_error*);

    static constexpr auto _interface = "org.open_power.OCC.PassThrough";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _org_open_power_OCC_PassThrough_interface;
    sdbusplus::SdBusInterface* _intf;
};

} // namespace server
} // namespace OCC
} // namespace open_power
} // namespace org
} // namespace sdbusplus
