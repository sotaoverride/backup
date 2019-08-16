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

class Critical
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
    Critical() = delete;
    Critical(const Critical&) = delete;
    Critical& operator=(const Critical&) = delete;
    Critical(Critical&&) = delete;
    Critical& operator=(Critical&&) = delete;
    virtual ~Critical() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Critical(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<bool, int64_t>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Critical(bus::bus& bus, const char* path,
             const std::map<std::string, PropertiesVariant>& vals,
             bool skipSignal = false);

    /** Get value of CriticalHigh */
    virtual int64_t criticalHigh() const;
    /** Set value of CriticalHigh with option to skip sending signal */
    virtual int64_t criticalHigh(int64_t value, bool skipSignal);
    /** Set value of CriticalHigh */
    virtual int64_t criticalHigh(int64_t value);
    /** Get value of CriticalLow */
    virtual int64_t criticalLow() const;
    /** Set value of CriticalLow with option to skip sending signal */
    virtual int64_t criticalLow(int64_t value, bool skipSignal);
    /** Set value of CriticalLow */
    virtual int64_t criticalLow(int64_t value);
    /** Get value of CriticalAlarmHigh */
    virtual bool criticalAlarmHigh() const;
    /** Set value of CriticalAlarmHigh with option to skip sending signal */
    virtual bool criticalAlarmHigh(bool value, bool skipSignal);
    /** Set value of CriticalAlarmHigh */
    virtual bool criticalAlarmHigh(bool value);
    /** Get value of CriticalAlarmLow */
    virtual bool criticalAlarmLow() const;
    /** Set value of CriticalAlarmLow with option to skip sending signal */
    virtual bool criticalAlarmLow(bool value, bool skipSignal);
    /** Set value of CriticalAlarmLow */
    virtual bool criticalAlarmLow(bool value);

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
    /** @brief sd-bus callback for get-property 'CriticalHigh' */
    static int _callback_get_CriticalHigh(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CriticalHigh' */
    static int _callback_set_CriticalHigh(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    /** @brief sd-bus callback for get-property 'CriticalLow' */
    static int _callback_get_CriticalLow(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CriticalLow' */
    static int _callback_set_CriticalLow(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);

    /** @brief sd-bus callback for get-property 'CriticalAlarmHigh' */
    static int _callback_get_CriticalAlarmHigh(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CriticalAlarmHigh' */
    static int _callback_set_CriticalAlarmHigh(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);

    /** @brief sd-bus callback for get-property 'CriticalAlarmLow' */
    static int _callback_get_CriticalAlarmLow(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CriticalAlarmLow' */
    static int _callback_set_CriticalAlarmLow(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Sensor.Threshold.Critical";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Sensor_Threshold_Critical_interface;
    sdbusplus::SdBusInterface* _intf;

    int64_t _criticalHigh{};
    int64_t _criticalLow{};
    bool _criticalAlarmHigh{};
    bool _criticalAlarmLow{};
};

} // namespace server
} // namespace Threshold
} // namespace Sensor
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
