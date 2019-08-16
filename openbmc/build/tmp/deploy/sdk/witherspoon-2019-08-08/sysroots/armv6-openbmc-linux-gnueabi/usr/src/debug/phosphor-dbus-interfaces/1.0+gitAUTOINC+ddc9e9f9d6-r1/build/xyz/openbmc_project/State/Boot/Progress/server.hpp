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
namespace State
{
namespace Boot
{
namespace server
{

class Progress
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
    Progress() = delete;
    Progress(const Progress&) = delete;
    Progress& operator=(const Progress&) = delete;
    Progress(Progress&&) = delete;
    Progress& operator=(Progress&&) = delete;
    virtual ~Progress() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    Progress(bus::bus& bus, const char* path);

    enum class ProgressStages
    {
        Unspecified,
        MemoryInit,
        SecondaryProcInit,
        PCIInit,
        OSStart,
        MotherboardInit,
    };

    using PropertiesVariant = std::variant<ProgressStages>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    Progress(bus::bus& bus, const char* path,
             const std::map<std::string, PropertiesVariant>& vals,
             bool skipSignal = false);

    /** Get value of BootProgress */
    virtual ProgressStages bootProgress() const;
    /** Set value of BootProgress with option to skip sending signal */
    virtual ProgressStages bootProgress(ProgressStages value, bool skipSignal);
    /** Set value of BootProgress */
    virtual ProgressStages bootProgress(ProgressStages value);

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
     *                 "xyz.openbmc_project.State.Boot.Progress.<value name>"
     *  @return - The enum value.
     */
    static ProgressStages convertProgressStagesFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'BootProgress' */
    static int _callback_get_BootProgress(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'BootProgress' */
    static int _callback_set_BootProgress(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.State.Boot.Progress";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_State_Boot_Progress_interface;
    sdbusplus::SdBusInterface* _intf;

    ProgressStages _bootProgress = ProgressStages::Unspecified;
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type Progress::ProgressStages.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(Progress::ProgressStages e);

} // namespace server
} // namespace Boot
} // namespace State
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
