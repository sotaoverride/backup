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
namespace Network
{
namespace server
{

class VLAN
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
    VLAN() = delete;
    VLAN(const VLAN&) = delete;
    VLAN& operator=(const VLAN&) = delete;
    VLAN(VLAN&&) = delete;
    VLAN& operator=(VLAN&&) = delete;
    virtual ~VLAN() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    VLAN(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<uint32_t, std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    VLAN(bus::bus& bus, const char* path,
         const std::map<std::string, PropertiesVariant>& vals,
         bool skipSignal = false);

    /** Get value of InterfaceName */
    virtual std::string interfaceName() const;
    /** Set value of InterfaceName with option to skip sending signal */
    virtual std::string interfaceName(std::string value, bool skipSignal);
    /** Set value of InterfaceName */
    virtual std::string interfaceName(std::string value);
    /** Get value of Id */
    virtual uint32_t id() const;
    /** Set value of Id with option to skip sending signal */
    virtual uint32_t id(uint32_t value, bool skipSignal);
    /** Set value of Id */
    virtual uint32_t id(uint32_t value);

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
    /** @brief sd-bus callback for get-property 'InterfaceName' */
    static int _callback_get_InterfaceName(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'InterfaceName' */
    static int _callback_set_InterfaceName(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Id' */
    static int _callback_get_Id(sd_bus*, const char*, const char*, const char*,
                                sd_bus_message*, void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Id' */
    static int _callback_set_Id(sd_bus*, const char*, const char*, const char*,
                                sd_bus_message*, void*, sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Network.VLAN";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Network_VLAN_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _interfaceName{};
    uint32_t _id{};
};

} // namespace server
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
