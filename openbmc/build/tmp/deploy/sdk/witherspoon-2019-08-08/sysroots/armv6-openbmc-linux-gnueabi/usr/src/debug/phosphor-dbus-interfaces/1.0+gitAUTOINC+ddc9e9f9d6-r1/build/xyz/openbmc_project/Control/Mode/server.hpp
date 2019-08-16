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

class Mode
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
    Mode() = delete;
    Mode(const Mode&) = delete;
    Mode& operator=(const Mode&) = delete;
    Mode(Mode&&) = delete;
    Mode& operator=(Mode&&) = delete;
    virtual ~Mode() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Mode(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<bool>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Mode(bus::bus& bus, const char* path,
         const std::map<std::string, PropertiesVariant>& vals,
         bool skipSignal = false);

    /** Get value of Manual */
    virtual bool manual() const;
    /** Set value of Manual with option to skip sending signal */
    virtual bool manual(bool value, bool skipSignal);
    /** Set value of Manual */
    virtual bool manual(bool value);
    /** Get value of FailSafe */
    virtual bool failSafe() const;
    /** Set value of FailSafe with option to skip sending signal */
    virtual bool failSafe(bool value, bool skipSignal);
    /** Set value of FailSafe */
    virtual bool failSafe(bool value);

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
    /** @brief sd-bus callback for get-property 'Manual' */
    static int _callback_get_Manual(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Manual' */
    static int _callback_set_Manual(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);

    /** @brief sd-bus callback for get-property 'FailSafe' */
    static int _callback_get_FailSafe(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);
    /** @brief sd-bus callback for set-property 'FailSafe' */
    static int _callback_set_FailSafe(sd_bus*, const char*, const char*,
                                      const char*, sd_bus_message*, void*,
                                      sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Control.Mode";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Control_Mode_interface;
    sdbusplus::SdBusInterface* _intf;

    bool _manual{};
    bool _failSafe{};
};

} // namespace server
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
