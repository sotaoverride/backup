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
namespace Led
{
namespace server
{

class Physical
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
    Physical() = delete;
    Physical(const Physical&) = delete;
    Physical& operator=(const Physical&) = delete;
    Physical(Physical&&) = delete;
    Physical& operator=(Physical&&) = delete;
    virtual ~Physical() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Physical(bus::bus& bus, const char* path);

    enum class Action
    {
        Off,
        On,
        Blink,
    };
    enum class Palette
    {
        Unknown,
        Red,
        Green,
        Blue,
        Yellow,
    };

    using PropertiesVariant = std::variant<Action, Palette, uint16_t, uint8_t>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Physical(bus::bus& bus, const char* path,
             const std::map<std::string, PropertiesVariant>& vals,
             bool skipSignal = false);

    /** Get value of State */
    virtual Action state() const;
    /** Set value of State with option to skip sending signal */
    virtual Action state(Action value, bool skipSignal);
    /** Set value of State */
    virtual Action state(Action value);
    /** Get value of DutyOn */
    virtual uint8_t dutyOn() const;
    /** Set value of DutyOn with option to skip sending signal */
    virtual uint8_t dutyOn(uint8_t value, bool skipSignal);
    /** Set value of DutyOn */
    virtual uint8_t dutyOn(uint8_t value);
    /** Get value of Color */
    virtual Palette color() const;
    /** Set value of Color with option to skip sending signal */
    virtual Palette color(Palette value, bool skipSignal);
    /** Set value of Color */
    virtual Palette color(Palette value);
    /** Get value of Period */
    virtual uint16_t period() const;
    /** Set value of Period with option to skip sending signal */
    virtual uint16_t period(uint16_t value, bool skipSignal);
    /** Set value of Period */
    virtual uint16_t period(uint16_t value);

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
     *                 "xyz.openbmc_project.Led.Physical.<value name>"
     *  @return - The enum value.
     */
    static Action convertActionFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Led.Physical.<value name>"
     *  @return - The enum value.
     */
    static Palette convertPaletteFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'State' */
    static int _callback_get_State(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'State' */
    static int _callback_set_State(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);

    /** @brief sd-bus callback for get-property 'DutyOn' */
    static int _callback_get_DutyOn(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DutyOn' */
    static int _callback_set_DutyOn(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Color' */
    static int _callback_get_Color(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Color' */
    static int _callback_set_Color(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Period' */
    static int _callback_get_Period(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Period' */
    static int _callback_set_Period(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Led.Physical";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Led_Physical_interface;
    sdbusplus::SdBusInterface* _intf;

    Action _state = Action::Off;
    uint8_t _dutyOn = 50;
    Palette _color = Palette::Unknown;
    uint16_t _period = 1000;
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Physical::Action.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Physical::Action e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Physical::Palette.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Physical::Palette e);

} // namespace server
} // namespace Led
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
