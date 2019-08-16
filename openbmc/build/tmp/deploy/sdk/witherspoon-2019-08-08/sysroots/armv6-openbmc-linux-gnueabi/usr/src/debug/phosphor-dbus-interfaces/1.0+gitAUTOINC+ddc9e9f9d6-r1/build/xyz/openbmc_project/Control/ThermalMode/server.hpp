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

class ThermalMode
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
    ThermalMode() = delete;
    ThermalMode(const ThermalMode&) = delete;
    ThermalMode& operator=(const ThermalMode&) = delete;
    ThermalMode(ThermalMode&&) = delete;
    ThermalMode& operator=(ThermalMode&&) = delete;
    virtual ~ThermalMode() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    ThermalMode(bus::bus& bus, const char* path);

    using PropertiesVariant =
        std::variant<std::vector<std::string>, std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    ThermalMode(bus::bus& bus, const char* path,
                const std::map<std::string, PropertiesVariant>& vals,
                bool skipSignal = false);

    /** Get value of Supported */
    virtual std::vector<std::string> supported() const;
    /** Set value of Supported with option to skip sending signal */
    virtual std::vector<std::string> supported(std::vector<std::string> value,
                                               bool skipSignal);
    /** Set value of Supported */
    virtual std::vector<std::string> supported(std::vector<std::string> value);
    /** Get value of Current */
    virtual std::string current() const;
    /** Set value of Current with option to skip sending signal */
    virtual std::string current(std::string value, bool skipSignal);
    /** Set value of Current */
    virtual std::string current(std::string value);

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
    /** @brief sd-bus callback for get-property 'Supported' */
    static int _callback_get_Supported(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Supported' */
    static int _callback_set_Supported(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Current' */
    static int _callback_get_Current(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Current' */
    static int _callback_set_Current(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Control.ThermalMode";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Control_ThermalMode_interface;
    sdbusplus::SdBusInterface* _intf;

    std::vector<std::string> _supported{};
    std::string _current = "Default";
};

} // namespace server
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
