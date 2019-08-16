#include <algorithm>
#include <com/ibm/Logging/Policy/server.hpp>
#include <map>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>

namespace sdbusplus
{
namespace com
{
namespace ibm
{
namespace Logging
{
namespace server
{

Policy::Policy(bus::bus& bus, const char* path) :
    _com_ibm_Logging_Policy_interface(bus, path, _interface, _vtable, this),
    _intf(bus.getInterface())
{
}

Policy::Policy(bus::bus& bus, const char* path,
               const std::map<std::string, PropertiesVariant>& vals,
               bool skipSignal) :
    Policy(bus, path)
{
    for (const auto& v : vals)
    {
        setPropertyByName(v.first, v.second, skipSignal);
    }
}

auto Policy::eventID() const -> std::string
{
    return _eventID;
}

int Policy::_callback_get_EventID(sd_bus* bus, const char* path,
                                  const char* interface, const char* property,
                                  sd_bus_message* reply, void* context,
                                  sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Policy*>(context);

    try
    {
        auto m = message::message(reply, o->_intf);

#if 1
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id(
                std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        m.append(convertForMessage(o->eventID()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Policy::eventID(std::string value, bool skipSignal) -> std::string
{
    if (_eventID != value)
    {
        _eventID = value;
        if (!skipSignal)
        {
            _com_ibm_Logging_Policy_interface.property_changed("EventID");
        }
    }

    return _eventID;
}

auto Policy::eventID(std::string val) -> std::string
{
    return eventID(val, false);
}
int Policy::_callback_set_EventID(sd_bus* bus, const char* path,
                                  const char* interface, const char* property,
                                  sd_bus_message* value, void* context,
                                  sd_bus_error* error)
{
    auto o = static_cast<Policy*>(context);

    try
    {
        auto m = message::message(value, o->_intf);

#if 1
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id(
                std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        std::string v{};
        m.read(v);
        o->eventID(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Policy
{
static const auto _property_EventID =
    utility::tuple_to_array(message::types::type_id<std::string>());
}
} // namespace details

auto Policy::description() const -> std::string
{
    return _description;
}

int Policy::_callback_get_Description(sd_bus* bus, const char* path,
                                      const char* interface,
                                      const char* property,
                                      sd_bus_message* reply, void* context,
                                      sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Policy*>(context);

    try
    {
        auto m = message::message(reply, o->_intf);

#if 1
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id(
                std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        m.append(convertForMessage(o->description()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Policy::description(std::string value, bool skipSignal) -> std::string
{
    if (_description != value)
    {
        _description = value;
        if (!skipSignal)
        {
            _com_ibm_Logging_Policy_interface.property_changed("Description");
        }
    }

    return _description;
}

auto Policy::description(std::string val) -> std::string
{
    return description(val, false);
}
int Policy::_callback_set_Description(sd_bus* bus, const char* path,
                                      const char* interface,
                                      const char* property,
                                      sd_bus_message* value, void* context,
                                      sd_bus_error* error)
{
    auto o = static_cast<Policy*>(context);

    try
    {
        auto m = message::message(value, o->_intf);

#if 1
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id(
                std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        std::string v{};
        m.read(v);
        o->description(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Policy
{
static const auto _property_Description =
    utility::tuple_to_array(message::types::type_id<std::string>());
}
} // namespace details

void Policy::setPropertyByName(const std::string& _name,
                               const PropertiesVariant& val, bool skipSignal)
{
    if (_name == "EventID")
    {
        auto& v = std::get<std::string>(val);
        eventID(v, skipSignal);
        return;
    }
    if (_name == "Description")
    {
        auto& v = std::get<std::string>(val);
        description(v, skipSignal);
        return;
    }
}

auto Policy::getPropertyByName(const std::string& _name) -> PropertiesVariant
{
    if (_name == "EventID")
    {
        return eventID();
    }
    if (_name == "Description")
    {
        return description();
    }

    return PropertiesVariant();
}

const vtable::vtable_t Policy::_vtable[] = {
    vtable::start(),
    vtable::property("EventID", details::Policy::_property_EventID.data(),
                     _callback_get_EventID, _callback_set_EventID,
                     vtable::property_::emits_change),
    vtable::property("Description",
                     details::Policy::_property_Description.data(),
                     _callback_get_Description, _callback_set_Description,
                     vtable::property_::emits_change),
    vtable::end()};

} // namespace server
} // namespace Logging
} // namespace ibm
} // namespace com
} // namespace sdbusplus
