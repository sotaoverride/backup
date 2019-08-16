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

class VendorInformation
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
    VendorInformation() = delete;
    VendorInformation(const VendorInformation&) = delete;
    VendorInformation& operator=(const VendorInformation&) = delete;
    VendorInformation(VendorInformation&&) = delete;
    VendorInformation& operator=(VendorInformation&&) = delete;
    virtual ~VendorInformation() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    VendorInformation(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    VendorInformation(bus::bus& bus, const char* path,
                      const std::map<std::string, PropertiesVariant>& vals,
                      bool skipSignal = false);

    /** Get value of CustomField1 */
    virtual std::string customField1() const;
    /** Set value of CustomField1 with option to skip sending signal */
    virtual std::string customField1(std::string value, bool skipSignal);
    /** Set value of CustomField1 */
    virtual std::string customField1(std::string value);
    /** Get value of CustomField2 */
    virtual std::string customField2() const;
    /** Set value of CustomField2 with option to skip sending signal */
    virtual std::string customField2(std::string value, bool skipSignal);
    /** Set value of CustomField2 */
    virtual std::string customField2(std::string value);

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
    /** @brief sd-bus callback for get-property 'CustomField1' */
    static int _callback_get_CustomField1(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CustomField1' */
    static int _callback_set_CustomField1(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    /** @brief sd-bus callback for get-property 'CustomField2' */
    static int _callback_get_CustomField2(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CustomField2' */
    static int _callback_set_CustomField2(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Inventory.Decorator.VendorInformation";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Inventory_Decorator_VendorInformation_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _customField1{};
    std::string _customField2{};
};

} // namespace server
} // namespace Decorator
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
