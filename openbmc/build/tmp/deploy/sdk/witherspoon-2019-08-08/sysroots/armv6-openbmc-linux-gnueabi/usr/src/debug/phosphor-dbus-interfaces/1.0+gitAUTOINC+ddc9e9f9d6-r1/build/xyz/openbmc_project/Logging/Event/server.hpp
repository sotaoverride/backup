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
namespace Logging
{
namespace server
{

class Event
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
    Event() = delete;
    Event(const Event&) = delete;
    Event& operator=(const Event&) = delete;
    Event(Event&&) = delete;
    Event& operator=(Event&&) = delete;
    virtual ~Event() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Event(bus::bus& bus, const char* path);

    using PropertiesVariant =
        std::variant<uint64_t, std::vector<std::string>, std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Event(bus::bus& bus, const char* path,
          const std::map<std::string, PropertiesVariant>& vals,
          bool skipSignal = false);

    /** Get value of Timestamp */
    virtual uint64_t timestamp() const;
    /** Set value of Timestamp with option to skip sending signal */
    virtual uint64_t timestamp(uint64_t value, bool skipSignal);
    /** Set value of Timestamp */
    virtual uint64_t timestamp(uint64_t value);
    /** Get value of Message */
    virtual std::string message() const;
    /** Set value of Message with option to skip sending signal */
    virtual std::string message(std::string value, bool skipSignal);
    /** Set value of Message */
    virtual std::string message(std::string value);
    /** Get value of AdditionalData */
    virtual std::vector<std::string> additionalData() const;
    /** Set value of AdditionalData with option to skip sending signal */
    virtual std::vector<std::string>
        additionalData(std::vector<std::string> value, bool skipSignal);
    /** Set value of AdditionalData */
    virtual std::vector<std::string>
        additionalData(std::vector<std::string> value);

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
    /** @brief sd-bus callback for get-property 'Timestamp' */
    static int _callback_get_Timestamp(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Timestamp' */
    static int _callback_set_Timestamp(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);

    /** @brief sd-bus callback for get-property 'Message' */
    static int _callback_get_Message(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Message' */
    static int _callback_set_Message(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    /** @brief sd-bus callback for get-property 'AdditionalData' */
    static int _callback_get_AdditionalData(sd_bus*, const char*, const char*,
                                            const char*, sd_bus_message*, void*,
                                            sd_bus_error*);
    /** @brief sd-bus callback for set-property 'AdditionalData' */
    static int _callback_set_AdditionalData(sd_bus*, const char*, const char*,
                                            const char*, sd_bus_message*, void*,
                                            sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Logging.Event";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Logging_Event_interface;
    sdbusplus::SdBusInterface* _intf;

    uint64_t _timestamp{};
    std::string _message{};
    std::vector<std::string> _additionalData{};
};

} // namespace server
} // namespace Logging
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
