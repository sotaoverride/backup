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
namespace server
{

class AccountPolicy
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
        AccountPolicy() = delete;
        AccountPolicy(const AccountPolicy&) = delete;
        AccountPolicy& operator=(const AccountPolicy&) = delete;
        AccountPolicy(AccountPolicy&&) = delete;
        AccountPolicy& operator=(AccountPolicy&&) = delete;
        virtual ~AccountPolicy() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        AccountPolicy(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                uint16_t,
                uint8_t,
                uint32_t>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        AccountPolicy(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of MaxLoginAttemptBeforeLockout */
        virtual uint16_t maxLoginAttemptBeforeLockout() const;
        /** Set value of MaxLoginAttemptBeforeLockout with option to skip sending signal */
        virtual uint16_t maxLoginAttemptBeforeLockout(uint16_t value,
               bool skipSignal);
        /** Set value of MaxLoginAttemptBeforeLockout */
        virtual uint16_t maxLoginAttemptBeforeLockout(uint16_t value);
        /** Get value of AccountUnlockTimeout */
        virtual uint32_t accountUnlockTimeout() const;
        /** Set value of AccountUnlockTimeout with option to skip sending signal */
        virtual uint32_t accountUnlockTimeout(uint32_t value,
               bool skipSignal);
        /** Set value of AccountUnlockTimeout */
        virtual uint32_t accountUnlockTimeout(uint32_t value);
        /** Get value of MinPasswordLength */
        virtual uint8_t minPasswordLength() const;
        /** Set value of MinPasswordLength with option to skip sending signal */
        virtual uint8_t minPasswordLength(uint8_t value,
               bool skipSignal);
        /** Set value of MinPasswordLength */
        virtual uint8_t minPasswordLength(uint8_t value);
        /** Get value of RememberOldPasswordTimes */
        virtual uint8_t rememberOldPasswordTimes() const;
        /** Set value of RememberOldPasswordTimes with option to skip sending signal */
        virtual uint8_t rememberOldPasswordTimes(uint8_t value,
               bool skipSignal);
        /** Set value of RememberOldPasswordTimes */
        virtual uint8_t rememberOldPasswordTimes(uint8_t value);

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

        /** @brief sd-bus callback for get-property 'MaxLoginAttemptBeforeLockout' */
        static int _callback_get_MaxLoginAttemptBeforeLockout(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'MaxLoginAttemptBeforeLockout' */
        static int _callback_set_MaxLoginAttemptBeforeLockout(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'AccountUnlockTimeout' */
        static int _callback_get_AccountUnlockTimeout(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'AccountUnlockTimeout' */
        static int _callback_set_AccountUnlockTimeout(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'MinPasswordLength' */
        static int _callback_get_MinPasswordLength(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'MinPasswordLength' */
        static int _callback_set_MinPasswordLength(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'RememberOldPasswordTimes' */
        static int _callback_get_RememberOldPasswordTimes(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'RememberOldPasswordTimes' */
        static int _callback_set_RememberOldPasswordTimes(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.User.AccountPolicy";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_User_AccountPolicy_interface;
        sdbusplus::SdBusInterface *_intf;

        uint16_t _maxLoginAttemptBeforeLockout{};
        uint32_t _accountUnlockTimeout{};
        uint8_t _minPasswordLength{};
        uint8_t _rememberOldPasswordTimes{};

};


} // namespace server
} // namespace User
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

