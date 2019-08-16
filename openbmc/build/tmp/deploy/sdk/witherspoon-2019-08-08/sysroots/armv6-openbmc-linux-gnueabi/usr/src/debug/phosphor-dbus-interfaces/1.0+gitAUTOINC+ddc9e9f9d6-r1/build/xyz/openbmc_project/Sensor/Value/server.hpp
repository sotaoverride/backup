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
namespace Sensor
{
namespace server
{

class Value
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
    Value() = delete;
    Value(const Value&) = delete;
    Value& operator=(const Value&) = delete;
    Value(Value&&) = delete;
    Value& operator=(Value&&) = delete;
    virtual ~Value() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Value(bus::bus& bus, const char* path);

    enum class Unit
    {
        DegreesC,
        RPMS,
        Volts,
        Meters,
        Amperes,
        Watts,
        Joules,
    };

    using PropertiesVariant = std::variant<Unit, int64_t>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Value(bus::bus& bus, const char* path,
          const std::map<std::string, PropertiesVariant>& vals,
          bool skipSignal = false);

    /** Get value of Value */
    virtual int64_t value() const;
    /** Set value of Value with option to skip sending signal */
    virtual int64_t value(int64_t value, bool skipSignal);
    /** Set value of Value */
    virtual int64_t value(int64_t value);
    /** Get value of MaxValue */
    virtual int64_t maxValue() const;
    /** Set value of MaxValue with option to skip sending signal */
    virtual int64_t maxValue(int64_t value, bool skipSignal);
    /** Set value of MaxValue */
    virtual int64_t maxValue(int64_t value);
    /** Get value of MinValue */
    virtual int64_t minValue() const;
    /** Set value of MinValue with option to skip sending signal */
    virtual int64_t minValue(int64_t value, bool skipSignal);
    /** Set value of MinValue */
    virtual int64_t minValue(int64_t value);
    /** Get value of Unit */
    virtual Unit unit() const;
    /** Set value of Unit with option to skip sending signal */
    virtual Unit unit(Unit value, bool skipSignal);
    /** Set value of Unit */
    virtual Unit unit(Unit value);
    /** Get value of Scale */
    virtual int64_t scale() const;
    /** Set value of Scale with option to skip sending signal */
    virtual int64_t scale(int64_t value, bool skipSignal);
    /** Set value of Scale */
    virtual int64_t scale(int64_t value);

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
     *                 "xyz.openbmc_project.Sensor.Value.<value name>"
     *  @return - The enum value.
     */
    static Unit convertUnitFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'Value' */
    static int _callback_get_Value(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Value' */
    static int _callback_set_Value(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);

    /** @brief sd-bus callback for get-property 'MaxValue' */
    static int _callback_get_MaxValue(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);
    /** @brief sd-bus callback for set-property 'MaxValue' */
    static int _callback_set_MaxValue(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);

    /** @brief sd-bus callback for get-property 'MinValue' */
    static int _callback_get_MinValue(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);
    /** @brief sd-bus callback for set-property 'MinValue' */
    static int _callback_set_MinValue(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Unit' */
    static int _callback_get_Unit(sd_bus*, const char*, const char*,
                                  const char*, sd_bus_message*, void*,
                                  sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Unit' */
    static int _callback_set_Unit(sd_bus*, const char*, const char*,
                                  const char*, sd_bus_message*, void*,
                                  sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Scale' */
    static int _callback_get_Scale(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Scale' */
    static int _callback_set_Scale(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Sensor.Value";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Sensor_Value_interface;
    sdbusplus::SdBusInterface* _intf;

    int64_t _value{};
    int64_t _maxValue{};
    int64_t _minValue{};
    Unit _unit{};
    int64_t _scale{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Value::Unit.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Value::Unit e);

} // namespace server
} // namespace Sensor
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
