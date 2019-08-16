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
namespace Power
{
namespace server
{

class ACPIPowerState
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
    ACPIPowerState() = delete;
    ACPIPowerState(const ACPIPowerState&) = delete;
    ACPIPowerState& operator=(const ACPIPowerState&) = delete;
    ACPIPowerState(ACPIPowerState&&) = delete;
    ACPIPowerState& operator=(ACPIPowerState&&) = delete;
    virtual ~ACPIPowerState() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    ACPIPowerState(bus::bus& bus, const char* path);

    enum class ACPI
    {
        S0_G0_D0,
        S1_D1,
        S2_D2,
        S3_D3,
        S4,
        S5_G2,
        S4_S5,
        G3,
        SLEEP,
        G1_SLEEP,
        OVERRIDE,
        LEGACY_ON,
        LEGACY_OFF,
        Unknown,
    };

    using PropertiesVariant = std::variant<ACPI>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    ACPIPowerState(bus::bus& bus, const char* path,
                   const std::map<std::string, PropertiesVariant>& vals,
                   bool skipSignal = false);

    /** Get value of SysACPIStatus */
    virtual ACPI sysACPIStatus() const;
    /** Set value of SysACPIStatus with option to skip sending signal */
    virtual ACPI sysACPIStatus(ACPI value, bool skipSignal);
    /** Set value of SysACPIStatus */
    virtual ACPI sysACPIStatus(ACPI value);
    /** Get value of DevACPIStatus */
    virtual ACPI devACPIStatus() const;
    /** Set value of DevACPIStatus with option to skip sending signal */
    virtual ACPI devACPIStatus(ACPI value, bool skipSignal);
    /** Set value of DevACPIStatus */
    virtual ACPI devACPIStatus(ACPI value);

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

    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Control.Power.ACPIPowerState.<value
     * name>"
     *  @return - The enum value.
     */
    static ACPI convertACPIFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'SysACPIStatus' */
    static int _callback_get_SysACPIStatus(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'SysACPIStatus' */
    static int _callback_set_SysACPIStatus(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'DevACPIStatus' */
    static int _callback_get_DevACPIStatus(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DevACPIStatus' */
    static int _callback_set_DevACPIStatus(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Control.Power.ACPIPowerState";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Control_Power_ACPIPowerState_interface;
    sdbusplus::SdBusInterface* _intf;

    ACPI _sysACPIStatus{};
    ACPI _devACPIStatus{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type ACPIPowerState::ACPI.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(ACPIPowerState::ACPI e);

} // namespace server
} // namespace Power
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
