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

class Attributes
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
    Attributes() = delete;
    Attributes(const Attributes&) = delete;
    Attributes& operator=(const Attributes&) = delete;
    Attributes(Attributes&&) = delete;
    Attributes& operator=(Attributes&&) = delete;
    virtual ~Attributes() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Attributes(bus::bus& bus, const char* path);

    using PropertiesVariant =
        std::variant<bool, std::vector<std::string>, std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Attributes(bus::bus& bus, const char* path,
               const std::map<std::string, PropertiesVariant>& vals,
               bool skipSignal = false);

    /** Get value of UserGroups */
    virtual std::vector<std::string> userGroups() const;
    /** Set value of UserGroups with option to skip sending signal */
    virtual std::vector<std::string> userGroups(std::vector<std::string> value,
                                                bool skipSignal);
    /** Set value of UserGroups */
    virtual std::vector<std::string> userGroups(std::vector<std::string> value);
    /** Get value of UserPrivilege */
    virtual std::string userPrivilege() const;
    /** Set value of UserPrivilege with option to skip sending signal */
    virtual std::string userPrivilege(std::string value, bool skipSignal);
    /** Set value of UserPrivilege */
    virtual std::string userPrivilege(std::string value);
    /** Get value of UserEnabled */
    virtual bool userEnabled() const;
    /** Set value of UserEnabled with option to skip sending signal */
    virtual bool userEnabled(bool value, bool skipSignal);
    /** Set value of UserEnabled */
    virtual bool userEnabled(bool value);
    /** Get value of UserLockedForFailedAttempt */
    virtual bool userLockedForFailedAttempt() const;
    /** Set value of UserLockedForFailedAttempt with option to skip sending
     * signal */
    virtual bool userLockedForFailedAttempt(bool value, bool skipSignal);
    /** Set value of UserLockedForFailedAttempt */
    virtual bool userLockedForFailedAttempt(bool value);

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
    /** @brief sd-bus callback for get-property 'UserGroups' */
    static int _callback_get_UserGroups(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'UserGroups' */
    static int _callback_set_UserGroups(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'UserPrivilege' */
    static int _callback_get_UserPrivilege(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'UserPrivilege' */
    static int _callback_set_UserPrivilege(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'UserEnabled' */
    static int _callback_get_UserEnabled(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);
    /** @brief sd-bus callback for set-property 'UserEnabled' */
    static int _callback_set_UserEnabled(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);

    /** @brief sd-bus callback for get-property 'UserLockedForFailedAttempt' */
    static int _callback_get_UserLockedForFailedAttempt(sd_bus*, const char*,
                                                        const char*,
                                                        const char*,
                                                        sd_bus_message*, void*,
                                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'UserLockedForFailedAttempt' */
    static int _callback_set_UserLockedForFailedAttempt(sd_bus*, const char*,
                                                        const char*,
                                                        const char*,
                                                        sd_bus_message*, void*,
                                                        sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.User.Attributes";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_User_Attributes_interface;
    sdbusplus::SdBusInterface* _intf;

    std::vector<std::string> _userGroups{};
    std::string _userPrivilege{};
    bool _userEnabled{};
    bool _userLockedForFailedAttempt{};
};

} // namespace server
} // namespace User
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
