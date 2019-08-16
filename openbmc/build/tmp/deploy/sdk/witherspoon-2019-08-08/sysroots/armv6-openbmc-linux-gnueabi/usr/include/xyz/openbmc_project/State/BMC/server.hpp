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
namespace State
{
namespace server
{

class BMC
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
        BMC() = delete;
        BMC(const BMC&) = delete;
        BMC& operator=(const BMC&) = delete;
        BMC(BMC&&) = delete;
        BMC& operator=(BMC&&) = delete;
        virtual ~BMC() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        BMC(bus::bus& bus, const char* path);

        enum class Transition
        {
            Reboot,
            None,
        };
        enum class BMCState
        {
            Ready,
            NotReady,
        };

        using PropertiesVariant = std::variant<
                uint64_t,
                BMCState,
                Transition>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        BMC(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of RequestedBMCTransition */
        virtual Transition requestedBMCTransition() const;
        /** Set value of RequestedBMCTransition with option to skip sending signal */
        virtual Transition requestedBMCTransition(Transition value,
               bool skipSignal);
        /** Set value of RequestedBMCTransition */
        virtual Transition requestedBMCTransition(Transition value);
        /** Get value of CurrentBMCState */
        virtual BMCState currentBMCState() const;
        /** Set value of CurrentBMCState with option to skip sending signal */
        virtual BMCState currentBMCState(BMCState value,
               bool skipSignal);
        /** Set value of CurrentBMCState */
        virtual BMCState currentBMCState(BMCState value);
        /** Get value of LastRebootTime */
        virtual uint64_t lastRebootTime() const;
        /** Set value of LastRebootTime with option to skip sending signal */
        virtual uint64_t lastRebootTime(uint64_t value,
               bool skipSignal);
        /** Set value of LastRebootTime */
        virtual uint64_t lastRebootTime(uint64_t value);

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
     *                 "xyz.openbmc_project.State.BMC.<value name>"
     *  @return - The enum value.
     */
    static Transition convertTransitionFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.State.BMC.<value name>"
     *  @return - The enum value.
     */
    static BMCState convertBMCStateFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for get-property 'RequestedBMCTransition' */
        static int _callback_get_RequestedBMCTransition(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'RequestedBMCTransition' */
        static int _callback_set_RequestedBMCTransition(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'CurrentBMCState' */
        static int _callback_get_CurrentBMCState(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'CurrentBMCState' */
        static int _callback_set_CurrentBMCState(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'LastRebootTime' */
        static int _callback_get_LastRebootTime(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'LastRebootTime' */
        static int _callback_set_LastRebootTime(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.State.BMC";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_State_BMC_interface;
        sdbusplus::SdBusInterface *_intf;

        Transition _requestedBMCTransition = Transition::None;
        BMCState _currentBMCState{};
        uint64_t _lastRebootTime{};

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type BMC::Transition.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(BMC::Transition e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type BMC::BMCState.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(BMC::BMCState e);

} // namespace server
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

