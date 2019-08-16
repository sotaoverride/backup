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
namespace Software
{
namespace server
{

class Activation
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
    Activation() = delete;
    Activation(const Activation&) = delete;
    Activation& operator=(const Activation&) = delete;
    Activation(Activation&&) = delete;
    Activation& operator=(Activation&&) = delete;
    virtual ~Activation() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Activation(bus::bus& bus, const char* path);

    enum class Activations
    {
        NotReady,
        Invalid,
        Ready,
        Activating,
        Active,
        Failed,
    };
    enum class RequestedActivations
    {
        None,
        Active,
    };

    using PropertiesVariant = std::variant<Activations, RequestedActivations>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Activation(bus::bus& bus, const char* path,
               const std::map<std::string, PropertiesVariant>& vals,
               bool skipSignal = false);

    /** Get value of Activation */
    virtual Activations activation() const;
    /** Set value of Activation with option to skip sending signal */
    virtual Activations activation(Activations value, bool skipSignal);
    /** Set value of Activation */
    virtual Activations activation(Activations value);
    /** Get value of RequestedActivation */
    virtual RequestedActivations requestedActivation() const;
    /** Set value of RequestedActivation with option to skip sending signal */
    virtual RequestedActivations requestedActivation(RequestedActivations value,
                                                     bool skipSignal);
    /** Set value of RequestedActivation */
    virtual RequestedActivations
        requestedActivation(RequestedActivations value);

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
     *                 "xyz.openbmc_project.Software.Activation.<value name>"
     *  @return - The enum value.
     */
    static Activations convertActivationsFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Software.Activation.<value name>"
     *  @return - The enum value.
     */
    static RequestedActivations
        convertRequestedActivationsFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'Activation' */
    static int _callback_get_Activation(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Activation' */
    static int _callback_set_Activation(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'RequestedActivation' */
    static int _callback_get_RequestedActivation(sd_bus*, const char*,
                                                 const char*, const char*,
                                                 sd_bus_message*, void*,
                                                 sd_bus_error*);
    /** @brief sd-bus callback for set-property 'RequestedActivation' */
    static int _callback_set_RequestedActivation(sd_bus*, const char*,
                                                 const char*, const char*,
                                                 sd_bus_message*, void*,
                                                 sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Software.Activation";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Software_Activation_interface;
    sdbusplus::SdBusInterface* _intf;

    Activations _activation{};
    RequestedActivations _requestedActivation{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Activation::Activations.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Activation::Activations e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Activation::RequestedActivations.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Activation::RequestedActivations e);

} // namespace server
} // namespace Software
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
