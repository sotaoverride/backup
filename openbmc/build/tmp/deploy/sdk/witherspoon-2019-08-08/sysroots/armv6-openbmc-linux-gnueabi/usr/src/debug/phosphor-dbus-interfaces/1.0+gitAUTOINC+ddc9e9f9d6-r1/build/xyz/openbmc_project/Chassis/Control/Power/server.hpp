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
namespace Chassis
{
namespace Control
{
namespace server
{

class Power
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
    Power() = delete;
    Power(const Power&) = delete;
    Power& operator=(const Power&) = delete;
    Power(Power&&) = delete;
    Power& operator=(Power&&) = delete;
    virtual ~Power() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Power(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<int32_t, bool>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Power(bus::bus& bus, const char* path,
          const std::map<std::string, PropertiesVariant>& vals,
          bool skipSignal = false);

    /** @brief Implementation for forcePowerOff
     *  Force power off the host.
     *
     *  @return status[bool] - The result of power off command.
     */
    virtual bool forcePowerOff() = 0;

    /** Get value of PGood */
    virtual bool pGood() const;
    /** Set value of PGood with option to skip sending signal */
    virtual bool pGood(bool value, bool skipSignal);
    /** Set value of PGood */
    virtual bool pGood(bool value);
    /** Get value of State */
    virtual int32_t state() const;
    /** Set value of State with option to skip sending signal */
    virtual int32_t state(int32_t value, bool skipSignal);
    /** Set value of State */
    virtual int32_t state(int32_t value);

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
    /** @brief sd-bus callback for forcePowerOff
     */
    static int _callback_ForcePowerOff(sd_bus_message*, void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'PGood' */
    static int _callback_get_PGood(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'PGood' */
    static int _callback_set_PGood(sd_bus*, const char*, const char*,
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

    static constexpr auto _interface =
        "xyz.openbmc_project.Chassis.Control.Power";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Chassis_Control_Power_interface;
    sdbusplus::SdBusInterface* _intf;

    bool _pGood = false;
    int32_t _state = 0;
};

} // namespace server
} // namespace Control
} // namespace Chassis
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
