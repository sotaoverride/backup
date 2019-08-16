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
namespace Channel
{
namespace server
{

class ChannelAccess
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
    ChannelAccess() = delete;
    ChannelAccess(const ChannelAccess&) = delete;
    ChannelAccess& operator=(const ChannelAccess&) = delete;
    ChannelAccess(ChannelAccess&&) = delete;
    ChannelAccess& operator=(ChannelAccess&&) = delete;
    virtual ~ChannelAccess() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    ChannelAccess(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    ChannelAccess(bus::bus& bus, const char* path,
                  const std::map<std::string, PropertiesVariant>& vals,
                  bool skipSignal = false);

    /** Get value of MaxPrivilege */
    virtual std::string maxPrivilege() const;
    /** Set value of MaxPrivilege with option to skip sending signal */
    virtual std::string maxPrivilege(std::string value, bool skipSignal);
    /** Set value of MaxPrivilege */
    virtual std::string maxPrivilege(std::string value);

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
    /** @brief sd-bus callback for get-property 'MaxPrivilege' */
    static int _callback_get_MaxPrivilege(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'MaxPrivilege' */
    static int _callback_set_MaxPrivilege(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Channel.ChannelAccess";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Channel_ChannelAccess_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _maxPrivilege{};
};

} // namespace server
} // namespace Channel
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
