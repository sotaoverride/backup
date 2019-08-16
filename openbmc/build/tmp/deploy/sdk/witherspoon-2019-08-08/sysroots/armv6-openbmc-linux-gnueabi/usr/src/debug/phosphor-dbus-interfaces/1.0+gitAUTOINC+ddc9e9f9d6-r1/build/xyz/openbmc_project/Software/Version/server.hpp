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
namespace Software
{
namespace server
{

class Version
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
    Version() = delete;
    Version(const Version&) = delete;
    Version& operator=(const Version&) = delete;
    Version(Version&&) = delete;
    Version& operator=(Version&&) = delete;
    virtual ~Version() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Version(bus::bus& bus, const char* path);

    enum class VersionPurpose
    {
        Unknown,
        Other,
        System,
        BMC,
        Host,
        PSU,
    };

    using PropertiesVariant = std::variant<VersionPurpose, std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Version(bus::bus& bus, const char* path,
            const std::map<std::string, PropertiesVariant>& vals,
            bool skipSignal = false);

    /** Get value of Version */
    virtual std::string version() const;
    /** Set value of Version with option to skip sending signal */
    virtual std::string version(std::string value, bool skipSignal);
    /** Set value of Version */
    virtual std::string version(std::string value);
    /** Get value of Purpose */
    virtual VersionPurpose purpose() const;
    /** Set value of Purpose with option to skip sending signal */
    virtual VersionPurpose purpose(VersionPurpose value, bool skipSignal);
    /** Set value of Purpose */
    virtual VersionPurpose purpose(VersionPurpose value);

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
     *                 "xyz.openbmc_project.Software.Version.<value name>"
     *  @return - The enum value.
     */
    static VersionPurpose convertVersionPurposeFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'Version' */
    static int _callback_get_Version(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Version' */
    static int _callback_set_Version(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Purpose' */
    static int _callback_get_Purpose(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Purpose' */
    static int _callback_set_Purpose(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Software.Version";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Software_Version_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _version{};
    VersionPurpose _purpose{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Version::VersionPurpose.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Version::VersionPurpose e);

} // namespace server
} // namespace Software
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
