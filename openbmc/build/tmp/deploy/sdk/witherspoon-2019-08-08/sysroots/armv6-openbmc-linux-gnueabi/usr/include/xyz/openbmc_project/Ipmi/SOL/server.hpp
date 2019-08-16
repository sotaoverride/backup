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
namespace Ipmi
{
namespace server
{

class SOL
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
        SOL() = delete;
        SOL(const SOL&) = delete;
        SOL& operator=(const SOL&) = delete;
        SOL(SOL&&) = delete;
        SOL& operator=(SOL&&) = delete;
        virtual ~SOL() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        SOL(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                bool,
                uint8_t>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        SOL(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of Progress */
        virtual uint8_t progress() const;
        /** Set value of Progress with option to skip sending signal */
        virtual uint8_t progress(uint8_t value,
               bool skipSignal);
        /** Set value of Progress */
        virtual uint8_t progress(uint8_t value);
        /** Get value of Enable */
        virtual bool enable() const;
        /** Set value of Enable with option to skip sending signal */
        virtual bool enable(bool value,
               bool skipSignal);
        /** Set value of Enable */
        virtual bool enable(bool value);
        /** Get value of ForceEncryption */
        virtual bool forceEncryption() const;
        /** Set value of ForceEncryption with option to skip sending signal */
        virtual bool forceEncryption(bool value,
               bool skipSignal);
        /** Set value of ForceEncryption */
        virtual bool forceEncryption(bool value);
        /** Get value of ForceAuthentication */
        virtual bool forceAuthentication() const;
        /** Set value of ForceAuthentication with option to skip sending signal */
        virtual bool forceAuthentication(bool value,
               bool skipSignal);
        /** Set value of ForceAuthentication */
        virtual bool forceAuthentication(bool value);
        /** Get value of Privilege */
        virtual uint8_t privilege() const;
        /** Set value of Privilege with option to skip sending signal */
        virtual uint8_t privilege(uint8_t value,
               bool skipSignal);
        /** Set value of Privilege */
        virtual uint8_t privilege(uint8_t value);
        /** Get value of AccumulateIntervalMS */
        virtual uint8_t accumulateIntervalMS() const;
        /** Set value of AccumulateIntervalMS with option to skip sending signal */
        virtual uint8_t accumulateIntervalMS(uint8_t value,
               bool skipSignal);
        /** Set value of AccumulateIntervalMS */
        virtual uint8_t accumulateIntervalMS(uint8_t value);
        /** Get value of Threshold */
        virtual uint8_t threshold() const;
        /** Set value of Threshold with option to skip sending signal */
        virtual uint8_t threshold(uint8_t value,
               bool skipSignal);
        /** Set value of Threshold */
        virtual uint8_t threshold(uint8_t value);
        /** Get value of RetryCount */
        virtual uint8_t retryCount() const;
        /** Set value of RetryCount with option to skip sending signal */
        virtual uint8_t retryCount(uint8_t value,
               bool skipSignal);
        /** Set value of RetryCount */
        virtual uint8_t retryCount(uint8_t value);
        /** Get value of RetryIntervalMS */
        virtual uint8_t retryIntervalMS() const;
        /** Set value of RetryIntervalMS with option to skip sending signal */
        virtual uint8_t retryIntervalMS(uint8_t value,
               bool skipSignal);
        /** Set value of RetryIntervalMS */
        virtual uint8_t retryIntervalMS(uint8_t value);

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

        /** @brief sd-bus callback for get-property 'Progress' */
        static int _callback_get_Progress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Progress' */
        static int _callback_set_Progress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Enable' */
        static int _callback_get_Enable(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Enable' */
        static int _callback_set_Enable(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'ForceEncryption' */
        static int _callback_get_ForceEncryption(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'ForceEncryption' */
        static int _callback_set_ForceEncryption(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'ForceAuthentication' */
        static int _callback_get_ForceAuthentication(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'ForceAuthentication' */
        static int _callback_set_ForceAuthentication(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Privilege' */
        static int _callback_get_Privilege(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Privilege' */
        static int _callback_set_Privilege(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'AccumulateIntervalMS' */
        static int _callback_get_AccumulateIntervalMS(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'AccumulateIntervalMS' */
        static int _callback_set_AccumulateIntervalMS(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Threshold' */
        static int _callback_get_Threshold(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Threshold' */
        static int _callback_set_Threshold(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'RetryCount' */
        static int _callback_get_RetryCount(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'RetryCount' */
        static int _callback_set_RetryCount(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'RetryIntervalMS' */
        static int _callback_get_RetryIntervalMS(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'RetryIntervalMS' */
        static int _callback_set_RetryIntervalMS(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Ipmi.SOL";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Ipmi_SOL_interface;
        sdbusplus::SdBusInterface *_intf;

        uint8_t _progress{};
        bool _enable{};
        bool _forceEncryption{};
        bool _forceAuthentication{};
        uint8_t _privilege{};
        uint8_t _accumulateIntervalMS{};
        uint8_t _threshold{};
        uint8_t _retryCount{};
        uint8_t _retryIntervalMS{};

};


} // namespace server
} // namespace Ipmi
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

