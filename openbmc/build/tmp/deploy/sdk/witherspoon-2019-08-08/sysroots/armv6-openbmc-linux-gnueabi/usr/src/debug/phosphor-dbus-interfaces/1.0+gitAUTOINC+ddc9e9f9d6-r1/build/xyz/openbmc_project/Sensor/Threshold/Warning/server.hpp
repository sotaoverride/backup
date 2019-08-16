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
namespace Threshold
{
namespace server
{

class Warning
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
    Warning() = delete;
    Warning(const Warning&) = delete;
    Warning& operator=(const Warning&) = delete;
    Warning(Warning&&) = delete;
    Warning& operator=(Warning&&) = delete;
    virtual ~Warning() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Warning(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<bool, int64_t>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Warning(bus::bus& bus, const char* path,
            const std::map<std::string, PropertiesVariant>& vals,
            bool skipSignal = false);

    /** Get value of WarningHigh */
    virtual int64_t warningHigh() const;
    /** Set value of WarningHigh with option to skip sending signal */
    virtual int64_t warningHigh(int64_t value, bool skipSignal);
    /** Set value of WarningHigh */
    virtual int64_t warningHigh(int64_t value);
    /** Get value of WarningLow */
    virtual int64_t warningLow() const;
    /** Set value of WarningLow with option to skip sending signal */
    virtual int64_t warningLow(int64_t value, bool skipSignal);
    /** Set value of WarningLow */
    virtual int64_t warningLow(int64_t value);
    /** Get value of WarningAlarmHigh */
    virtual bool warningAlarmHigh() const;
    /** Set value of WarningAlarmHigh with option to skip sending signal */
    virtual bool warningAlarmHigh(bool value, bool skipSignal);
    /** Set value of WarningAlarmHigh */
    virtual bool warningAlarmHigh(bool value);
    /** Get value of WarningAlarmLow */
    virtual bool warningAlarmLow() const;
    /** Set value of WarningAlarmLow with option to skip sending signal */
    virtual bool warningAlarmLow(bool value, bool skipSignal);
    /** Set value of WarningAlarmLow */
    virtual bool warningAlarmLow(bool value);

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
    /** @brief sd-bus callback for get-property 'WarningHigh' */
    static int _callback_get_WarningHigh(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);
    /** @brief sd-bus callback for set-property 'WarningHigh' */
    static int _callback_set_WarningHigh(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);

    /** @brief sd-bus callback for get-property 'WarningLow' */
    static int _callback_get_WarningLow(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'WarningLow' */
    static int _callback_set_WarningLow(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'WarningAlarmHigh' */
    static int _callback_get_WarningAlarmHigh(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'WarningAlarmHigh' */
    static int _callback_set_WarningAlarmHigh(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'WarningAlarmLow' */
    static int _callback_get_WarningAlarmLow(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'WarningAlarmLow' */
    static int _callback_set_WarningAlarmLow(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Sensor.Threshold.Warning";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Sensor_Threshold_Warning_interface;
    sdbusplus::SdBusInterface* _intf;

    int64_t _warningHigh{};
    int64_t _warningLow{};
    bool _warningAlarmHigh{};
    bool _warningAlarmLow{};
};

} // namespace server
} // namespace Threshold
} // namespace Sensor
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
