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

class PowerOnHours
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
    PowerOnHours() = delete;
    PowerOnHours(const PowerOnHours&) = delete;
    PowerOnHours& operator=(const PowerOnHours&) = delete;
    PowerOnHours(PowerOnHours&&) = delete;
    PowerOnHours& operator=(PowerOnHours&&) = delete;
    virtual ~PowerOnHours() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    PowerOnHours(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<uint32_t>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    PowerOnHours(bus::bus& bus, const char* path,
                 const std::map<std::string, PropertiesVariant>& vals,
                 bool skipSignal = false);

    /** Get value of POHCounter */
    virtual uint32_t pOHCounter() const;
    /** Set value of POHCounter with option to skip sending signal */
    virtual uint32_t pOHCounter(uint32_t value, bool skipSignal);
    /** Set value of POHCounter */
    virtual uint32_t pOHCounter(uint32_t value);

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
    /** @brief sd-bus callback for get-property 'POHCounter' */
    static int _callback_get_POHCounter(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'POHCounter' */
    static int _callback_set_POHCounter(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.State.PowerOnHours";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_State_PowerOnHours_interface;
    sdbusplus::SdBusInterface* _intf;

    uint32_t _pOHCounter{};
};

} // namespace server
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
