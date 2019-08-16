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
namespace Inventory
{
namespace Decorator
{
namespace server
{

class CoolingType
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
    CoolingType() = delete;
    CoolingType(const CoolingType&) = delete;
    CoolingType& operator=(const CoolingType&) = delete;
    CoolingType(CoolingType&&) = delete;
    CoolingType& operator=(CoolingType&&) = delete;
    virtual ~CoolingType() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    CoolingType(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<bool>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    CoolingType(bus::bus& bus, const char* path,
                const std::map<std::string, PropertiesVariant>& vals,
                bool skipSignal = false);

    /** Get value of AirCooled */
    virtual bool airCooled() const;
    /** Set value of AirCooled with option to skip sending signal */
    virtual bool airCooled(bool value, bool skipSignal);
    /** Set value of AirCooled */
    virtual bool airCooled(bool value);
    /** Get value of WaterCooled */
    virtual bool waterCooled() const;
    /** Set value of WaterCooled with option to skip sending signal */
    virtual bool waterCooled(bool value, bool skipSignal);
    /** Set value of WaterCooled */
    virtual bool waterCooled(bool value);

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
    /** @brief sd-bus callback for get-property 'AirCooled' */
    static int _callback_get_AirCooled(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);
    /** @brief sd-bus callback for set-property 'AirCooled' */
    static int _callback_set_AirCooled(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);

    /** @brief sd-bus callback for get-property 'WaterCooled' */
    static int _callback_get_WaterCooled(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);
    /** @brief sd-bus callback for set-property 'WaterCooled' */
    static int _callback_set_WaterCooled(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Inventory.Decorator.CoolingType";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Inventory_Decorator_CoolingType_interface;
    sdbusplus::SdBusInterface* _intf;

    bool _airCooled{};
    bool _waterCooled{};
};

} // namespace server
} // namespace Decorator
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus