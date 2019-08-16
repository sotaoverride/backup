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
namespace Memory
{
namespace server
{

class MemoryECC
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
    MemoryECC() = delete;
    MemoryECC(const MemoryECC&) = delete;
    MemoryECC& operator=(const MemoryECC&) = delete;
    MemoryECC(MemoryECC&&) = delete;
    MemoryECC& operator=(MemoryECC&&) = delete;
    virtual ~MemoryECC() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    MemoryECC(bus::bus& bus, const char* path);

    enum class ECCStatus
    {
        ok,
        CE,
        UE,
        LogFull,
    };

    using PropertiesVariant = std::variant<ECCStatus, bool, int64_t>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    MemoryECC(bus::bus& bus, const char* path,
              const std::map<std::string, PropertiesVariant>& vals,
              bool skipSignal = false);

    /** Get value of isLoggingLimitReached */
    virtual bool isLoggingLimitReached() const;
    /** Set value of isLoggingLimitReached with option to skip sending signal */
    virtual bool isLoggingLimitReached(bool value, bool skipSignal);
    /** Set value of isLoggingLimitReached */
    virtual bool isLoggingLimitReached(bool value);
    /** Get value of ceCount */
    virtual int64_t ceCount() const;
    /** Set value of ceCount with option to skip sending signal */
    virtual int64_t ceCount(int64_t value, bool skipSignal);
    /** Set value of ceCount */
    virtual int64_t ceCount(int64_t value);
    /** Get value of ueCount */
    virtual int64_t ueCount() const;
    /** Set value of ueCount with option to skip sending signal */
    virtual int64_t ueCount(int64_t value, bool skipSignal);
    /** Set value of ueCount */
    virtual int64_t ueCount(int64_t value);
    /** Get value of state */
    virtual ECCStatus state() const;
    /** Set value of state with option to skip sending signal */
    virtual ECCStatus state(ECCStatus value, bool skipSignal);
    /** Set value of state */
    virtual ECCStatus state(ECCStatus value);

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
     *                 "xyz.openbmc_project.Memory.MemoryECC.<value name>"
     *  @return - The enum value.
     */
    static ECCStatus convertECCStatusFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'isLoggingLimitReached' */
    static int _callback_get_isLoggingLimitReached(sd_bus*, const char*,
                                                   const char*, const char*,
                                                   sd_bus_message*, void*,
                                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'isLoggingLimitReached' */
    static int _callback_set_isLoggingLimitReached(sd_bus*, const char*,
                                                   const char*, const char*,
                                                   sd_bus_message*, void*,
                                                   sd_bus_error*);

    /** @brief sd-bus callback for get-property 'ceCount' */
    static int _callback_get_ceCount(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'ceCount' */
    static int _callback_set_ceCount(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    /** @brief sd-bus callback for get-property 'ueCount' */
    static int _callback_get_ueCount(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);
    /** @brief sd-bus callback for set-property 'ueCount' */
    static int _callback_set_ueCount(sd_bus*, const char*, const char*,
                                     const char*, sd_bus_message*, void*,
                                     sd_bus_error*);

    /** @brief sd-bus callback for get-property 'state' */
    static int _callback_get_state(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'state' */
    static int _callback_set_state(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Memory.MemoryECC";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Memory_MemoryECC_interface;
    sdbusplus::SdBusInterface* _intf;

    bool _isLoggingLimitReached{};
    int64_t _ceCount{};
    int64_t _ueCount{};
    ECCStatus _state = ECCStatus::ok;
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type MemoryECC::ECCStatus.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(MemoryECC::ECCStatus e);

} // namespace server
} // namespace Memory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
