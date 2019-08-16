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
namespace Item
{
namespace server
{

class Chassis
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
    Chassis() = delete;
    Chassis(const Chassis&) = delete;
    Chassis& operator=(const Chassis&) = delete;
    Chassis(Chassis&&) = delete;
    Chassis& operator=(Chassis&&) = delete;
    virtual ~Chassis() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Chassis(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Chassis(bus::bus& bus, const char* path,
            const std::map<std::string, PropertiesVariant>& vals,
            bool skipSignal = false);

    /** Get value of Type */
    virtual std::string type() const;
    /** Set value of Type with option to skip sending signal */
    virtual std::string type(std::string value, bool skipSignal);
    /** Set value of Type */
    virtual std::string type(std::string value);

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
    /** @brief sd-bus callback for get-property 'Type' */
    static int _callback_get_Type(sd_bus*, const char*, const char*,
                                  const char*, sd_bus_message*, void*,
                                  sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Type' */
    static int _callback_set_Type(sd_bus*, const char*, const char*,
                                  const char*, sd_bus_message*, void*,
                                  sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Inventory.Item.Chassis";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Inventory_Item_Chassis_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _type{};
};

} // namespace server
} // namespace Item
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
