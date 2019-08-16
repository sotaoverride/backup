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

class Watchdog
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
    Watchdog() = delete;
    Watchdog(const Watchdog&) = delete;
    Watchdog& operator=(const Watchdog&) = delete;
    Watchdog(Watchdog&&) = delete;
    Watchdog& operator=(Watchdog&&) = delete;
    virtual ~Watchdog() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Watchdog(bus::bus& bus, const char* path);

    enum class Action
    {
        None,
        HardReset,
        PowerOff,
        PowerCycle,
    };
    enum class TimerUse
    {
        Reserved,
        BIOSFRB2,
        BIOSPOST,
        OSLoad,
        SMSOS,
        OEM,
    };

    using PropertiesVariant = std::variant<Action, TimerUse, uint64_t, bool>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Watchdog(bus::bus& bus, const char* path,
             const std::map<std::string, PropertiesVariant>& vals,
             bool skipSignal = false);

    /** @brief Implementation for ResetTimeRemaining
     *  Resets the time remaining to the configured interval. This is equivalent
     * to reading the Interval and writing it into the TimeRemaining. Optionally
     * the watchdog can be enabled during the reset process.
     *
     *  @param[in] enableWatchdog - If true the watchdog will be enabled when
     * the reset is performed.
     */
    virtual void resetTimeRemaining(bool enableWatchdog) = 0;

    /** Get value of Initialized */
    virtual bool initialized() const;
    /** Set value of Initialized with option to skip sending signal */
    virtual bool initialized(bool value, bool skipSignal);
    /** Set value of Initialized */
    virtual bool initialized(bool value);
    /** Get value of Enabled */
    virtual bool enabled() const;
    /** Set value of Enabled with option to skip sending signal */
    virtual bool enabled(bool value, bool skipSignal);
    /** Set value of Enabled */
    virtual bool enabled(bool value);
    /** Get value of ExpireAction */
    virtual Action expireAction() const;
    /** Set value of ExpireAction with option to skip sending signal */
    virtual Action expireAction(Action value, bool skipSignal);
    /** Set value of ExpireAction */
    virtual Action expireAction(Action value);
    /** Get value of Interval */
    virtual uint64_t interval() const;
    /** Set value of Interval with option to skip sending signal */
    virtual uint64_t interval(uint64_t value, bool skipSignal);
    /** Set value of Interval */
    virtual uint64_t interval(uint64_t value);
    /** Get value of TimeRemaining */
    virtual uint64_t timeRemaining() const;
    /** Set value of TimeRemaining with option to skip sending signal */
    virtual uint64_t timeRemaining(uint64_t value, bool skipSignal);
    /** Set value of TimeRemaining */
    virtual uint64_t timeRemaining(uint64_t value);
    /** Get value of CurrentTimerUse */
    virtual TimerUse currentTimerUse() const;
    /** Set value of CurrentTimerUse with option to skip sending signal */
    virtual TimerUse currentTimerUse(TimerUse value, bool skipSignal);
    /** Set value of CurrentTimerUse */
    virtual TimerUse currentTimerUse(TimerUse value);
    /** Get value of ExpiredTimerUse */
    virtual TimerUse expiredTimerUse() const;
    /** Set value of ExpiredTimerUse with option to skip sending signal */
    virtual TimerUse expiredTimerUse(TimerUse value, bool skipSignal);
    /** Set value of ExpiredTimerUse */
    virtual TimerUse expiredTimerUse(TimerUse value);

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
     *                 "xyz.openbmc_project.State.Watchdog.<value name>"
     *  @return - The enum value.
     */
    static Action convertActionFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.State.Watchdog.<value name>"
     *  @return - The enum value.
     */
    static TimerUse convertTimerUseFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for ResetTimeRemaining
     */
    static int _callback_ResetTimeRemaining(sd_bus_message*, void*,
                                            sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Initialized' */
    static int _callback_get_Initialized(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Initialized' */
    static int _callback_set_Initialized(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Enabled' */
    static int _callback_get_Enabled(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Enabled' */
    static int _callback_set_Enabled(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    /** @brief sd-bus callback for get-property 'ExpireAction' */
    static int _callback_get_ExpireAction(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'ExpireAction' */
    static int _callback_set_ExpireAction(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Interval' */
    static int _callback_get_Interval(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Interval' */
    static int _callback_set_Interval(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);

    /** @brief sd-bus callback for get-property 'TimeRemaining' */
    static int _callback_get_TimeRemaining(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'TimeRemaining' */
    static int _callback_set_TimeRemaining(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'CurrentTimerUse' */
    static int _callback_get_CurrentTimerUse(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CurrentTimerUse' */
    static int _callback_set_CurrentTimerUse(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'ExpiredTimerUse' */
    static int _callback_get_ExpiredTimerUse(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'ExpiredTimerUse' */
    static int _callback_set_ExpiredTimerUse(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.State.Watchdog";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_State_Watchdog_interface;
    sdbusplus::SdBusInterface* _intf;

    bool _initialized = false;
    bool _enabled = false;
    Action _expireAction = Action::HardReset;
    uint64_t _interval = 30000;
    uint64_t _timeRemaining = 0;
    TimerUse _currentTimerUse = TimerUse::Reserved;
    TimerUse _expiredTimerUse = TimerUse::Reserved;
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Watchdog::Action.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Watchdog::Action e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Watchdog::TimerUse.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Watchdog::TimerUse e);

} // namespace server
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
