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

class SystemConfiguration
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
    SystemConfiguration() = delete;
    SystemConfiguration(const SystemConfiguration&) = delete;
    SystemConfiguration& operator=(const SystemConfiguration&) = delete;
    SystemConfiguration(SystemConfiguration&&) = delete;
    SystemConfiguration& operator=(SystemConfiguration&&) = delete;
    virtual ~SystemConfiguration() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    SystemConfiguration(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    SystemConfiguration(bus::bus& bus, const char* path,
                        const std::map<std::string, PropertiesVariant>& vals,
                        bool skipSignal = false);

    /** Get value of HostName */
    virtual std::string hostName() const;
    /** Set value of HostName with option to skip sending signal */
    virtual std::string hostName(std::string value, bool skipSignal);
    /** Set value of HostName */
    virtual std::string hostName(std::string value);
    /** Get value of DefaultGateway */
    virtual std::string defaultGateway() const;
    /** Set value of DefaultGateway with option to skip sending signal */
    virtual std::string defaultGateway(std::string value, bool skipSignal);
    /** Set value of DefaultGateway */
    virtual std::string defaultGateway(std::string value);
    /** Get value of DefaultGateway6 */
    virtual std::string defaultGateway6() const;
    /** Set value of DefaultGateway6 with option to skip sending signal */
    virtual std::string defaultGateway6(std::string value, bool skipSignal);
    /** Set value of DefaultGateway6 */
    virtual std::string defaultGateway6(std::string value);

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
    /** @brief sd-bus callback for get-property 'HostName' */
    static int _callback_get_HostName(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);
    /** @brief sd-bus callback for set-property 'HostName' */
    static int _callback_set_HostName(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);

    /** @brief sd-bus callback for get-property 'DefaultGateway' */
    static int _callback_get_DefaultGateway(sd_bus*, const char*, const char*,
                                            const char*, sd_bus_message*, void*,
                                            sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DefaultGateway' */
    static int _callback_set_DefaultGateway(sd_bus*, const char*, const char*,
                                            const char*, sd_bus_message*, void*,
                                            sd_bus_error*);

    /** @brief sd-bus callback for get-property 'DefaultGateway6' */
    static int _callback_get_DefaultGateway6(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DefaultGateway6' */
    static int _callback_set_DefaultGateway6(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Network.SystemConfiguration";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Network_SystemConfiguration_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _hostName{};
    std::string _defaultGateway{};
    std::string _defaultGateway6{};
};

} // namespace server
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
