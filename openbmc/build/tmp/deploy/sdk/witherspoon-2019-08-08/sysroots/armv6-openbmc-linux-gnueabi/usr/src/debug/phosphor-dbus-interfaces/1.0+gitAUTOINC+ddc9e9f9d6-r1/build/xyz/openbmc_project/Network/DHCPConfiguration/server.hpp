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

class DHCPConfiguration
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
    DHCPConfiguration() = delete;
    DHCPConfiguration(const DHCPConfiguration&) = delete;
    DHCPConfiguration& operator=(const DHCPConfiguration&) = delete;
    DHCPConfiguration(DHCPConfiguration&&) = delete;
    DHCPConfiguration& operator=(DHCPConfiguration&&) = delete;
    virtual ~DHCPConfiguration() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    DHCPConfiguration(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<bool>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    DHCPConfiguration(bus::bus& bus, const char* path,
                      const std::map<std::string, PropertiesVariant>& vals,
                      bool skipSignal = false);

    /** Get value of DNSEnabled */
    virtual bool dNSEnabled() const;
    /** Set value of DNSEnabled with option to skip sending signal */
    virtual bool dNSEnabled(bool value, bool skipSignal);
    /** Set value of DNSEnabled */
    virtual bool dNSEnabled(bool value);
    /** Get value of NTPEnabled */
    virtual bool nTPEnabled() const;
    /** Set value of NTPEnabled with option to skip sending signal */
    virtual bool nTPEnabled(bool value, bool skipSignal);
    /** Set value of NTPEnabled */
    virtual bool nTPEnabled(bool value);
    /** Get value of HostNameEnabled */
    virtual bool hostNameEnabled() const;
    /** Set value of HostNameEnabled with option to skip sending signal */
    virtual bool hostNameEnabled(bool value, bool skipSignal);
    /** Set value of HostNameEnabled */
    virtual bool hostNameEnabled(bool value);
    /** Get value of SendHostNameEnabled */
    virtual bool sendHostNameEnabled() const;
    /** Set value of SendHostNameEnabled with option to skip sending signal */
    virtual bool sendHostNameEnabled(bool value, bool skipSignal);
    /** Set value of SendHostNameEnabled */
    virtual bool sendHostNameEnabled(bool value);

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
    /** @brief sd-bus callback for get-property 'DNSEnabled' */
    static int _callback_get_DNSEnabled(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DNSEnabled' */
    static int _callback_set_DNSEnabled(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'NTPEnabled' */
    static int _callback_get_NTPEnabled(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'NTPEnabled' */
    static int _callback_set_NTPEnabled(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'HostNameEnabled' */
    static int _callback_get_HostNameEnabled(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'HostNameEnabled' */
    static int _callback_set_HostNameEnabled(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'SendHostNameEnabled' */
    static int _callback_get_SendHostNameEnabled(sd_bus*, const char*,
                                                 const char*, const char*,
                                                 sd_bus_message*, void*,
                                                 sd_bus_error*);
    /** @brief sd-bus callback for set-property 'SendHostNameEnabled' */
    static int _callback_set_SendHostNameEnabled(sd_bus*, const char*,
                                                 const char*, const char*,
                                                 sd_bus_message*, void*,
                                                 sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Network.DHCPConfiguration";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Network_DHCPConfiguration_interface;
    sdbusplus::SdBusInterface* _intf;

    bool _dNSEnabled{};
    bool _nTPEnabled{};
    bool _hostNameEnabled{};
    bool _sendHostNameEnabled{};
};

} // namespace server
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
