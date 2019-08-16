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
namespace TPM
{
namespace server
{

class Policy
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
    Policy() = delete;
    Policy(const Policy&) = delete;
    Policy& operator=(const Policy&) = delete;
    Policy(Policy&&) = delete;
    Policy& operator=(Policy&&) = delete;
    virtual ~Policy() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Policy(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<bool>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Policy(bus::bus& bus, const char* path,
           const std::map<std::string, PropertiesVariant>& vals,
           bool skipSignal = false);

    /** Get value of TPMEnable */
    virtual bool tPMEnable() const;
    /** Set value of TPMEnable with option to skip sending signal */
    virtual bool tPMEnable(bool value, bool skipSignal);
    /** Set value of TPMEnable */
    virtual bool tPMEnable(bool value);

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
    /** @brief sd-bus callback for get-property 'TPMEnable' */
    static int _callback_get_TPMEnable(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);
    /** @brief sd-bus callback for set-property 'TPMEnable' */
    static int _callback_set_TPMEnable(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Control.TPM.Policy";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Control_TPM_Policy_interface;
    sdbusplus::SdBusInterface* _intf;

    bool _tPMEnable{};
};

} // namespace server
} // namespace TPM
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus