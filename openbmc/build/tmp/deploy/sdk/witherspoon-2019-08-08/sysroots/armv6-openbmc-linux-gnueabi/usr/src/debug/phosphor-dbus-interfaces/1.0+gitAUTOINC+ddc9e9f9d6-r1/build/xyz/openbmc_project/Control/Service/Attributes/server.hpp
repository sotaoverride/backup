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
namespace Control
{
namespace Service
{
namespace server
{

class Attributes
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
    Attributes() = delete;
    Attributes(const Attributes&) = delete;
    Attributes& operator=(const Attributes&) = delete;
    Attributes(Attributes&&) = delete;
    Attributes& operator=(Attributes&&) = delete;
    virtual ~Attributes() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Attributes(bus::bus& bus, const char* path);

    enum class SupportedStates
    {
        enabled,
        disabled,
    };

    using PropertiesVariant =
        std::variant<std::vector<std::string>, uint32_t, SupportedStates>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Attributes(bus::bus& bus, const char* path,
               const std::map<std::string, PropertiesVariant>& vals,
               bool skipSignal = false);

    /** Get value of State */
    virtual SupportedStates state() const;
    /** Set value of State with option to skip sending signal */
    virtual SupportedStates state(SupportedStates value, bool skipSignal);
    /** Set value of State */
    virtual SupportedStates state(SupportedStates value);
    /** Get value of Port */
    virtual uint32_t port() const;
    /** Set value of Port with option to skip sending signal */
    virtual uint32_t port(uint32_t value, bool skipSignal);
    /** Set value of Port */
    virtual uint32_t port(uint32_t value);
    /** Get value of Channel */
    virtual std::vector<std::string> channel() const;
    /** Set value of Channel with option to skip sending signal */
    virtual std::vector<std::string> channel(std::vector<std::string> value,
                                             bool skipSignal);
    /** Set value of Channel */
    virtual std::vector<std::string> channel(std::vector<std::string> value);

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
     *                 "xyz.openbmc_project.Control.Service.Attributes.<value
     * name>"
     *  @return - The enum value.
     */
    static SupportedStates
        convertSupportedStatesFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'State' */
    static int _callback_get_State(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'State' */
    static int _callback_set_State(sd_bus*, const char*, const char*,
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

    /** @brief sd-bus callback for get-property 'Channel' */
    static int _callback_get_Channel(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Channel' */
    static int _callback_set_Channel(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Control.Service.Attributes";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Control_Service_Attributes_interface;
    sdbusplus::SdBusInterface* _intf;

    SupportedStates _state{};
    uint32_t _port{};
    std::vector<std::string> _channel{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Attributes::SupportedStates.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Attributes::SupportedStates e);

} // namespace server
} // namespace Service
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
