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

class Asset
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
    Asset() = delete;
    Asset(const Asset&) = delete;
    Asset& operator=(const Asset&) = delete;
    Asset(Asset&&) = delete;
    Asset& operator=(Asset&&) = delete;
    virtual ~Asset() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Asset(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Asset(bus::bus& bus, const char* path,
          const std::map<std::string, PropertiesVariant>& vals,
          bool skipSignal = false);

    /** Get value of PartNumber */
    virtual std::string partNumber() const;
    /** Set value of PartNumber with option to skip sending signal */
    virtual std::string partNumber(std::string value, bool skipSignal);
    /** Set value of PartNumber */
    virtual std::string partNumber(std::string value);
    /** Get value of SerialNumber */
    virtual std::string serialNumber() const;
    /** Set value of SerialNumber with option to skip sending signal */
    virtual std::string serialNumber(std::string value, bool skipSignal);
    /** Set value of SerialNumber */
    virtual std::string serialNumber(std::string value);
    /** Get value of Manufacturer */
    virtual std::string manufacturer() const;
    /** Set value of Manufacturer with option to skip sending signal */
    virtual std::string manufacturer(std::string value, bool skipSignal);
    /** Set value of Manufacturer */
    virtual std::string manufacturer(std::string value);
    /** Get value of BuildDate */
    virtual std::string buildDate() const;
    /** Set value of BuildDate with option to skip sending signal */
    virtual std::string buildDate(std::string value, bool skipSignal);
    /** Set value of BuildDate */
    virtual std::string buildDate(std::string value);
    /** Get value of Model */
    virtual std::string model() const;
    /** Set value of Model with option to skip sending signal */
    virtual std::string model(std::string value, bool skipSignal);
    /** Set value of Model */
    virtual std::string model(std::string value);

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
    /** @brief sd-bus callback for get-property 'PartNumber' */
    static int _callback_get_PartNumber(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'PartNumber' */
    static int _callback_set_PartNumber(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'SerialNumber' */
    static int _callback_get_SerialNumber(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'SerialNumber' */
    static int _callback_set_SerialNumber(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Manufacturer' */
    static int _callback_get_Manufacturer(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Manufacturer' */
    static int _callback_set_Manufacturer(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    /** @brief sd-bus callback for get-property 'BuildDate' */
    static int _callback_get_BuildDate(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);
    /** @brief sd-bus callback for set-property 'BuildDate' */
    static int _callback_set_BuildDate(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Model' */
    static int _callback_get_Model(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Model' */
    static int _callback_set_Model(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Inventory.Decorator.Asset";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Inventory_Decorator_Asset_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _partNumber{};
    std::string _serialNumber{};
    std::string _manufacturer{};
    std::string _buildDate{};
    std::string _model{};
};

} // namespace server
} // namespace Decorator
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
