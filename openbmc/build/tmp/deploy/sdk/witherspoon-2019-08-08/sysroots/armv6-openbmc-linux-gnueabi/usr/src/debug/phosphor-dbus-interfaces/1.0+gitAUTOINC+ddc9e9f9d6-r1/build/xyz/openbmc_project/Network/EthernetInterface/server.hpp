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

class EthernetInterface
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
    EthernetInterface() = delete;
    EthernetInterface(const EthernetInterface&) = delete;
    EthernetInterface& operator=(const EthernetInterface&) = delete;
    EthernetInterface(EthernetInterface&&) = delete;
    EthernetInterface& operator=(EthernetInterface&&) = delete;
    virtual ~EthernetInterface() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    EthernetInterface(bus::bus& bus, const char* path);

    enum class LinkLocalConf
    {
        both,
        v4,
        v6,
        none,
    };

    using PropertiesVariant =
        std::variant<std::vector<std::string>, LinkLocalConf, bool, uint32_t,
                     std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    EthernetInterface(bus::bus& bus, const char* path,
                      const std::map<std::string, PropertiesVariant>& vals,
                      bool skipSignal = false);

    /** Get value of InterfaceName */
    virtual std::string interfaceName() const;
    /** Set value of InterfaceName with option to skip sending signal */
    virtual std::string interfaceName(std::string value, bool skipSignal);
    /** Set value of InterfaceName */
    virtual std::string interfaceName(std::string value);
    /** Get value of Speed */
    virtual uint32_t speed() const;
    /** Set value of Speed with option to skip sending signal */
    virtual uint32_t speed(uint32_t value, bool skipSignal);
    /** Set value of Speed */
    virtual uint32_t speed(uint32_t value);
    /** Get value of AutoNeg */
    virtual bool autoNeg() const;
    /** Set value of AutoNeg with option to skip sending signal */
    virtual bool autoNeg(bool value, bool skipSignal);
    /** Set value of AutoNeg */
    virtual bool autoNeg(bool value);
    /** Get value of DomainName */
    virtual std::vector<std::string> domainName() const;
    /** Set value of DomainName with option to skip sending signal */
    virtual std::vector<std::string> domainName(std::vector<std::string> value,
                                                bool skipSignal);
    /** Set value of DomainName */
    virtual std::vector<std::string> domainName(std::vector<std::string> value);
    /** Get value of DHCPEnabled */
    virtual bool dHCPEnabled() const;
    /** Set value of DHCPEnabled with option to skip sending signal */
    virtual bool dHCPEnabled(bool value, bool skipSignal);
    /** Set value of DHCPEnabled */
    virtual bool dHCPEnabled(bool value);
    /** Get value of Nameservers */
    virtual std::vector<std::string> nameservers() const;
    /** Set value of Nameservers with option to skip sending signal */
    virtual std::vector<std::string> nameservers(std::vector<std::string> value,
                                                 bool skipSignal);
    /** Set value of Nameservers */
    virtual std::vector<std::string>
        nameservers(std::vector<std::string> value);
    /** Get value of NTPServers */
    virtual std::vector<std::string> nTPServers() const;
    /** Set value of NTPServers with option to skip sending signal */
    virtual std::vector<std::string> nTPServers(std::vector<std::string> value,
                                                bool skipSignal);
    /** Set value of NTPServers */
    virtual std::vector<std::string> nTPServers(std::vector<std::string> value);
    /** Get value of LinkLocalAutoConf */
    virtual LinkLocalConf linkLocalAutoConf() const;
    /** Set value of LinkLocalAutoConf with option to skip sending signal */
    virtual LinkLocalConf linkLocalAutoConf(LinkLocalConf value,
                                            bool skipSignal);
    /** Set value of LinkLocalAutoConf */
    virtual LinkLocalConf linkLocalAutoConf(LinkLocalConf value);
    /** Get value of IPv6AcceptRA */
    virtual bool iPv6AcceptRA() const;
    /** Set value of IPv6AcceptRA with option to skip sending signal */
    virtual bool iPv6AcceptRA(bool value, bool skipSignal);
    /** Set value of IPv6AcceptRA */
    virtual bool iPv6AcceptRA(bool value);

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

    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Network.EthernetInterface.<value
     * name>"
     *  @return - The enum value.
     */
    static LinkLocalConf convertLinkLocalConfFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'InterfaceName' */
    static int _callback_get_InterfaceName(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'InterfaceName' */
    static int _callback_set_InterfaceName(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Speed' */
    static int _callback_get_Speed(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Speed' */
    static int _callback_set_Speed(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);

    /** @brief sd-bus callback for get-property 'AutoNeg' */
    static int _callback_get_AutoNeg(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'AutoNeg' */
    static int _callback_set_AutoNeg(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    /** @brief sd-bus callback for get-property 'DomainName' */
    static int _callback_get_DomainName(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DomainName' */
    static int _callback_set_DomainName(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'DHCPEnabled' */
    static int _callback_get_DHCPEnabled(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DHCPEnabled' */
    static int _callback_set_DHCPEnabled(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Nameservers' */
    static int _callback_get_Nameservers(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Nameservers' */
    static int _callback_set_Nameservers(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);

    /** @brief sd-bus callback for get-property 'NTPServers' */
    static int _callback_get_NTPServers(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'NTPServers' */
    static int _callback_set_NTPServers(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'LinkLocalAutoConf' */
    static int _callback_get_LinkLocalAutoConf(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);
    /** @brief sd-bus callback for set-property 'LinkLocalAutoConf' */
    static int _callback_set_LinkLocalAutoConf(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);

    /** @brief sd-bus callback for get-property 'IPv6AcceptRA' */
    static int _callback_get_IPv6AcceptRA(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'IPv6AcceptRA' */
    static int _callback_set_IPv6AcceptRA(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Network.EthernetInterface";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Network_EthernetInterface_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _interfaceName{};
    uint32_t _speed{};
    bool _autoNeg{};
    std::vector<std::string> _domainName{};
    bool _dHCPEnabled{};
    std::vector<std::string> _nameservers{};
    std::vector<std::string> _nTPServers{};
    LinkLocalConf _linkLocalAutoConf{};
    bool _iPv6AcceptRA{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type EthernetInterface::LinkLocalConf.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(EthernetInterface::LinkLocalConf e);

} // namespace server
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
