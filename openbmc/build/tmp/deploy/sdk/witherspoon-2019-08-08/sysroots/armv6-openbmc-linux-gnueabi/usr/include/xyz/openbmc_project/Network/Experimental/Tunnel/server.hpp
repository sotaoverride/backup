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
namespace Network
{
namespace Experimental
{
namespace server
{

class Tunnel
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
        Tunnel() = delete;
        Tunnel(const Tunnel&) = delete;
        Tunnel& operator=(const Tunnel&) = delete;
        Tunnel(Tunnel&&) = delete;
        Tunnel& operator=(Tunnel&&) = delete;
        virtual ~Tunnel() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Tunnel(bus::bus& bus, const char* path);

        enum class IPv6Tunnel
        {
            ip6ip6,
            ipip6,
            any,
        };

        using PropertiesVariant = std::variant<
                IPv6Tunnel,
                bool,
                uint32_t,
                std::string>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        Tunnel(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of InterfaceName */
        virtual std::string interfaceName() const;
        /** Set value of InterfaceName with option to skip sending signal */
        virtual std::string interfaceName(std::string value,
               bool skipSignal);
        /** Set value of InterfaceName */
        virtual std::string interfaceName(std::string value);
        /** Get value of Local */
        virtual std::string local() const;
        /** Set value of Local with option to skip sending signal */
        virtual std::string local(std::string value,
               bool skipSignal);
        /** Set value of Local */
        virtual std::string local(std::string value);
        /** Get value of Remote */
        virtual std::string remote() const;
        /** Set value of Remote with option to skip sending signal */
        virtual std::string remote(std::string value,
               bool skipSignal);
        /** Set value of Remote */
        virtual std::string remote(std::string value);
        /** Get value of TOS */
        virtual uint32_t tOS() const;
        /** Set value of TOS with option to skip sending signal */
        virtual uint32_t tOS(uint32_t value,
               bool skipSignal);
        /** Set value of TOS */
        virtual uint32_t tOS(uint32_t value);
        /** Get value of TTL */
        virtual uint32_t tTL() const;
        /** Set value of TTL with option to skip sending signal */
        virtual uint32_t tTL(uint32_t value,
               bool skipSignal);
        /** Set value of TTL */
        virtual uint32_t tTL(uint32_t value);
        /** Get value of DiscoverPathMTU */
        virtual bool discoverPathMTU() const;
        /** Set value of DiscoverPathMTU with option to skip sending signal */
        virtual bool discoverPathMTU(bool value,
               bool skipSignal);
        /** Set value of DiscoverPathMTU */
        virtual bool discoverPathMTU(bool value);
        /** Get value of IPv6FlowLabel */
        virtual uint32_t iPv6FlowLabel() const;
        /** Set value of IPv6FlowLabel with option to skip sending signal */
        virtual uint32_t iPv6FlowLabel(uint32_t value,
               bool skipSignal);
        /** Set value of IPv6FlowLabel */
        virtual uint32_t iPv6FlowLabel(uint32_t value);
        /** Get value of CopyDSCP */
        virtual bool copyDSCP() const;
        /** Set value of CopyDSCP with option to skip sending signal */
        virtual bool copyDSCP(bool value,
               bool skipSignal);
        /** Set value of CopyDSCP */
        virtual bool copyDSCP(bool value);
        /** Get value of EncapsulationLimit */
        virtual uint32_t encapsulationLimit() const;
        /** Set value of EncapsulationLimit with option to skip sending signal */
        virtual uint32_t encapsulationLimit(uint32_t value,
               bool skipSignal);
        /** Set value of EncapsulationLimit */
        virtual uint32_t encapsulationLimit(uint32_t value);
        /** Get value of Key */
        virtual std::string key() const;
        /** Set value of Key with option to skip sending signal */
        virtual std::string key(std::string value,
               bool skipSignal);
        /** Set value of Key */
        virtual std::string key(std::string value);
        /** Get value of InputKey */
        virtual std::string inputKey() const;
        /** Set value of InputKey with option to skip sending signal */
        virtual std::string inputKey(std::string value,
               bool skipSignal);
        /** Set value of InputKey */
        virtual std::string inputKey(std::string value);
        /** Get value of OutputKey */
        virtual std::string outputKey() const;
        /** Set value of OutputKey with option to skip sending signal */
        virtual std::string outputKey(std::string value,
               bool skipSignal);
        /** Set value of OutputKey */
        virtual std::string outputKey(std::string value);
        /** Get value of Mode */
        virtual IPv6Tunnel mode() const;
        /** Set value of Mode with option to skip sending signal */
        virtual IPv6Tunnel mode(IPv6Tunnel value,
               bool skipSignal);
        /** Set value of Mode */
        virtual IPv6Tunnel mode(IPv6Tunnel value);

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
     *                 "xyz.openbmc_project.Network.Experimental.Tunnel.<value name>"
     *  @return - The enum value.
     */
    static IPv6Tunnel convertIPv6TunnelFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for get-property 'InterfaceName' */
        static int _callback_get_InterfaceName(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'InterfaceName' */
        static int _callback_set_InterfaceName(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Local' */
        static int _callback_get_Local(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Local' */
        static int _callback_set_Local(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Remote' */
        static int _callback_get_Remote(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Remote' */
        static int _callback_set_Remote(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'TOS' */
        static int _callback_get_TOS(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'TOS' */
        static int _callback_set_TOS(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'TTL' */
        static int _callback_get_TTL(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'TTL' */
        static int _callback_set_TTL(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'DiscoverPathMTU' */
        static int _callback_get_DiscoverPathMTU(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'DiscoverPathMTU' */
        static int _callback_set_DiscoverPathMTU(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'IPv6FlowLabel' */
        static int _callback_get_IPv6FlowLabel(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'IPv6FlowLabel' */
        static int _callback_set_IPv6FlowLabel(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'CopyDSCP' */
        static int _callback_get_CopyDSCP(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'CopyDSCP' */
        static int _callback_set_CopyDSCP(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'EncapsulationLimit' */
        static int _callback_get_EncapsulationLimit(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'EncapsulationLimit' */
        static int _callback_set_EncapsulationLimit(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Key' */
        static int _callback_get_Key(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Key' */
        static int _callback_set_Key(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'InputKey' */
        static int _callback_get_InputKey(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'InputKey' */
        static int _callback_set_InputKey(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'OutputKey' */
        static int _callback_get_OutputKey(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'OutputKey' */
        static int _callback_set_OutputKey(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Mode' */
        static int _callback_get_Mode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Mode' */
        static int _callback_set_Mode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Network.Experimental.Tunnel";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Network_Experimental_Tunnel_interface;
        sdbusplus::SdBusInterface *_intf;

        std::string _interfaceName{};
        std::string _local{};
        std::string _remote{};
        uint32_t _tOS{};
        uint32_t _tTL{};
        bool _discoverPathMTU{};
        uint32_t _iPv6FlowLabel{};
        bool _copyDSCP{};
        uint32_t _encapsulationLimit{};
        std::string _key{};
        std::string _inputKey{};
        std::string _outputKey{};
        IPv6Tunnel _mode = IPv6Tunnel::any;

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Tunnel::IPv6Tunnel.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Tunnel::IPv6Tunnel e);

} // namespace server
} // namespace Experimental
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

