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

class Bond
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
        Bond() = delete;
        Bond(const Bond&) = delete;
        Bond& operator=(const Bond&) = delete;
        Bond(Bond&&) = delete;
        Bond& operator=(Bond&&) = delete;
        virtual ~Bond() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Bond(bus::bus& bus, const char* path);

        enum class BondingMode
        {
            RoundRobin,
            ActiveBackup,
            XOR,
            Broadcast,
            Dynamic,
            TLB,
            ALB,
        };
        enum class HashPolicy
        {
            Layer2,
            Layer2Plus3,
            Layer3Plus4,
            Encap2Plus3,
            Encap3Plus4,
        };

        using PropertiesVariant = std::variant<
                HashPolicy,
                BondingMode,
                std::vector<std::string>,
                std::string>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        Bond(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of InterfaceName */
        virtual std::string interfaceName() const;
        /** Set value of InterfaceName with option to skip sending signal */
        virtual std::string interfaceName(std::string value,
               bool skipSignal);
        /** Set value of InterfaceName */
        virtual std::string interfaceName(std::string value);
        /** Get value of BondedInterfaces */
        virtual std::vector<std::string> bondedInterfaces() const;
        /** Set value of BondedInterfaces with option to skip sending signal */
        virtual std::vector<std::string> bondedInterfaces(std::vector<std::string> value,
               bool skipSignal);
        /** Set value of BondedInterfaces */
        virtual std::vector<std::string> bondedInterfaces(std::vector<std::string> value);
        /** Get value of Mode */
        virtual BondingMode mode() const;
        /** Set value of Mode with option to skip sending signal */
        virtual BondingMode mode(BondingMode value,
               bool skipSignal);
        /** Set value of Mode */
        virtual BondingMode mode(BondingMode value);
        /** Get value of TransmitHashPolicy */
        virtual HashPolicy transmitHashPolicy() const;
        /** Set value of TransmitHashPolicy with option to skip sending signal */
        virtual HashPolicy transmitHashPolicy(HashPolicy value,
               bool skipSignal);
        /** Set value of TransmitHashPolicy */
        virtual HashPolicy transmitHashPolicy(HashPolicy value);

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
     *                 "xyz.openbmc_project.Network.Experimental.Bond.<value name>"
     *  @return - The enum value.
     */
    static BondingMode convertBondingModeFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Network.Experimental.Bond.<value name>"
     *  @return - The enum value.
     */
    static HashPolicy convertHashPolicyFromString(const std::string& s);

    private:

        /** @brief sd-bus callback for get-property 'InterfaceName' */
        static int _callback_get_InterfaceName(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'InterfaceName' */
        static int _callback_set_InterfaceName(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'BondedInterfaces' */
        static int _callback_get_BondedInterfaces(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'BondedInterfaces' */
        static int _callback_set_BondedInterfaces(
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

        /** @brief sd-bus callback for get-property 'TransmitHashPolicy' */
        static int _callback_get_TransmitHashPolicy(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'TransmitHashPolicy' */
        static int _callback_set_TransmitHashPolicy(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Network.Experimental.Bond";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Network_Experimental_Bond_interface;
        sdbusplus::SdBusInterface *_intf;

        std::string _interfaceName{};
        std::vector<std::string> _bondedInterfaces{};
        BondingMode _mode = BondingMode::RoundRobin;
        HashPolicy _transmitHashPolicy = HashPolicy::Layer2;

};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Bond::BondingMode.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Bond::BondingMode e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Bond::HashPolicy.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Bond::HashPolicy e);

} // namespace server
} // namespace Experimental
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

