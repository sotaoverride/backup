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
namespace Common
{
namespace server
{

class ObjectPath
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
    ObjectPath() = delete;
    ObjectPath(const ObjectPath&) = delete;
    ObjectPath& operator=(const ObjectPath&) = delete;
    ObjectPath(ObjectPath&&) = delete;
    ObjectPath& operator=(ObjectPath&&) = delete;
    virtual ~ObjectPath() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    ObjectPath(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    ObjectPath(bus::bus& bus, const char* path,
               const std::map<std::string, PropertiesVariant>& vals,
               bool skipSignal = false);

    /** Get value of Path */
    virtual std::string path() const;
    /** Set value of Path with option to skip sending signal */
    virtual std::string path(std::string value, bool skipSignal);
    /** Set value of Path */
    virtual std::string path(std::string value);

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
    /** @brief sd-bus callback for get-property 'Path' */
    static int _callback_get_Path(sd_bus*, const char*, const char*,
                                  const char*, sd_bus_message*, void*,
                                  sd_bus_error*);
    /** @brief sd-bus callback for set-property 'Path' */
    static int _callback_set_Path(sd_bus*, const char*, const char*,
                                  const char*, sd_bus_message*, void*,
                                  sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Common.ObjectPath";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Common_ObjectPath_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _path{};
};

} // namespace server
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
