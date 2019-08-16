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

class Neighbor
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
    Neighbor() = delete;
    Neighbor(const Neighbor&) = delete;
    Neighbor& operator=(const Neighbor&) = delete;
    Neighbor(Neighbor&&) = delete;
    Neighbor& operator=(Neighbor&&) = delete;
    virtual ~Neighbor() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Neighbor(bus::bus& bus, const char* path);

    enum class State
    {
        Incomplete,
        Reachable,
        Stale,
        Invalid,
        Permanent,
    };

    using PropertiesVariant = std::variant<State, std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Neighbor(bus::bus& bus, const char* path,
             const std::map<std::string, PropertiesVariant>& vals,
             bool skipSignal = false);

    /** Get value of IPAddress */
    virtual std::string iPAddress() const;
    /** Set value of IPAddress with option to skip sending signal */
    virtual std::string iPAddress(std::string value, bool skipSignal);
    /** Set value of IPAddress */
    virtual std::string iPAddress(std::string value);
    /** Get value of MACAddress */
    virtual std::string mACAddress() const;
    /** Set value of MACAddress with option to skip sending signal */
    virtual std::string mACAddress(std::string value, bool skipSignal);
    /** Set value of MACAddress */
    virtual std::string mACAddress(std::string value);
    /** Get value of State */
    virtual State state() const;
    /** Set value of State with option to skip sending signal */
    virtual State state(State value, bool skipSignal);
    /** Set value of State */
    virtual State state(State value);

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
     *                 "xyz.openbmc_project.Network.Neighbor.<value name>"
     *  @return - The enum value.
     */
    static State convertStateFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'IPAddress' */
    static int _callback_get_IPAddress(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);
    /** @brief sd-bus callback for set-property 'IPAddress' */
    static int _callback_set_IPAddress(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);

    /** @brief sd-bus callback for get-property 'MACAddress' */
    static int _callback_get_MACAddress(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'MACAddress' */
    static int _callback_set_MACAddress(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'State' */
    static int _callback_get_State(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'State' */
    static int _callback_set_State(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Network.Neighbor";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Network_Neighbor_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _iPAddress{};
    std::string _mACAddress{};
    State _state{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Neighbor::State.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Neighbor::State e);

} // namespace server
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
