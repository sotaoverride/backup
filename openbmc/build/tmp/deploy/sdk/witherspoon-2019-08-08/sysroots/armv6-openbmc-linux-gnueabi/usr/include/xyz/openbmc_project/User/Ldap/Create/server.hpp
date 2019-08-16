#pragma once
#include <map>
#include <string>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <systemd/sd-bus.h>
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

class Create
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
        Create() = delete;
        Create(const Create&) = delete;
        Create& operator=(const Create&) = delete;
        Create(Create&&) = delete;
        Create& operator=(Create&&) = delete;
        virtual ~Create() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Create(bus::bus& bus, const char* path);

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


        /** @brief Implementation for CreateConfig
         *  This method always creates a new config file as well as a D-Bus  object to represent the config, it will destroy an existing one, if found. In other words, this is not an update API. Individual properties can be updated as per the xyz/openbmc_project/User/Ldap/Config.interface.yaml.
         *
         *  @param[in] lDAPServerURI - Specifies the LDAP URI of the server to connect to.
         *  @param[in] lDAPBindDN - Specifies the distinguished name with which to bind to the directory server for lookups.
         *  @param[in] lDAPBaseDN - Specifies the base distinguished name to use as search base.
         *  @param[in] lDAPBINDDNpassword - Specifies the clear text credentials with which to bind. This option is only applicable when used with LDAPBindDN.
         *  @param[in] lDAPSearchScope - Specifies the search scope:subtree, one level or base object.
         *  @param[in] lDAPType - Specifies the the configured server is ActiveDirectory(AD) or OpenLdap. It's just an indication for the LDAP stack running on the BMC, in case the app is implemented in such a way that it has to react differently for AD vs openldap.
         *  @param[in] groupNameAttribute - Specifies the attribute name that contains the name of the Group in the LDAP server.
         *  @param[in] usernameAttribute - Specifies the attribute name that contains the username in the LDAP server.
         *
         *  @return path[std::string] - The object path of the D-Bus object representing the config.
         */
        virtual std::string createConfig(
            std::string lDAPServerURI,
            std::string lDAPBindDN,
            std::string lDAPBaseDN,
            std::string lDAPBINDDNpassword,
            SearchScope lDAPSearchScope,
            Type lDAPType,
            std::string groupNameAttribute,
            std::string usernameAttribute) = 0;



    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.User.Ldap.Create.<value name>"
     *  @return - The enum value.
     */
    static SearchScope convertSearchScopeFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.User.Ldap.Create.<value name>"
     *  @return - The enum value.
     */
    static Type convertTypeFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for CreateConfig
         */
        static int _callback_CreateConfig(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.User.Ldap.Create";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_User_Ldap_Create_interface;
        sdbusplus::SdBusInterface *_intf;


};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Create::SearchScope.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Create::SearchScope e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Create::Type.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Create::Type e);

} // namespace server
} // namespace Ldap
} // namespace User
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

