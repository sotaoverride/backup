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
namespace Control
{
namespace server
{

class ChassisCapabilities
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
        ChassisCapabilities() = delete;
        ChassisCapabilities(const ChassisCapabilities&) = delete;
        ChassisCapabilities& operator=(const ChassisCapabilities&) = delete;
        ChassisCapabilities(ChassisCapabilities&&) = delete;
        ChassisCapabilities& operator=(ChassisCapabilities&&) = delete;
        virtual ~ChassisCapabilities() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        ChassisCapabilities(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                uint8_t>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        ChassisCapabilities(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of CapabilitiesFlags */
        virtual uint8_t capabilitiesFlags() const;
        /** Set value of CapabilitiesFlags with option to skip sending signal */
        virtual uint8_t capabilitiesFlags(uint8_t value,
               bool skipSignal);
        /** Set value of CapabilitiesFlags */
        virtual uint8_t capabilitiesFlags(uint8_t value);
        /** Get value of FRUDeviceAddress */
        virtual uint8_t fRUDeviceAddress() const;
        /** Set value of FRUDeviceAddress with option to skip sending signal */
        virtual uint8_t fRUDeviceAddress(uint8_t value,
               bool skipSignal);
        /** Set value of FRUDeviceAddress */
        virtual uint8_t fRUDeviceAddress(uint8_t value);
        /** Get value of SDRDeviceAddress */
        virtual uint8_t sDRDeviceAddress() const;
        /** Set value of SDRDeviceAddress with option to skip sending signal */
        virtual uint8_t sDRDeviceAddress(uint8_t value,
               bool skipSignal);
        /** Set value of SDRDeviceAddress */
        virtual uint8_t sDRDeviceAddress(uint8_t value);
        /** Get value of SELDeviceAddress */
        virtual uint8_t sELDeviceAddress() const;
        /** Set value of SELDeviceAddress with option to skip sending signal */
        virtual uint8_t sELDeviceAddress(uint8_t value,
               bool skipSignal);
        /** Set value of SELDeviceAddress */
        virtual uint8_t sELDeviceAddress(uint8_t value);
        /** Get value of SMDeviceAddress */
        virtual uint8_t sMDeviceAddress() const;
        /** Set value of SMDeviceAddress with option to skip sending signal */
        virtual uint8_t sMDeviceAddress(uint8_t value,
               bool skipSignal);
        /** Set value of SMDeviceAddress */
        virtual uint8_t sMDeviceAddress(uint8_t value);
        /** Get value of BridgeDeviceAddress */
        virtual uint8_t bridgeDeviceAddress() const;
        /** Set value of BridgeDeviceAddress with option to skip sending signal */
        virtual uint8_t bridgeDeviceAddress(uint8_t value,
               bool skipSignal);
        /** Set value of BridgeDeviceAddress */
        virtual uint8_t bridgeDeviceAddress(uint8_t value);

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

        /** @brief sd-bus callback for get-property 'CapabilitiesFlags' */
        static int _callback_get_CapabilitiesFlags(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'CapabilitiesFlags' */
        static int _callback_set_CapabilitiesFlags(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'FRUDeviceAddress' */
        static int _callback_get_FRUDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'FRUDeviceAddress' */
        static int _callback_set_FRUDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'SDRDeviceAddress' */
        static int _callback_get_SDRDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'SDRDeviceAddress' */
        static int _callback_set_SDRDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'SELDeviceAddress' */
        static int _callback_get_SELDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'SELDeviceAddress' */
        static int _callback_set_SELDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'SMDeviceAddress' */
        static int _callback_get_SMDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'SMDeviceAddress' */
        static int _callback_set_SMDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'BridgeDeviceAddress' */
        static int _callback_get_BridgeDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'BridgeDeviceAddress' */
        static int _callback_set_BridgeDeviceAddress(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Control.ChassisCapabilities";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Control_ChassisCapabilities_interface;
        sdbusplus::SdBusInterface *_intf;

        uint8_t _capabilitiesFlags{};
        uint8_t _fRUDeviceAddress{};
        uint8_t _sDRDeviceAddress{};
        uint8_t _sELDeviceAddress{};
        uint8_t _sMDeviceAddress{};
        uint8_t _bridgeDeviceAddress{};

};


} // namespace server
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

