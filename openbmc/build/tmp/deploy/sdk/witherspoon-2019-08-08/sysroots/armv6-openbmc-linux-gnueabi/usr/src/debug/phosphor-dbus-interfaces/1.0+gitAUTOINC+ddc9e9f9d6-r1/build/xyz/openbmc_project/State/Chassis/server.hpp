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
namespace State
{
namespace server
{

class Chassis
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
    Chassis() = delete;
    Chassis(const Chassis&) = delete;
    Chassis& operator=(const Chassis&) = delete;
    Chassis(Chassis&&) = delete;
    Chassis& operator=(Chassis&&) = delete;
    virtual ~Chassis() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Chassis(bus::bus& bus, const char* path);

    enum class Transition
    {
        Off,
        On,
    };
    enum class PowerState
    {
        Off,
        On,
    };

    using PropertiesVariant = std::variant<uint64_t, Transition, PowerState>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Chassis(bus::bus& bus, const char* path,
            const std::map<std::string, PropertiesVariant>& vals,
            bool skipSignal = false);

    /** Get value of RequestedPowerTransition */
    virtual Transition requestedPowerTransition() const;
    /** Set value of RequestedPowerTransition with option to skip sending signal
     */
    virtual Transition requestedPowerTransition(Transition value,
                                                bool skipSignal);
    /** Set value of RequestedPowerTransition */
    virtual Transition requestedPowerTransition(Transition value);
    /** Get value of CurrentPowerState */
    virtual PowerState currentPowerState() const;
    /** Set value of CurrentPowerState with option to skip sending signal */
    virtual PowerState currentPowerState(PowerState value, bool skipSignal);
    /** Set value of CurrentPowerState */
    virtual PowerState currentPowerState(PowerState value);
    /** Get value of LastStateChangeTime */
    virtual uint64_t lastStateChangeTime() const;
    /** Set value of LastStateChangeTime with option to skip sending signal */
    virtual uint64_t lastStateChangeTime(uint64_t value, bool skipSignal);
    /** Set value of LastStateChangeTime */
    virtual uint64_t lastStateChangeTime(uint64_t value);

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
     *                 "xyz.openbmc_project.State.Chassis.<value name>"
     *  @return - The enum value.
     */
    static Transition convertTransitionFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.State.Chassis.<value name>"
     *  @return - The enum value.
     */
    static PowerState convertPowerStateFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'RequestedPowerTransition' */
    static int _callback_get_RequestedPowerTransition(sd_bus*, const char*,
                                                      const char*, const char*,
                                                      sd_bus_message*, void*,
                                                      sd_bus_error*);
    /** @brief sd-bus callback for set-property 'RequestedPowerTransition' */
    static int _callback_set_RequestedPowerTransition(sd_bus*, const char*,
                                                      const char*, const char*,
                                                      sd_bus_message*, void*,
                                                      sd_bus_error*);

    /** @brief sd-bus callback for get-property 'CurrentPowerState' */
    static int _callback_get_CurrentPowerState(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CurrentPowerState' */
    static int _callback_set_CurrentPowerState(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);

    /** @brief sd-bus callback for get-property 'LastStateChangeTime' */
    static int _callback_get_LastStateChangeTime(sd_bus*, const char*,
                                                 const char*, const char*,
                                                 sd_bus_message*, void*,
                                                 sd_bus_error*);
    /** @brief sd-bus callback for set-property 'LastStateChangeTime' */
    static int _callback_set_LastStateChangeTime(sd_bus*, const char*,
                                                 const char*, const char*,
                                                 sd_bus_message*, void*,
                                                 sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.State.Chassis";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_State_Chassis_interface;
    sdbusplus::SdBusInterface* _intf;

    Transition _requestedPowerTransition = Transition::Off;
    PowerState _currentPowerState{};
    uint64_t _lastStateChangeTime{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Chassis::Transition.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Chassis::Transition e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Chassis::PowerState.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Chassis::PowerState e);

} // namespace server
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
