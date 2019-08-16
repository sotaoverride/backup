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
namespace server
{

class Manager
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
    Manager() = delete;
    Manager(const Manager&) = delete;
    Manager& operator=(const Manager&) = delete;
    Manager(Manager&&) = delete;
    Manager& operator=(Manager&&) = delete;
    virtual ~Manager() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Manager(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<std::vector<std::string>>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Manager(bus::bus& bus, const char* path,
            const std::map<std::string, PropertiesVariant>& vals,
            bool skipSignal = false);

    /** @brief Implementation for CreateUser
     *  Creates a new user. If the user already exists, then it will throw an
     * error.
     *
     *  @param[in] userName - User name which has to be created.
     *  @param[in] groupNames - List of groups to which the user has to be
     * added.
     *  @param[in] privilege - Privilege of the user to be added.
     *  @param[in] enabled - User enabled / disabled.
     */
    virtual void createUser(std::string userName,
                            std::vector<std::string> groupNames,
                            std::string privilege, bool enabled) = 0;

    /** @brief Implementation for RenameUser
     *  Rename's existing user to new one. All other properties of the user will
     * remain same.
     *
     *  @param[in] userName - User name which has to be updated.
     *  @param[in] newUserName - New User name to which user has to be updated.
     */
    virtual void renameUser(std::string userName, std::string newUserName) = 0;

    /** @brief Implementation for GetUserInfo
     *  Get user properites. If its local user, method returns
-user privilege
-user groups
-user enabled state
-user locked state
-remote user flag
If its ldap user, method returns
-user privilege
-remote user flag
     *
     *  @param[in] userName - User name whose properties have to be returned.
     *
     *  @return userInfo[std::map<std::string, std::variant<std::string,
std::vector<std::string>, bool>>] - Dictionary of user properties. List of key
name and data type of properties below. UserPrivilege -> privilege of the
user(string) UserGroups    -> list of groups user belongs to(array[string])
UserEnabled   -> user enabled state(boolean) UserLockedForFailedAttempt -> user
locked state(boolean) RemoteUser    ->  remote or local user(boolean) For
detailed documentation of user properties refer Attributes.interface.yaml
examples: 1.UserInfo["RemoteUser"] returns true for ldap user and false for
local user. 2.UserInfo["UserGroups"] gets list of groups of user.
     */
    virtual std::map<std::string,
                     std::variant<std::string, std::vector<std::string>, bool>>
        getUserInfo(std::string userName) = 0;

    /** @brief Send signal 'UserRenamed'
     *
     *  Signal indicating user's name is updated.
     *
     *  @param[in] userName - Name of the user which got renamed.
     *  @param[in] newUserName - New name of the user.
     */
    void userRenamed(std::string userName, std::string newUserName);

    /** Get value of AllPrivileges */
    virtual std::vector<std::string> allPrivileges() const;
    /** Set value of AllPrivileges with option to skip sending signal */
    virtual std::vector<std::string>
        allPrivileges(std::vector<std::string> value, bool skipSignal);
    /** Set value of AllPrivileges */
    virtual std::vector<std::string>
        allPrivileges(std::vector<std::string> value);
    /** Get value of AllGroups */
    virtual std::vector<std::string> allGroups() const;
    /** Set value of AllGroups with option to skip sending signal */
    virtual std::vector<std::string> allGroups(std::vector<std::string> value,
                                               bool skipSignal);
    /** Set value of AllGroups */
    virtual std::vector<std::string> allGroups(std::vector<std::string> value);

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
    /** @brief sd-bus callback for CreateUser
     */
    static int _callback_CreateUser(sd_bus_message*, void*, sd_bus_error*);

    /** @brief sd-bus callback for RenameUser
     */
    static int _callback_RenameUser(sd_bus_message*, void*, sd_bus_error*);

    /** @brief sd-bus callback for GetUserInfo
     */
    static int _callback_GetUserInfo(sd_bus_message*, void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'AllPrivileges' */
    static int _callback_get_AllPrivileges(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'AllPrivileges' */
    static int _callback_set_AllPrivileges(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'AllGroups' */
    static int _callback_get_AllGroups(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);
    /** @brief sd-bus callback for set-property 'AllGroups' */
    static int _callback_set_AllGroups(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.User.Manager";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_User_Manager_interface;
    sdbusplus::SdBusInterface* _intf;

    std::vector<std::string> _allPrivileges{};
    std::vector<std::string> _allGroups{};
};

} // namespace server
} // namespace User
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
