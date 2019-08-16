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
namespace Nvme
{
namespace server
{

class Status
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
    Status() = delete;
    Status(const Status&) = delete;
    Status& operator=(const Status&) = delete;
    Status(Status&&) = delete;
    Status& operator=(Status&&) = delete;
    virtual ~Status() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Status(bus::bus& bus, const char* path);

    using PropertiesVariant = std::variant<bool, std::string>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Status(bus::bus& bus, const char* path,
           const std::map<std::string, PropertiesVariant>& vals,
           bool skipSignal = false);

    /** Get value of SmartWarnings */
    virtual std::string smartWarnings() const;
    /** Set value of SmartWarnings with option to skip sending signal */
    virtual std::string smartWarnings(std::string value, bool skipSignal);
    /** Set value of SmartWarnings */
    virtual std::string smartWarnings(std::string value);
    /** Get value of StatusFlags */
    virtual std::string statusFlags() const;
    /** Set value of StatusFlags with option to skip sending signal */
    virtual std::string statusFlags(std::string value, bool skipSignal);
    /** Set value of StatusFlags */
    virtual std::string statusFlags(std::string value);
    /** Get value of DriveLifeUsed */
    virtual std::string driveLifeUsed() const;
    /** Set value of DriveLifeUsed with option to skip sending signal */
    virtual std::string driveLifeUsed(std::string value, bool skipSignal);
    /** Set value of DriveLifeUsed */
    virtual std::string driveLifeUsed(std::string value);
    /** Get value of CapacityFault */
    virtual bool capacityFault() const;
    /** Set value of CapacityFault with option to skip sending signal */
    virtual bool capacityFault(bool value, bool skipSignal);
    /** Set value of CapacityFault */
    virtual bool capacityFault(bool value);
    /** Get value of TemperatureFault */
    virtual bool temperatureFault() const;
    /** Set value of TemperatureFault with option to skip sending signal */
    virtual bool temperatureFault(bool value, bool skipSignal);
    /** Set value of TemperatureFault */
    virtual bool temperatureFault(bool value);
    /** Get value of DegradesFault */
    virtual bool degradesFault() const;
    /** Set value of DegradesFault with option to skip sending signal */
    virtual bool degradesFault(bool value, bool skipSignal);
    /** Set value of DegradesFault */
    virtual bool degradesFault(bool value);
    /** Get value of MediaFault */
    virtual bool mediaFault() const;
    /** Set value of MediaFault with option to skip sending signal */
    virtual bool mediaFault(bool value, bool skipSignal);
    /** Set value of MediaFault */
    virtual bool mediaFault(bool value);
    /** Get value of BackupDeviceFault */
    virtual bool backupDeviceFault() const;
    /** Set value of BackupDeviceFault with option to skip sending signal */
    virtual bool backupDeviceFault(bool value, bool skipSignal);
    /** Set value of BackupDeviceFault */
    virtual bool backupDeviceFault(bool value);

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
    /** @brief sd-bus callback for get-property 'SmartWarnings' */
    static int _callback_get_SmartWarnings(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'SmartWarnings' */
    static int _callback_set_SmartWarnings(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'StatusFlags' */
    static int _callback_get_StatusFlags(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);
    /** @brief sd-bus callback for set-property 'StatusFlags' */
    static int _callback_set_StatusFlags(sd_bus*, const char*, const char*,
                                         const char*, sd_bus_message*, void*,
                                         sd_bus_error*);

    /** @brief sd-bus callback for get-property 'DriveLifeUsed' */
    static int _callback_get_DriveLifeUsed(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DriveLifeUsed' */
    static int _callback_set_DriveLifeUsed(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'CapacityFault' */
    static int _callback_get_CapacityFault(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CapacityFault' */
    static int _callback_set_CapacityFault(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'TemperatureFault' */
    static int _callback_get_TemperatureFault(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'TemperatureFault' */
    static int _callback_set_TemperatureFault(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'DegradesFault' */
    static int _callback_get_DegradesFault(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'DegradesFault' */
    static int _callback_set_DegradesFault(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'MediaFault' */
    static int _callback_get_MediaFault(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'MediaFault' */
    static int _callback_set_MediaFault(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'BackupDeviceFault' */
    static int _callback_get_BackupDeviceFault(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);
    /** @brief sd-bus callback for set-property 'BackupDeviceFault' */
    static int _callback_set_BackupDeviceFault(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Nvme.Status";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Nvme_Status_interface;
    sdbusplus::SdBusInterface* _intf;

    std::string _smartWarnings{};
    std::string _statusFlags{};
    std::string _driveLifeUsed{};
    bool _capacityFault = false;
    bool _temperatureFault = false;
    bool _degradesFault = false;
    bool _mediaFault = false;
    bool _backupDeviceFault = false;
};

} // namespace server
} // namespace Nvme
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
