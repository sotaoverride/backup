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
namespace Ipmi
{
namespace server
{

class SessionInfo
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
    SessionInfo() = delete;
    SessionInfo(const SessionInfo&) = delete;
    SessionInfo& operator=(const SessionInfo&) = delete;
    SessionInfo(SessionInfo&&) = delete;
    SessionInfo& operator=(SessionInfo&&) = delete;
    virtual ~SessionInfo() = default;

    /** @brief Constructor to put object onto bus at a dbus path.
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     */
    SessionInfo(bus::bus& bus, const char* path);

    using PropertiesVariant =
        std::variant<uint16_t, uint32_t, uint8_t, std::vector<uint8_t>>;

    /** @brief Constructor to initialize the object from a map of
     *         properties.
     *
     *  @param[in] bus - Bus to attach to.
     *  @param[in] path - Path to attach at.
     *  @param[in] vals - Map of property name to value for initialization.
     */
    SessionInfo(bus::bus& bus, const char* path,
                const std::map<std::string, PropertiesVariant>& vals,
                bool skipSignal = false);

    /** Get value of SessionHandle */
    virtual uint8_t sessionHandle() const;
    /** Set value of SessionHandle with option to skip sending signal */
    virtual uint8_t sessionHandle(uint8_t value, bool skipSignal);
    /** Set value of SessionHandle */
    virtual uint8_t sessionHandle(uint8_t value);
    /** Get value of ChannelNum */
    virtual uint8_t channelNum() const;
    /** Set value of ChannelNum with option to skip sending signal */
    virtual uint8_t channelNum(uint8_t value, bool skipSignal);
    /** Set value of ChannelNum */
    virtual uint8_t channelNum(uint8_t value);
    /** Get value of CurrentPrivilege */
    virtual uint8_t currentPrivilege() const;
    /** Set value of CurrentPrivilege with option to skip sending signal */
    virtual uint8_t currentPrivilege(uint8_t value, bool skipSignal);
    /** Set value of CurrentPrivilege */
    virtual uint8_t currentPrivilege(uint8_t value);
    /** Get value of RemoteIPAddr */
    virtual uint32_t remoteIPAddr() const;
    /** Set value of RemoteIPAddr with option to skip sending signal */
    virtual uint32_t remoteIPAddr(uint32_t value, bool skipSignal);
    /** Set value of RemoteIPAddr */
    virtual uint32_t remoteIPAddr(uint32_t value);
    /** Get value of RemotePort */
    virtual uint16_t remotePort() const;
    /** Set value of RemotePort with option to skip sending signal */
    virtual uint16_t remotePort(uint16_t value, bool skipSignal);
    /** Set value of RemotePort */
    virtual uint16_t remotePort(uint16_t value);
    /** Get value of RemoteMACAddress */
    virtual std::vector<uint8_t> remoteMACAddress() const;
    /** Set value of RemoteMACAddress with option to skip sending signal */
    virtual std::vector<uint8_t> remoteMACAddress(std::vector<uint8_t> value,
                                                  bool skipSignal);
    /** Set value of RemoteMACAddress */
    virtual std::vector<uint8_t> remoteMACAddress(std::vector<uint8_t> value);
    /** Get value of UserID */
    virtual uint8_t userID() const;
    /** Set value of UserID with option to skip sending signal */
    virtual uint8_t userID(uint8_t value, bool skipSignal);
    /** Set value of UserID */
    virtual uint8_t userID(uint8_t value);
    /** Get value of State */
    virtual uint8_t state() const;
    /** Set value of State with option to skip sending signal */
    virtual uint8_t state(uint8_t value, bool skipSignal);
    /** Set value of State */
    virtual uint8_t state(uint8_t value);

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
    /** @brief sd-bus callback for get-property 'SessionHandle' */
    static int _callback_get_SessionHandle(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);
    /** @brief sd-bus callback for set-property 'SessionHandle' */
    static int _callback_set_SessionHandle(sd_bus*, const char*, const char*,
                                           const char*, sd_bus_message*, void*,
                                           sd_bus_error*);

    /** @brief sd-bus callback for get-property 'ChannelNum' */
    static int _callback_get_ChannelNum(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'ChannelNum' */
    static int _callback_set_ChannelNum(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'CurrentPrivilege' */
    static int _callback_get_CurrentPrivilege(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'CurrentPrivilege' */
    static int _callback_set_CurrentPrivilege(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'RemoteIPAddr' */
    static int _callback_get_RemoteIPAddr(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);
    /** @brief sd-bus callback for set-property 'RemoteIPAddr' */
    static int _callback_set_RemoteIPAddr(sd_bus*, const char*, const char*,
                                          const char*, sd_bus_message*, void*,
                                          sd_bus_error*);

    /** @brief sd-bus callback for get-property 'RemotePort' */
    static int _callback_get_RemotePort(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);
    /** @brief sd-bus callback for set-property 'RemotePort' */
    static int _callback_set_RemotePort(sd_bus*, const char*, const char*,
                                        const char*, sd_bus_message*, void*,
                                        sd_bus_error*);

    /** @brief sd-bus callback for get-property 'RemoteMACAddress' */
    static int _callback_get_RemoteMACAddress(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);
    /** @brief sd-bus callback for set-property 'RemoteMACAddress' */
    static int _callback_set_RemoteMACAddress(sd_bus*, const char*, const char*,
                                              const char*, sd_bus_message*,
                                              void*, sd_bus_error*);

    /** @brief sd-bus callback for get-property 'UserID' */
    static int _callback_get_UserID(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);
    /** @brief sd-bus callback for set-property 'UserID' */
    static int _callback_set_UserID(sd_bus*, const char*, const char*,
                                    const char*, sd_bus_message*, void*,
                                    sd_bus_error*);

    /** @brief sd-bus callback for get-property 'State' */
    static int _callback_get_State(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);
    /** @brief sd-bus callback for set-property 'State' */
    static int _callback_set_State(sd_bus*, const char*, const char*,
                                   const char*, sd_bus_message*, void*,
                                   sd_bus_error*);

    static constexpr auto _interface = "xyz.openbmc_project.Ipmi.SessionInfo";
    static const vtable::vtable_t _vtable[];
    sdbusplus::server::interface::
        interface _xyz_openbmc_project_Ipmi_SessionInfo_interface;
    sdbusplus::SdBusInterface* _intf;

    uint8_t _sessionHandle{};
    uint8_t _channelNum{};
    uint8_t _currentPrivilege{};
    uint32_t _remoteIPAddr{};
    uint16_t _remotePort{};
    std::vector<uint8_t> _remoteMACAddress{};
    uint8_t _userID{};
    uint8_t _state = 0;
};

} // namespace server
} // namespace Ipmi
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
