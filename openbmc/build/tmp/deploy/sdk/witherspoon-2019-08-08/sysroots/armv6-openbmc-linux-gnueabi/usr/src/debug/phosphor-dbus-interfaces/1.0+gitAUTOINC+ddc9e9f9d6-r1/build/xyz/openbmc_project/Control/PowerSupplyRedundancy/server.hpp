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

class PowerSupplyRedundancy
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
    PowerSupplyRedundancy() = delete;
    PowerSupplyRedundancy(const PowerSupplyRedundancy&) = delete;
    PowerSupplyRedundancy& operator=(const PowerSupplyRedundancy&) = delete;
    PowerSupplyRedundancy(PowerSupplyRedundancy&&) = delete;
    PowerSupplyRedundancy& operator=(PowerSupplyRedundancy&&) = delete;
    virtual ~PowerSupplyRedundancy() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    PowerSupplyRedundancy(bus::bus& bus, const char* path);

    enum class Algo
    {
        bmcSpecific,
        userSpecific,
    };
    enum class Status
    {
        inProgress,
        completed,
    };

    using PropertiesVariant =
        std::variant<Status, uint8_t, std::vector<uint8_t>, bool, Algo,
                     uint32_t>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    PowerSupplyRedundancy(bus::bus& bus, const char* path,
                          const std::map<std::string, PropertiesVariant>& vals,
                          bool skipSignal = false);

    /** Get value of PowerSupplyRedundancyEnabled */
    virtual bool powerSupplyRedundancyEnabled() const;
    /** Set value of PowerSupplyRedundancyEnabled with option to skip sending
     * signal */
    virtual bool powerSupplyRedundancyEnabled(bool value, bool skipSignal);
    /** Set value of PowerSupplyRedundancyEnabled */
    virtual bool powerSupplyRedundancyEnabled(bool value);
    /** Get value of RotationEnabled */
    virtual bool rotationEnabled() const;
    /** Set value of RotationEnabled with option to skip sending signal */
    virtual bool rotationEnabled(bool value, bool skipSignal);
    /** Set value of RotationEnabled */
    virtual bool rotationEnabled(bool value);
    /** Get value of RotationAlgorithm */
    virtual Algo rotationAlgorithm() const;
    /** Set value of RotationAlgorithm with option to skip sending signal */
    virtual Algo rotationAlgorithm(Algo value, bool skipSignal);
    /** Set value of RotationAlgorithm */
    virtual Algo rotationAlgorithm(Algo value);
    /** Get value of RotationRankOrder */
    virtual std::vector<uint8_t> rotationRankOrder() const;
    /** Set value of RotationRankOrder with option to skip sending signal */
    virtual std::vector<uint8_t> rotationRankOrder(std::vector<uint8_t> value,
                                                   bool skipSignal);
    /** Set value of RotationRankOrder */
    virtual std::vector<uint8_t> rotationRankOrder(std::vector<uint8_t> value);
    /** Get value of PeriodOfRotation */
    virtual uint32_t periodOfRotation() const;
    /** Set value of PeriodOfRotation with option to skip sending signal */
    virtual uint32_t periodOfRotation(uint32_t value, bool skipSignal);
    /** Set value of PeriodOfRotation */
    virtual uint32_t periodOfRotation(uint32_t value);
    /** Get value of ColdRedundancyStatus */
    virtual Status coldRedundancyStatus() const;
    /** Set value of ColdRedundancyStatus with option to skip sending signal */
    virtual Status coldRedundancyStatus(Status value, bool skipSignal);
    /** Set value of ColdRedundancyStatus */
    virtual Status coldRedundancyStatus(Status value);
    /** Get value of PSUNumber */
    virtual uint8_t pSUNumber() const;
    /** Set value of PSUNumber with option to skip sending signal */
    virtual uint8_t pSUNumber(uint8_t value, bool skipSignal);
    /** Set value of PSUNumber */
    virtual uint8_t pSUNumber(uint8_t value);

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
     *                 "xyz.openbmc_project.Control.PowerSupplyRedundancy.<value
     * name>"
     *  @return - The enum value.
     */
    static Algo convertAlgoFromString(const std::string& s);
    /** @brief Convert a string to an appropriate enum value.
     *  @param[in] s - The string to convert in the form of
     *                 "xyz.openbmc_project.Control.PowerSupplyRedundancy.<value
     * name>"
     *  @return - The enum value.
     */
    static Status convertStatusFromString(const std::string& s);

  private:
    /** @brief sd-bus callback for get-property 'PowerSupplyRedundancyEnabled'
     */
    static int _callback_get_PowerSupplyRedundancyEnabled(sd_bus*, const char*,
                                                          const char*,
                                                          const char*,
                                                          sd_bus_message*,
                                                          void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'PowerSupplyRedundancyEnabled'
     */
    static int _callback_set_PowerSupplyRedundancyEnabled(sd_bus*, const char*,
                                                          const char*,
                                                          const char*,
                                                          sd_bus_message*,
                                                          void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'RotationEnabled' */
    static int _callback_get_RotationEnabled(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'RotationEnabled' */
    static int _callback_set_RotationEnabled(sd_bus*, const char*, const char*,
                                             const char*, sd_bus_message*,
                                             void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'RotationAlgorithm' */
    static int _callback_get_RotationAlgorithm(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);
    /** @brief sd-bus callback for set-property 'RotationAlgorithm' */
    static int _callback_set_RotationAlgorithm(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);

    /** @brief sd-bus callback for get-property 'RotationRankOrder' */
    static int _callback_get_RotationRankOrder(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);
    /** @brief sd-bus callback for set-property 'RotationRankOrder' */
    static int _callback_set_RotationRankOrder(sd_bus*, const char*,
                                               const char*, const char*,
                                               sd_bus_message*, void*,
                                               sd_bus_error*);

    /** @brief sd-bus callback for get-property 'PeriodOfRotation' */
    static int _callback_get_PeriodOfRotation(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'PeriodOfRotation' */
    static int _callback_set_PeriodOfRotation(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'ColdRedundancyStatus' */
    static int _callback_get_ColdRedundancyStatus(sd_bus*, const char*,
                                                  const char*, const char*,
                                                  sd_bus_message*, void*,
                                                  sd_bus_error*);
    /** @brief sd-bus callback for set-property 'ColdRedundancyStatus' */
    static int _callback_set_ColdRedundancyStatus(sd_bus*, const char*,
                                                  const char*, const char*,
                                                  sd_bus_message*, void*,
                                                  sd_bus_error*);

    /** @brief sd-bus callback for get-property 'PSUNumber' */
    static int _callback_get_PSUNumber(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);
    /** @brief sd-bus callback for set-property 'PSUNumber' */
    static int _callback_set_PSUNumber(sd_bus*, const char*, const char*,
                                       const char*, sd_bus_message*, void*,
                                       sd_bus_error*);

    static constexpr auto _interface =
        "xyz.openbmc_project.Control.PowerSupplyRedundancy";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Control_PowerSupplyRedundancy_interface;
    sdbusplus::SdBusInterface* _intf;

    bool _powerSupplyRedundancyEnabled{};
    bool _rotationEnabled{};
    Algo _rotationAlgorithm{};
    std::vector<uint8_t> _rotationRankOrder{};
    uint32_t _periodOfRotation{};
    Status _coldRedundancyStatus{};
    uint8_t _pSUNumber{};
};

/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type PowerSupplyRedundancy::Algo.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(PowerSupplyRedundancy::Algo e);
/* Specialization of sdbusplus::server::bindings::details::convertForMessage
 * for enum-type PowerSupplyRedundancy::Status.
 *
 * This converts from the enum to a constant c-string representing the enum.
 *
 * @param[in] e - Enum value to convert.
 * @return C-string representing the name for the enum value.
 */
std::string convertForMessage(PowerSupplyRedundancy::Status e);

} // namespace server
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
