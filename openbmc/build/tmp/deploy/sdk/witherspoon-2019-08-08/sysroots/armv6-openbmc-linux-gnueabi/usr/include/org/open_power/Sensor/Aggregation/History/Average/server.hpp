#pragma once
#include <map>
#include <string>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <systemd/sd-bus.h>
#include <tuple>
#include <variant>




namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Sensor
{
namespace Aggregation
{
namespace History
{
namespace server
{

class Average
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
        Average() = delete;
        Average(const Average&) = delete;
        Average& operator=(const Average&) = delete;
        Average(Average&&) = delete;
        Average& operator=(Average&&) = delete;
        virtual ~Average() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Average(bus::bus& bus, const char* path);

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

        using PropertiesVariant = std::variant<
                std::vector<std::tuple<uint64_t, int64_t>>,
                Unit,
                int64_t>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        Average(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of Scale */
        virtual int64_t scale() const;
        /** Set value of Scale with option to skip sending signal */
        virtual int64_t scale(int64_t value,
               bool skipSignal);
        /** Set value of Scale */
        virtual int64_t scale(int64_t value);
        /** Get value of Unit */
        virtual Unit unit() const;
        /** Set value of Unit with option to skip sending signal */
        virtual Unit unit(Unit value,
               bool skipSignal);
        /** Set value of Unit */
        virtual Unit unit(Unit value);
        /** Get value of Values */
        virtual std::vector<std::tuple<uint64_t, int64_t>> values() const;
        /** Set value of Values with option to skip sending signal */
        virtual std::vector<std::tuple<uint64_t, int64_t>> values(std::vector<std::tuple<uint64_t, int64_t>> value,
               bool skipSignal);
        /** Set value of Values */
        virtual std::vector<std::tuple<uint64_t, int64_t>> values(std::vector<std::tuple<uint64_t, int64_t>> value);

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
     *                 "org.open_power.Sensor.Aggregation.History.Average.<value name>"
     *  @return - The enum value.
     */
    static Unit convertUnitFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for get-property 'Scale' */
        static int _callback_get_Scale(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Scale' */
        static int _callback_set_Scale(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Unit' */
        static int _callback_get_Unit(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Unit' */
        static int _callback_set_Unit(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Values' */
        static int _callback_get_Values(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Values' */
        static int _callback_set_Values(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "org.open_power.Sensor.Aggregation.History.Average";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _org_open_power_Sensor_Aggregation_History_Average_interface;
        sdbusplus::SdBusInterface *_intf;

        int64_t _scale{};
        Unit _unit{};
        std::vector<std::tuple<uint64_t, int64_t>> _values{};

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Average::Unit.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Average::Unit e);

} // namespace server
} // namespace History
} // namespace Aggregation
} // namespace Sensor
} // namespace open_power
} // namespace org
} // namespace sdbusplus

