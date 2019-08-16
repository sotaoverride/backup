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
namespace Control
{
namespace server
{

class FanRedundancy
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
    FanRedundancy() = delete;
    FanRedundancy(const FanRedundancy&) = delete;
    FanRedundancy& operator=(const FanRedundancy&) = delete;
    FanRedundancy(FanRedundancy&&) = delete;
    FanRedundancy& operator=(FanRedundancy&&) = delete;
    virtual ~FanRedundancy() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    FanRedundancy(bus::bus& bus, const char* path);

    enum class State
    {
        Full,
        Degraded,
        Failed,
    };

    using PropertiesVariant =
        std::variant<State, std::vector<sdbusplus::message::object_path>,
                     uint8_t>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    FanRedundancy(bus::bus& bus, const char* path,
                  const std::map<std::string, PropertiesVariant>& vals,
                  bool skipSignal = false);

    /** Get value of AllowedFailures */
    virtual uint8_t allowedFailures() const;
    /** Set value of AllowedFailures with option to skip sending signal */
    virtual uint8_t allowedFailures(uint8_t value, bool skipSignal);
    /** Set value of AllowedFailures */
    virtual uint8_t allowedFailures(uint8_t value);
    /** Get value of Collection */
    virtual std::vector<sdbusplus::message::object_path> collection() const;
    /** Set value of Collection with option to skip sending signal */
    virtual std::vector<sdbusplus::message::object_path>
        collection(std::vector<sdbusplus::message::object_path> value,
                   bool skipSignal);
    /** Set value of Collection */
    virtual std::vector<sdbusplus::message::object_path>
        collection(std::vector<sdbusplus::message::object_path> value);
    /** Get value of Status */
    virtual State status() const;
    /** Set value of Status with option to skip sending signal */
    virtual State status(State value, bool skipSignal);
    /** Set value of Status */
    virtual State status(State value);

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
     *                 "xyz.openbmc_project.Control.FanRedundancy.<value name>"
     *  @return - The enum value.
     */
    static State convertStateFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'AllowedFailures' */
    static int _callback_get_AllowedFailures(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'AllowedFailures' */
    static int _callback_set_AllowedFailures(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Collection' */
    static int _callback_get_Collection(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Collection' */
    static int _callback_set_Collection(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Status' */
    static int _callback_get_Status(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Status' */
    static int _callback_set_Status(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Control.FanRedundancy";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Control_FanRedundancy_interface;
    sdbusplus::SdBusInterface* _intf;

    uint8_t _allowedFailures{};
    std::vector<sdbusplus::message::object_path> _collection{};
    State _status{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type FanRedundancy::State.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(FanRedundancy::State e);

} // namespace server
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
