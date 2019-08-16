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
namespace server
{

class PowerSupplyAttributes
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
    PowerSupplyAttributes() = delete;
    PowerSupplyAttributes(const PowerSupplyAttributes&) = delete;
    PowerSupplyAttributes& operator=(const PowerSupplyAttributes&) = delete;
    PowerSupplyAttributes(PowerSupplyAttributes&&) = delete;
    PowerSupplyAttributes& operator=(PowerSupplyAttributes&&) = delete;
    virtual ~PowerSupplyAttributes() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    PowerSupplyAttributes(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<uint32_t>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    PowerSupplyAttributes(bus::bus& bus, const char* path,
                          const std::map<std::string, PropertiesVariant>& vals,
                          bool skipSignal = false);

    /** Get value of DeratingFactor */
    virtual uint32_t deratingFactor() const;
    /** Set value of DeratingFactor with option to skip sending signal */
    virtual uint32_t deratingFactor(uint32_t value, bool skipSignal);
    /** Set value of DeratingFactor */
    virtual uint32_t deratingFactor(uint32_t value);

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
    /** @brief sd-bus callback for get-property 'DeratingFactor' */
    static int _callback_get_DeratingFactor(sd_bus*, const char*, const char*,
                                            const char*, sd_bus_message*, void*,
                                            sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DeratingFactor' */
    static int _callback_set_DeratingFactor(sd_bus*, const char*, const char*,
                                            const char*, sd_bus_message*, void*,
                                            sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Control.PowerSupplyAttributes";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Control_PowerSupplyAttributes_interface;
    sdbusplus::SdBusInterface* _intf;

    uint32_t _deratingFactor{};
};

} // namespace server
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
