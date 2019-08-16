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
namespace server
{

class IP
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
        IP() = delete;
        IP(const IP&) = delete;
        IP& operator=(const IP&) = delete;
        IP(IP&&) = delete;
        IP& operator=(IP&&) = delete;
        virtual ~IP() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        IP(bus::bus& bus, const char* path);

        enum class Protocol
        {
            IPv4,
            IPv6,
        };
        enum class AddressOrigin
        {
            Static,
            DHCP,
            LinkLocal,
            SLAAC,
        };

        using PropertiesVariant = std::variant<
                AddressOrigin,
                Protocol,
                uint8_t,
                std::string>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        IP(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of Address */
        virtual std::string address() const;
        /** Set value of Address with option to skip sending signal */
        virtual std::string address(std::string value,
               bool skipSignal);
        /** Set value of Address */
        virtual std::string address(std::string value);
        /** Get value of PrefixLength */
        virtual uint8_t prefixLength() const;
        /** Set value of PrefixLength with option to skip sending signal */
        virtual uint8_t prefixLength(uint8_t value,
               bool skipSignal);
        /** Set value of PrefixLength */
        virtual uint8_t prefixLength(uint8_t value);
        /** Get value of Origin */
        virtual AddressOrigin origin() const;
        /** Set value of Origin with option to skip sending signal */
        virtual AddressOrigin origin(AddressOrigin value,
               bool skipSignal);
        /** Set value of Origin */
        virtual AddressOrigin origin(AddressOrigin value);
        /** Get value of Gateway */
        virtual std::string gateway() const;
        /** Set value of Gateway with option to skip sending signal */
        virtual std::string gateway(std::string value,
               bool skipSignal);
        /** Set value of Gateway */
        virtual std::string gateway(std::string value);
        /** Get value of Type */
        virtual Protocol type() const;
        /** Set value of Type with option to skip sending signal */
        virtual Protocol type(Protocol value,
               bool skipSignal);
        /** Set value of Type */
        virtual Protocol type(Protocol value);

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
     *                 "xyz.openbmc_project.Network.IP.<value name>"
     *  @return - The enum value.
     */
    static Protocol convertProtocolFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Network.IP.<value name>"
     *  @return - The enum value.
     */
    static AddressOrigin convertAddressOriginFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for get-property 'Address' */
        static int _callback_get_Address(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Address' */
        static int _callback_set_Address(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'PrefixLength' */
        static int _callback_get_PrefixLength(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'PrefixLength' */
        static int _callback_set_PrefixLength(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Origin' */
        static int _callback_get_Origin(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Origin' */
        static int _callback_set_Origin(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Gateway' */
        static int _callback_get_Gateway(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Gateway' */
        static int _callback_set_Gateway(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Type' */
        static int _callback_get_Type(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Type' */
        static int _callback_set_Type(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Network.IP";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Network_IP_interface;
        sdbusplus::SdBusInterface *_intf;

        std::string _address{};
        uint8_t _prefixLength{};
        AddressOrigin _origin{};
        std::string _gateway{};
        Protocol _type{};

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type IP::Protocol.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(IP::Protocol e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type IP::AddressOrigin.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(IP::AddressOrigin e);

} // namespace server
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

