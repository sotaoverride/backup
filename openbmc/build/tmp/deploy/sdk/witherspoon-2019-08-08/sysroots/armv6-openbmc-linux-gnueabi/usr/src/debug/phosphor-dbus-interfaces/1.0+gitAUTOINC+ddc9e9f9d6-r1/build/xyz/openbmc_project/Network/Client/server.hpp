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

class Client
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
    Client() = delete;
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    Client(Client&&) = delete;
    Client& operator=(Client&&) = delete;
    virtual ~Client() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Client(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<uint16_t, std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Client(bus::bus& bus, const char* path,
           const std::map<std::string, PropertiesVariant>& vals,
           bool skipSignal = false);

    /** Get value of Address */
    virtual std::string address() const;
    /** Set value of Address with option to skip sending signal */
    virtual std::string address(std::string value, bool skipSignal);
    /** Set value of Address */
    virtual std::string address(std::string value);
    /** Get value of Port */
    virtual uint16_t port() const;
    /** Set value of Port with option to skip sending signal */
    virtual uint16_t port(uint16_t value, bool skipSignal);
    /** Set value of Port */
    virtual uint16_t port(uint16_t value);

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
    /** @brief sd-bus callback for get-property 'Address' */
    static int _callback_get_Address(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Address' */
    static int _callback_set_Address(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Port' */
    static int _callback_get_Port(sd_bus*, const char*, const char*,
                                  const char*, sd_bus_message*, void*,
                                  sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Port' */
    static int _callback_set_Port(sd_bus*, const char*, const char*,
                                  const char*, sd_bus_message*, void*,
                                  sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Network.Client";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Network_Client_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _address{};
    uint16_t _port{};
};

} // namespace server
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
