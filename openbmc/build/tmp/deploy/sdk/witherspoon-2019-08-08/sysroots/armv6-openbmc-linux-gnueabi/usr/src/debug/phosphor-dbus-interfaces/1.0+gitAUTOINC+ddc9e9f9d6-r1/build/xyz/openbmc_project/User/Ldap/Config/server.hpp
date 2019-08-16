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
namespace User
{
namespace Ldap
{
namespace server
{

class Config
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
    Config() = delete;
    Config(const Config&) = delete;
    Config& operator=(const Config&) = delete;
    Config(Config&&) = delete;
    Config& operator=(Config&&) = delete;
    virtual ~Config() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Config(bus::bus& bus, const char* path);

    enum class SearchScope
    {
        sub,
        one,
        base,
    };
    enum class Type
    {
        ActiveDirectory,
        OpenLdap,
    };

    using PropertiesVariant = std::variant<SearchScope, Type, std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Config(bus::bus& bus, const char* path,
           const std::map<std::string, PropertiesVariant>& vals,
           bool skipSignal = false);

    /** Get value of LDAPServerURI */
    virtual std::string lDAPServerURI() const;
    /** Set value of LDAPServerURI with option to skip sending signal */
    virtual std::string lDAPServerURI(std::string value, bool skipSignal);
    /** Set value of LDAPServerURI */
    virtual std::string lDAPServerURI(std::string value);
    /** Get value of LDAPBindDN */
    virtual std::string lDAPBindDN() const;
    /** Set value of LDAPBindDN with option to skip sending signal */
    virtual std::string lDAPBindDN(std::string value, bool skipSignal);
    /** Set value of LDAPBindDN */
    virtual std::string lDAPBindDN(std::string value);
    /** Get value of LDAPBindDNPassword */
    virtual std::string lDAPBindDNPassword() const;
    /** Set value of LDAPBindDNPassword with option to skip sending signal */
    virtual std::string lDAPBindDNPassword(std::string value, bool skipSignal);
    /** Set value of LDAPBindDNPassword */
    virtual std::string lDAPBindDNPassword(std::string value);
    /** Get value of LDAPBaseDN */
    virtual std::string lDAPBaseDN() const;
    /** Set value of LDAPBaseDN with option to skip sending signal */
    virtual std::string lDAPBaseDN(std::string value, bool skipSignal);
    /** Set value of LDAPBaseDN */
    virtual std::string lDAPBaseDN(std::string value);
    /** Get value of LDAPSearchScope */
    virtual SearchScope lDAPSearchScope() const;
    /** Set value of LDAPSearchScope with option to skip sending signal */
    virtual SearchScope lDAPSearchScope(SearchScope value, bool skipSignal);
    /** Set value of LDAPSearchScope */
    virtual SearchScope lDAPSearchScope(SearchScope value);
    /** Get value of LDAPType */
    virtual Type lDAPType() const;
    /** Set value of LDAPType with option to skip sending signal */
    virtual Type lDAPType(Type value, bool skipSignal);
    /** Set value of LDAPType */
    virtual Type lDAPType(Type value);
    /** Get value of GroupNameAttribute */
    virtual std::string groupNameAttribute() const;
    /** Set value of GroupNameAttribute with option to skip sending signal */
    virtual std::string groupNameAttribute(std::string value, bool skipSignal);
    /** Set value of GroupNameAttribute */
    virtual std::string groupNameAttribute(std::string value);
    /** Get value of UserNameAttribute */
    virtual std::string userNameAttribute() const;
    /** Set value of UserNameAttribute with option to skip sending signal */
    virtual std::string userNameAttribute(std::string value, bool skipSignal);
    /** Set value of UserNameAttribute */
    virtual std::string userNameAttribute(std::string value);

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
     *                 "xyz.openbmc_project.User.Ldap.Config.<value name>"
     *  @return - The enum value.
     */
    static SearchScope convertSearchScopeFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.User.Ldap.Config.<value name>"
     *  @return - The enum value.
     */
    static Type convertTypeFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'LDAPServerURI' */
    static int _callback_get_LDAPServerURI(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'LDAPServerURI' */
    static int _callback_set_LDAPServerURI(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'LDAPBindDN' */
    static int _callback_get_LDAPBindDN(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'LDAPBindDN' */
    static int _callback_set_LDAPBindDN(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'LDAPBindDNPassword' */
    static int _callback_get_LDAPBindDNPassword(sd_bus*, const char*,
                                                const char*, const char*,
                                                sd_bus_message*, void*,
                                                sd_bus_error*);
    /** @brief sd-bus callback for set-property 'LDAPBindDNPassword' */
    static int _callback_set_LDAPBindDNPassword(sd_bus*, const char*,
                                                const char*, const char*,
                                                sd_bus_message*, void*,
                                                sd_bus_error*);

    /** @brief sd-bus callback for get-property 'LDAPBaseDN' */
    static int _callback_get_LDAPBaseDN(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'LDAPBaseDN' */
    static int _callback_set_LDAPBaseDN(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'LDAPSearchScope' */
    static int _callback_get_LDAPSearchScope(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'LDAPSearchScope' */
    static int _callback_set_LDAPSearchScope(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'LDAPType' */
    static int _callback_get_LDAPType(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);
    /** @brief sd-bus callback for set-property 'LDAPType' */
    static int _callback_set_LDAPType(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);

    /** @brief sd-bus callback for get-property 'GroupNameAttribute' */
    static int _callback_get_GroupNameAttribute(sd_bus*, const char*,
                                                const char*, const char*,
                                                sd_bus_message*, void*,
                                                sd_bus_error*);
    /** @brief sd-bus callback for set-property 'GroupNameAttribute' */
    static int _callback_set_GroupNameAttribute(sd_bus*, const char*,
                                                const char*, const char*,
                                                sd_bus_message*, void*,
                                                sd_bus_error*);

    /** @brief sd-bus callback for get-property 'UserNameAttribute' */
    static int _callback_get_UserNameAttribute(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);
    /** @brief sd-bus callback for set-property 'UserNameAttribute' */
    static int _callback_set_UserNameAttribute(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.User.Ldap.Config";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_User_Ldap_Config_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _lDAPServerURI{};
    std::string _lDAPBindDN{};
    std::string _lDAPBindDNPassword{};
    std::string _lDAPBaseDN{};
    SearchScope _lDAPSearchScope = SearchScope::sub;
    Type _lDAPType{};
    std::string _groupNameAttribute{};
    std::string _userNameAttribute{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Config::SearchScope.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Config::SearchScope e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Config::Type.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Config::Type e);

} // namespace server
} // namespace Ldap
} // namespace User
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
