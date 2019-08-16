#include <algorithm>
#include <map>
#include <org/open_power/Inventory/Decorator/Asset/server.hpp>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Inventory
{
namespace Decorator
{
namespace server
{

Asset::Asset(bus::bus& bus, const char* path) :
    _org_open_power_Inventory_Decorator_Asset_interface(bus, path, _interface,
                                                        _vtable, this),
    _intf(bus.getInterface())
{
}

Asset::Asset(bus::bus& bus, const char* path,
             const std::map<std::string, PropertiesVariant>& vals,
             bool skipSignal) :
    Asset(bus, path)
{
    for (const auto& v : vals)
    {
        setPropertyByName(v.first, v.second, skipSignal);
    }
}

auto Asset::cCIN() const -> std::string
{
    return _cCIN;
}

int Asset::_callback_get_CCIN(sd_bus* bus, const char* path,
                              const char* interface, const char* property,
                              sd_bus_message* reply, void* context,
                              sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Asset*>(context);

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

        m.append(convertForMessage(o->cCIN()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Asset::cCIN(std::string value, bool skipSignal) -> std::string
{
    if (_cCIN != value)
    {
        _cCIN = value;
        if (!skipSignal)
        {
            _org_open_power_Inventory_Decorator_Asset_interface
                .property_changed("CCIN");
        }
    }

    return _cCIN;
}

auto Asset::cCIN(std::string val) -> std::string
{
    return cCIN(val, false);
}
int Asset::_callback_set_CCIN(sd_bus* bus, const char* path,
                              const char* interface, const char* property,
                              sd_bus_message* value, void* context,
                              sd_bus_error* error)
{
    auto o = static_cast<Asset*>(context);

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
        o->cCIN(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Asset
{
static const auto _property_CCIN =
    utility::tuple_to_array(message::types::type_id<std::string>());
}
} // namespace details

void Asset::setPropertyByName(const std::string& _name,
                              const PropertiesVariant& val, bool skipSignal)
{
    if (_name == "CCIN")
    {
        auto& v = std::get<std::string>(val);
        cCIN(v, skipSignal);
        return;
    }
}

auto Asset::getPropertyByName(const std::string& _name) -> PropertiesVariant
{
    if (_name == "CCIN")
    {
        return cCIN();
    }

    return PropertiesVariant();
}

const vtable::vtable_t Asset::_vtable[] = {
    vtable::start(),
    vtable::property("CCIN", details::Asset::_property_CCIN.data(),
                     _callback_get_CCIN, _callback_set_CCIN,
                     vtable::property_::emits_change),
    vtable::end()};

} // namespace server
} // namespace Decorator
} // namespace Inventory
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <algorithm>
#include <map>
#include <org/open_power/OCC/PassThrough/server.hpp>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace OCC
{
namespace server
{

PassThrough::PassThrough(bus::bus& bus, const char* path) :
    _org_open_power_OCC_PassThrough_interface(bus, path, _interface, _vtable,
                                              this),
    _intf(bus.getInterface())
{
}

int PassThrough::_callback_Send(sd_bus_message* msg, void* context,
                                sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    try
    {
        auto m = message::message(msg);
#if 1
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id(
                std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        std::vector<int32_t> command{};

        m.read(command);

        auto o = static_cast<PassThrough*>(context);
        auto r = o->send(command);

        auto reply = m.new_method_return();
        reply.append(convertForMessage(std::move(r)));

        reply.method_return();
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace PassThrough
{
static const auto _param_Send =
    utility::tuple_to_array(message::types::type_id<std::vector<int32_t>>());
static const auto _return_Send =
    utility::tuple_to_array(message::types::type_id<std::vector<int32_t>>());
} // namespace PassThrough
} // namespace details

const vtable::vtable_t PassThrough::_vtable[] = {
    vtable::start(),

    vtable::method("Send", details::PassThrough::_param_Send.data(),
                   details::PassThrough::_return_Send.data(), _callback_Send),
    vtable::end()};

} // namespace server
} // namespace OCC
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <algorithm>
#include <map>
#include <org/open_power/OCC/Status/server.hpp>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace OCC
{
namespace server
{

Status::Status(bus::bus& bus, const char* path) :
    _org_open_power_OCC_Status_interface(bus, path, _interface, _vtable, this),
    _intf(bus.getInterface())
{
}

Status::Status(bus::bus& bus, const char* path,
               const std::map<std::string, PropertiesVariant>& vals,
               bool skipSignal) :
    Status(bus, path)
{
    for (const auto& v : vals)
    {
        setPropertyByName(v.first, v.second, skipSignal);
    }
}

auto Status::occActive() const -> bool
{
    return _occActive;
}

int Status::_callback_get_OccActive(sd_bus* bus, const char* path,
                                    const char* interface, const char* property,
                                    sd_bus_message* reply, void* context,
                                    sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Status*>(context);

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

        m.append(convertForMessage(o->occActive()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Status::occActive(bool value, bool skipSignal) -> bool
{
    if (_occActive != value)
    {
        _occActive = value;
        if (!skipSignal)
        {
            _org_open_power_OCC_Status_interface.property_changed("OccActive");
        }
    }

    return _occActive;
}

auto Status::occActive(bool val) -> bool
{
    return occActive(val, false);
}
int Status::_callback_set_OccActive(sd_bus* bus, const char* path,
                                    const char* interface, const char* property,
                                    sd_bus_message* value, void* context,
                                    sd_bus_error* error)
{
    auto o = static_cast<Status*>(context);

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

        bool v{};
        m.read(v);
        o->occActive(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Status
{
static const auto _property_OccActive =
    utility::tuple_to_array(message::types::type_id<bool>());
}
} // namespace details

auto Status::throttleProcTemp() const -> bool
{
    return _throttleProcTemp;
}

int Status::_callback_get_ThrottleProcTemp(sd_bus* bus, const char* path,
                                           const char* interface,
                                           const char* property,
                                           sd_bus_message* reply, void* context,
                                           sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Status*>(context);

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

        m.append(convertForMessage(o->throttleProcTemp()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Status::throttleProcTemp(bool value, bool skipSignal) -> bool
{
    if (_throttleProcTemp != value)
    {
        _throttleProcTemp = value;
        if (!skipSignal)
        {
            _org_open_power_OCC_Status_interface.property_changed(
                "ThrottleProcTemp");
        }
    }

    return _throttleProcTemp;
}

auto Status::throttleProcTemp(bool val) -> bool
{
    return throttleProcTemp(val, false);
}
int Status::_callback_set_ThrottleProcTemp(sd_bus* bus, const char* path,
                                           const char* interface,
                                           const char* property,
                                           sd_bus_message* value, void* context,
                                           sd_bus_error* error)
{
    auto o = static_cast<Status*>(context);

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

        bool v{};
        m.read(v);
        o->throttleProcTemp(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Status
{
static const auto _property_ThrottleProcTemp =
    utility::tuple_to_array(message::types::type_id<bool>());
}
} // namespace details

auto Status::throttleProcPower() const -> bool
{
    return _throttleProcPower;
}

int Status::_callback_get_ThrottleProcPower(sd_bus* bus, const char* path,
                                            const char* interface,
                                            const char* property,
                                            sd_bus_message* reply,
                                            void* context, sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Status*>(context);

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

        m.append(convertForMessage(o->throttleProcPower()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Status::throttleProcPower(bool value, bool skipSignal) -> bool
{
    if (_throttleProcPower != value)
    {
        _throttleProcPower = value;
        if (!skipSignal)
        {
            _org_open_power_OCC_Status_interface.property_changed(
                "ThrottleProcPower");
        }
    }

    return _throttleProcPower;
}

auto Status::throttleProcPower(bool val) -> bool
{
    return throttleProcPower(val, false);
}
int Status::_callback_set_ThrottleProcPower(sd_bus* bus, const char* path,
                                            const char* interface,
                                            const char* property,
                                            sd_bus_message* value,
                                            void* context, sd_bus_error* error)
{
    auto o = static_cast<Status*>(context);

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

        bool v{};
        m.read(v);
        o->throttleProcPower(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Status
{
static const auto _property_ThrottleProcPower =
    utility::tuple_to_array(message::types::type_id<bool>());
}
} // namespace details

auto Status::throttleMemTemp() const -> bool
{
    return _throttleMemTemp;
}

int Status::_callback_get_ThrottleMemTemp(sd_bus* bus, const char* path,
                                          const char* interface,
                                          const char* property,
                                          sd_bus_message* reply, void* context,
                                          sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Status*>(context);

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

        m.append(convertForMessage(o->throttleMemTemp()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Status::throttleMemTemp(bool value, bool skipSignal) -> bool
{
    if (_throttleMemTemp != value)
    {
        _throttleMemTemp = value;
        if (!skipSignal)
        {
            _org_open_power_OCC_Status_interface.property_changed(
                "ThrottleMemTemp");
        }
    }

    return _throttleMemTemp;
}

auto Status::throttleMemTemp(bool val) -> bool
{
    return throttleMemTemp(val, false);
}
int Status::_callback_set_ThrottleMemTemp(sd_bus* bus, const char* path,
                                          const char* interface,
                                          const char* property,
                                          sd_bus_message* value, void* context,
                                          sd_bus_error* error)
{
    auto o = static_cast<Status*>(context);

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

        bool v{};
        m.read(v);
        o->throttleMemTemp(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Status
{
static const auto _property_ThrottleMemTemp =
    utility::tuple_to_array(message::types::type_id<bool>());
}
} // namespace details

void Status::setPropertyByName(const std::string& _name,
                               const PropertiesVariant& val, bool skipSignal)
{
    if (_name == "OccActive")
    {
        auto& v = std::get<bool>(val);
        occActive(v, skipSignal);
        return;
    }
    if (_name == "ThrottleProcTemp")
    {
        auto& v = std::get<bool>(val);
        throttleProcTemp(v, skipSignal);
        return;
    }
    if (_name == "ThrottleProcPower")
    {
        auto& v = std::get<bool>(val);
        throttleProcPower(v, skipSignal);
        return;
    }
    if (_name == "ThrottleMemTemp")
    {
        auto& v = std::get<bool>(val);
        throttleMemTemp(v, skipSignal);
        return;
    }
}

auto Status::getPropertyByName(const std::string& _name) -> PropertiesVariant
{
    if (_name == "OccActive")
    {
        return occActive();
    }
    if (_name == "ThrottleProcTemp")
    {
        return throttleProcTemp();
    }
    if (_name == "ThrottleProcPower")
    {
        return throttleProcPower();
    }
    if (_name == "ThrottleMemTemp")
    {
        return throttleMemTemp();
    }

    return PropertiesVariant();
}

const vtable::vtable_t Status::_vtable[] = {
    vtable::start(),
    vtable::property("OccActive", details::Status::_property_OccActive.data(),
                     _callback_get_OccActive, _callback_set_OccActive,
                     vtable::property_::emits_change),
    vtable::property(
        "ThrottleProcTemp", details::Status::_property_ThrottleProcTemp.data(),
        _callback_get_ThrottleProcTemp, _callback_set_ThrottleProcTemp,
        vtable::property_::emits_change),
    vtable::property("ThrottleProcPower",
                     details::Status::_property_ThrottleProcPower.data(),
                     _callback_get_ThrottleProcPower,
                     _callback_set_ThrottleProcPower,
                     vtable::property_::emits_change),
    vtable::property(
        "ThrottleMemTemp", details::Status::_property_ThrottleMemTemp.data(),
        _callback_get_ThrottleMemTemp, _callback_set_ThrottleMemTemp,
        vtable::property_::emits_change),
    vtable::end()};

} // namespace server
} // namespace OCC
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <algorithm>
#include <map>
#include <org/open_power/Control/Host/server.hpp>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Control
{
namespace server
{

Host::Host(bus::bus& bus, const char* path) :
    _org_open_power_Control_Host_interface(bus, path, _interface, _vtable,
                                           this),
    _intf(bus.getInterface())
{
}

int Host::_callback_Execute(sd_bus_message* msg, void* context,
                            sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    try
    {
        auto m = message::message(msg);
#if 1
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id(
                std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        std::string command{};
        std::variant<uint8_t> data{};

        m.read(command, data);

        auto o = static_cast<Host*>(context);
        o->execute(convertCommandFromString(command), data);

        auto reply = m.new_method_return();
        // No data to append on reply.

        reply.method_return();
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Host
{
static const auto _param_Execute = utility::tuple_to_array(
    message::types::type_id<std::string, std::variant<uint8_t>>());
static const auto _return_Execute =
    utility::tuple_to_array(std::make_tuple('\0'));
} // namespace Host
} // namespace details

void Host::commandComplete(Command command, Result result)
{
    using sdbusplus::server::binding::details::convertForMessage;

    auto& i = _org_open_power_Control_Host_interface;
    auto m = i.new_signal("CommandComplete");

    m.append(convertForMessage(command), convertForMessage(result));
    m.signal_send();
}

namespace details
{
namespace Host
{
static const auto _signal_CommandComplete = utility::tuple_to_array(
    message::types::type_id<std::string, std::string>());
}
} // namespace details

namespace
{
/** String to enum mapping for Host::Command */
static const std::tuple<const char*, Host::Command> mappingHostCommand[] = {
    std::make_tuple("org.open_power.Control.Host.Command.OCCReset",
                    Host::Command::OCCReset),
};

} // anonymous namespace

auto Host::convertCommandFromString(const std::string& s) -> Command
{
    auto i = std::find_if(
        std::begin(mappingHostCommand), std::end(mappingHostCommand),
        [&s](auto& e) { return 0 == strcmp(s.c_str(), std::get<0>(e)); });
    if (std::end(mappingHostCommand) == i)
    {
        throw sdbusplus::exception::InvalidEnumString();
    }
    else
    {
        return std::get<1>(*i);
    }
}

std::string convertForMessage(Host::Command v)
{
    auto i = std::find_if(std::begin(mappingHostCommand),
                          std::end(mappingHostCommand),
                          [v](auto& e) { return v == std::get<1>(e); });
    if (i == std::end(mappingHostCommand))
    {
        throw std::invalid_argument(std::to_string(static_cast<int>(v)));
    }
    return std::get<0>(*i);
}

namespace
{
/** String to enum mapping for Host::Result */
static const std::tuple<const char*, Host::Result> mappingHostResult[] = {
    std::make_tuple("org.open_power.Control.Host.Result.Success",
                    Host::Result::Success),
    std::make_tuple("org.open_power.Control.Host.Result.Failure",
                    Host::Result::Failure),
};

} // anonymous namespace

auto Host::convertResultFromString(const std::string& s) -> Result
{
    auto i = std::find_if(
        std::begin(mappingHostResult), std::end(mappingHostResult),
        [&s](auto& e) { return 0 == strcmp(s.c_str(), std::get<0>(e)); });
    if (std::end(mappingHostResult) == i)
    {
        throw sdbusplus::exception::InvalidEnumString();
    }
    else
    {
        return std::get<1>(*i);
    }
}

std::string convertForMessage(Host::Result v)
{
    auto i =
        std::find_if(std::begin(mappingHostResult), std::end(mappingHostResult),
                     [v](auto& e) { return v == std::get<1>(e); });
    if (i == std::end(mappingHostResult))
    {
        throw std::invalid_argument(std::to_string(static_cast<int>(v)));
    }
    return std::get<0>(*i);
}

const vtable::vtable_t Host::_vtable[] = {
    vtable::start(),

    vtable::method("Execute", details::Host::_param_Execute.data(),
                   details::Host::_return_Execute.data(), _callback_Execute),

    vtable::signal("CommandComplete",
                   details::Host::_signal_CommandComplete.data()),
    vtable::end()};

} // namespace server
} // namespace Control
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <algorithm>
#include <map>
#include <org/open_power/Logging/PEL/server.hpp>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>
#include <xyz/openbmc_project/Common/error.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Logging
{
namespace server
{

PEL::PEL(bus::bus& bus, const char* path) :
    _org_open_power_Logging_PEL_interface(bus, path, _interface, _vtable, this),
    _intf(bus.getInterface())
{
}

int PEL::_callback_GetPEL(sd_bus_message* msg, void* context,
                          sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    try
    {
        auto m = message::message(msg);
#if 1
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id(
                std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        int32_t pelID{};

        m.read(pelID);

        auto o = static_cast<PEL*>(context);
        auto r = o->getPEL(pelID);

        auto reply = m.new_method_return();
        reply.append(convertForMessage(std::move(r)));

        reply.method_return();
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }
    catch (sdbusplus::xyz::openbmc_project::Common::Error::InternalFailure& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }
    catch (sdbusplus::xyz::openbmc_project::Common::Error::InvalidArgument& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace PEL
{
static const auto _param_GetPEL =
    utility::tuple_to_array(message::types::type_id<int32_t>());
static const auto _return_GetPEL = utility::tuple_to_array(
    message::types::type_id<sdbusplus::message::unix_fd>());
} // namespace PEL
} // namespace details

int PEL::_callback_GetPELFromOBMCID(sd_bus_message* msg, void* context,
                                    sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    try
    {
        auto m = message::message(msg);
#if 1
        {
            auto tbus = m.get_bus();
            sdbusplus::server::transaction::Transaction t(tbus, m);
            sdbusplus::server::transaction::set_id(
                std::hash<sdbusplus::server::transaction::Transaction>{}(t));
        }
#endif

        int32_t obmcLogID{};

        m.read(obmcLogID);

        auto o = static_cast<PEL*>(context);
        auto r = o->getPELFromOBMCID(obmcLogID);

        auto reply = m.new_method_return();
        reply.append(convertForMessage(std::move(r)));

        reply.method_return();
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }
    catch (sdbusplus::xyz::openbmc_project::Common::Error::InternalFailure& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }
    catch (sdbusplus::xyz::openbmc_project::Common::Error::InvalidArgument& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace PEL
{
static const auto _param_GetPELFromOBMCID =
    utility::tuple_to_array(message::types::type_id<int32_t>());
static const auto _return_GetPELFromOBMCID =
    utility::tuple_to_array(message::types::type_id<std::vector<uint8_t>>());
} // namespace PEL
} // namespace details

const vtable::vtable_t PEL::_vtable[] = {
    vtable::start(),

    vtable::method("GetPEL", details::PEL::_param_GetPEL.data(),
                   details::PEL::_return_GetPEL.data(), _callback_GetPEL),

    vtable::method("GetPELFromOBMCID",
                   details::PEL::_param_GetPELFromOBMCID.data(),
                   details::PEL::_return_GetPELFromOBMCID.data(),
                   _callback_GetPELFromOBMCID),
    vtable::end()};

} // namespace server
} // namespace Logging
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <algorithm>
#include <map>
#include <org/open_power/Sensor/Aggregation/History/Average/server.hpp>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Sensor
{
namespace Aggregation
{
namespace History
{
namespace server
{

Average::Average(bus::bus& bus, const char* path) :
    _org_open_power_Sensor_Aggregation_History_Average_interface(
        bus, path, _interface, _vtable, this),
    _intf(bus.getInterface())
{
}

Average::Average(bus::bus& bus, const char* path,
                 const std::map<std::string, PropertiesVariant>& vals,
                 bool skipSignal) :
    Average(bus, path)
{
    for (const auto& v : vals)
    {
        setPropertyByName(v.first, v.second, skipSignal);
    }
}

auto Average::scale() const -> int64_t
{
    return _scale;
}

int Average::_callback_get_Scale(sd_bus* bus, const char* path,
                                 const char* interface, const char* property,
                                 sd_bus_message* reply, void* context,
                                 sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Average*>(context);

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

        m.append(convertForMessage(o->scale()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Average::scale(int64_t value, bool skipSignal) -> int64_t
{
    if (_scale != value)
    {
        _scale = value;
        if (!skipSignal)
        {
            _org_open_power_Sensor_Aggregation_History_Average_interface
                .property_changed("Scale");
        }
    }

    return _scale;
}

auto Average::scale(int64_t val) -> int64_t
{
    return scale(val, false);
}
int Average::_callback_set_Scale(sd_bus* bus, const char* path,
                                 const char* interface, const char* property,
                                 sd_bus_message* value, void* context,
                                 sd_bus_error* error)
{
    auto o = static_cast<Average*>(context);

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

        int64_t v{};
        m.read(v);
        o->scale(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Average
{
static const auto _property_Scale =
    utility::tuple_to_array(message::types::type_id<int64_t>());
}
} // namespace details

auto Average::unit() const -> Unit
{
    return _unit;
}

int Average::_callback_get_Unit(sd_bus* bus, const char* path,
                                const char* interface, const char* property,
                                sd_bus_message* reply, void* context,
                                sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Average*>(context);

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

        m.append(convertForMessage(o->unit()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Average::unit(Unit value, bool skipSignal) -> Unit
{
    if (_unit != value)
    {
        _unit = value;
        if (!skipSignal)
        {
            _org_open_power_Sensor_Aggregation_History_Average_interface
                .property_changed("Unit");
        }
    }

    return _unit;
}

auto Average::unit(Unit val) -> Unit
{
    return unit(val, false);
}
int Average::_callback_set_Unit(sd_bus* bus, const char* path,
                                const char* interface, const char* property,
                                sd_bus_message* value, void* context,
                                sd_bus_error* error)
{
    auto o = static_cast<Average*>(context);

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
        o->unit(convertUnitFromString(v));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Average
{
static const auto _property_Unit =
    utility::tuple_to_array(message::types::type_id<std::string>());
}
} // namespace details

auto Average::values() const -> std::vector<std::tuple<uint64_t, int64_t>>
{
    return _values;
}

int Average::_callback_get_Values(sd_bus* bus, const char* path,
                                  const char* interface, const char* property,
                                  sd_bus_message* reply, void* context,
                                  sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Average*>(context);

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

        m.append(convertForMessage(o->values()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Average::values(std::vector<std::tuple<uint64_t, int64_t>> value,
                     bool skipSignal)
    -> std::vector<std::tuple<uint64_t, int64_t>>
{
    if (_values != value)
    {
        _values = value;
        if (!skipSignal)
        {
            _org_open_power_Sensor_Aggregation_History_Average_interface
                .property_changed("Values");
        }
    }

    return _values;
}

auto Average::values(std::vector<std::tuple<uint64_t, int64_t>> val)
    -> std::vector<std::tuple<uint64_t, int64_t>>
{
    return values(val, false);
}
int Average::_callback_set_Values(sd_bus* bus, const char* path,
                                  const char* interface, const char* property,
                                  sd_bus_message* value, void* context,
                                  sd_bus_error* error)
{
    auto o = static_cast<Average*>(context);

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

        std::vector<std::tuple<uint64_t, int64_t>> v{};
        m.read(v);
        o->values(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Average
{
static const auto _property_Values = utility::tuple_to_array(
    message::types::type_id<std::vector<std::tuple<uint64_t, int64_t>>>());
}
} // namespace details

void Average::setPropertyByName(const std::string& _name,
                                const PropertiesVariant& val, bool skipSignal)
{
    if (_name == "Scale")
    {
        auto& v = std::get<int64_t>(val);
        scale(v, skipSignal);
        return;
    }
    if (_name == "Unit")
    {
        auto& v = std::get<Unit>(val);
        unit(v, skipSignal);
        return;
    }
    if (_name == "Values")
    {
        auto& v = std::get<std::vector<std::tuple<uint64_t, int64_t>>>(val);
        values(v, skipSignal);
        return;
    }
}

auto Average::getPropertyByName(const std::string& _name) -> PropertiesVariant
{
    if (_name == "Scale")
    {
        return scale();
    }
    if (_name == "Unit")
    {
        return unit();
    }
    if (_name == "Values")
    {
        return values();
    }

    return PropertiesVariant();
}

namespace
{
/** String to enum mapping for Average::Unit */
static const std::tuple<const char*, Average::Unit> mappingAverageUnit[] = {
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Average.Unit.DegreesC",
        Average::Unit::DegreesC),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Average.Unit.RPMS",
        Average::Unit::RPMS),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Average.Unit.Volts",
        Average::Unit::Volts),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Average.Unit.Meters",
        Average::Unit::Meters),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Average.Unit.Amperes",
        Average::Unit::Amperes),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Average.Unit.Watts",
        Average::Unit::Watts),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Average.Unit.Joules",
        Average::Unit::Joules),
};

} // anonymous namespace

auto Average::convertUnitFromString(const std::string& s) -> Unit
{
    auto i = std::find_if(
        std::begin(mappingAverageUnit), std::end(mappingAverageUnit),
        [&s](auto& e) { return 0 == strcmp(s.c_str(), std::get<0>(e)); });
    if (std::end(mappingAverageUnit) == i)
    {
        throw sdbusplus::exception::InvalidEnumString();
    }
    else
    {
        return std::get<1>(*i);
    }
}

std::string convertForMessage(Average::Unit v)
{
    auto i = std::find_if(std::begin(mappingAverageUnit),
                          std::end(mappingAverageUnit),
                          [v](auto& e) { return v == std::get<1>(e); });
    if (i == std::end(mappingAverageUnit))
    {
        throw std::invalid_argument(std::to_string(static_cast<int>(v)));
    }
    return std::get<0>(*i);
}

const vtable::vtable_t Average::_vtable[] = {
    vtable::start(),
    vtable::property("Scale", details::Average::_property_Scale.data(),
                     _callback_get_Scale, _callback_set_Scale,
                     vtable::property_::emits_change),
    vtable::property("Unit", details::Average::_property_Unit.data(),
                     _callback_get_Unit, _callback_set_Unit,
                     vtable::property_::emits_change),
    vtable::property("Values", details::Average::_property_Values.data(),
                     _callback_get_Values, _callback_set_Values,
                     vtable::property_::emits_change),
    vtable::end()};

} // namespace server
} // namespace History
} // namespace Aggregation
} // namespace Sensor
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <algorithm>
#include <map>
#include <org/open_power/Sensor/Aggregation/History/Maximum/server.hpp>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Sensor
{
namespace Aggregation
{
namespace History
{
namespace server
{

Maximum::Maximum(bus::bus& bus, const char* path) :
    _org_open_power_Sensor_Aggregation_History_Maximum_interface(
        bus, path, _interface, _vtable, this),
    _intf(bus.getInterface())
{
}

Maximum::Maximum(bus::bus& bus, const char* path,
                 const std::map<std::string, PropertiesVariant>& vals,
                 bool skipSignal) :
    Maximum(bus, path)
{
    for (const auto& v : vals)
    {
        setPropertyByName(v.first, v.second, skipSignal);
    }
}

auto Maximum::scale() const -> int64_t
{
    return _scale;
}

int Maximum::_callback_get_Scale(sd_bus* bus, const char* path,
                                 const char* interface, const char* property,
                                 sd_bus_message* reply, void* context,
                                 sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Maximum*>(context);

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

        m.append(convertForMessage(o->scale()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Maximum::scale(int64_t value, bool skipSignal) -> int64_t
{
    if (_scale != value)
    {
        _scale = value;
        if (!skipSignal)
        {
            _org_open_power_Sensor_Aggregation_History_Maximum_interface
                .property_changed("Scale");
        }
    }

    return _scale;
}

auto Maximum::scale(int64_t val) -> int64_t
{
    return scale(val, false);
}
int Maximum::_callback_set_Scale(sd_bus* bus, const char* path,
                                 const char* interface, const char* property,
                                 sd_bus_message* value, void* context,
                                 sd_bus_error* error)
{
    auto o = static_cast<Maximum*>(context);

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

        int64_t v{};
        m.read(v);
        o->scale(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Maximum
{
static const auto _property_Scale =
    utility::tuple_to_array(message::types::type_id<int64_t>());
}
} // namespace details

auto Maximum::unit() const -> Unit
{
    return _unit;
}

int Maximum::_callback_get_Unit(sd_bus* bus, const char* path,
                                const char* interface, const char* property,
                                sd_bus_message* reply, void* context,
                                sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Maximum*>(context);

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

        m.append(convertForMessage(o->unit()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Maximum::unit(Unit value, bool skipSignal) -> Unit
{
    if (_unit != value)
    {
        _unit = value;
        if (!skipSignal)
        {
            _org_open_power_Sensor_Aggregation_History_Maximum_interface
                .property_changed("Unit");
        }
    }

    return _unit;
}

auto Maximum::unit(Unit val) -> Unit
{
    return unit(val, false);
}
int Maximum::_callback_set_Unit(sd_bus* bus, const char* path,
                                const char* interface, const char* property,
                                sd_bus_message* value, void* context,
                                sd_bus_error* error)
{
    auto o = static_cast<Maximum*>(context);

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
        o->unit(convertUnitFromString(v));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Maximum
{
static const auto _property_Unit =
    utility::tuple_to_array(message::types::type_id<std::string>());
}
} // namespace details

auto Maximum::values() const -> std::vector<std::tuple<uint64_t, int64_t>>
{
    return _values;
}

int Maximum::_callback_get_Values(sd_bus* bus, const char* path,
                                  const char* interface, const char* property,
                                  sd_bus_message* reply, void* context,
                                  sd_bus_error* error)
{
    using sdbusplus::server::binding::details::convertForMessage;

    // TODO(venture): Can this except? I wouldn't think so.
    auto o = static_cast<Maximum*>(context);

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

        m.append(convertForMessage(o->values()));
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

auto Maximum::values(std::vector<std::tuple<uint64_t, int64_t>> value,
                     bool skipSignal)
    -> std::vector<std::tuple<uint64_t, int64_t>>
{
    if (_values != value)
    {
        _values = value;
        if (!skipSignal)
        {
            _org_open_power_Sensor_Aggregation_History_Maximum_interface
                .property_changed("Values");
        }
    }

    return _values;
}

auto Maximum::values(std::vector<std::tuple<uint64_t, int64_t>> val)
    -> std::vector<std::tuple<uint64_t, int64_t>>
{
    return values(val, false);
}
int Maximum::_callback_set_Values(sd_bus* bus, const char* path,
                                  const char* interface, const char* property,
                                  sd_bus_message* value, void* context,
                                  sd_bus_error* error)
{
    auto o = static_cast<Maximum*>(context);

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

        std::vector<std::tuple<uint64_t, int64_t>> v{};
        m.read(v);
        o->values(v);
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return o->_intf->sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Maximum
{
static const auto _property_Values = utility::tuple_to_array(
    message::types::type_id<std::vector<std::tuple<uint64_t, int64_t>>>());
}
} // namespace details

void Maximum::setPropertyByName(const std::string& _name,
                                const PropertiesVariant& val, bool skipSignal)
{
    if (_name == "Scale")
    {
        auto& v = std::get<int64_t>(val);
        scale(v, skipSignal);
        return;
    }
    if (_name == "Unit")
    {
        auto& v = std::get<Unit>(val);
        unit(v, skipSignal);
        return;
    }
    if (_name == "Values")
    {
        auto& v = std::get<std::vector<std::tuple<uint64_t, int64_t>>>(val);
        values(v, skipSignal);
        return;
    }
}

auto Maximum::getPropertyByName(const std::string& _name) -> PropertiesVariant
{
    if (_name == "Scale")
    {
        return scale();
    }
    if (_name == "Unit")
    {
        return unit();
    }
    if (_name == "Values")
    {
        return values();
    }

    return PropertiesVariant();
}

namespace
{
/** String to enum mapping for Maximum::Unit */
static const std::tuple<const char*, Maximum::Unit> mappingMaximumUnit[] = {
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Maximum.Unit.DegreesC",
        Maximum::Unit::DegreesC),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Maximum.Unit.RPMS",
        Maximum::Unit::RPMS),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Maximum.Unit.Volts",
        Maximum::Unit::Volts),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Maximum.Unit.Meters",
        Maximum::Unit::Meters),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Maximum.Unit.Amperes",
        Maximum::Unit::Amperes),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Maximum.Unit.Watts",
        Maximum::Unit::Watts),
    std::make_tuple(
        "org.open_power.Sensor.Aggregation.History.Maximum.Unit.Joules",
        Maximum::Unit::Joules),
};

} // anonymous namespace

auto Maximum::convertUnitFromString(const std::string& s) -> Unit
{
    auto i = std::find_if(
        std::begin(mappingMaximumUnit), std::end(mappingMaximumUnit),
        [&s](auto& e) { return 0 == strcmp(s.c_str(), std::get<0>(e)); });
    if (std::end(mappingMaximumUnit) == i)
    {
        throw sdbusplus::exception::InvalidEnumString();
    }
    else
    {
        return std::get<1>(*i);
    }
}

std::string convertForMessage(Maximum::Unit v)
{
    auto i = std::find_if(std::begin(mappingMaximumUnit),
                          std::end(mappingMaximumUnit),
                          [v](auto& e) { return v == std::get<1>(e); });
    if (i == std::end(mappingMaximumUnit))
    {
        throw std::invalid_argument(std::to_string(static_cast<int>(v)));
    }
    return std::get<0>(*i);
}

const vtable::vtable_t Maximum::_vtable[] = {
    vtable::start(),
    vtable::property("Scale", details::Maximum::_property_Scale.data(),
                     _callback_get_Scale, _callback_set_Scale,
                     vtable::property_::emits_change),
    vtable::property("Unit", details::Maximum::_property_Unit.data(),
                     _callback_get_Unit, _callback_set_Unit,
                     vtable::property_::emits_change),
    vtable::property("Values", details::Maximum::_property_Values.data(),
                     _callback_get_Values, _callback_set_Values,
                     vtable::property_::emits_change),
    vtable::end()};

} // namespace server
} // namespace History
} // namespace Aggregation
} // namespace Sensor
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <org/open_power/Proc/FSI/error.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Proc
{
namespace FSI
{
namespace Error
{
const char* MasterDetectionFailure::name() const noexcept
{
    return errName;
}
const char* MasterDetectionFailure::description() const noexcept
{
    return errDesc;
}
const char* MasterDetectionFailure::what() const noexcept
{
    return errWhat;
}
const char* SlaveDetectionFailure::name() const noexcept
{
    return errName;
}
const char* SlaveDetectionFailure::description() const noexcept
{
    return errDesc;
}
const char* SlaveDetectionFailure::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace FSI
} // namespace Proc
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <org/open_power/Host/Access/error.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Host
{
namespace Access
{
namespace Error
{
const char* WriteCFAM::name() const noexcept
{
    return errName;
}
const char* WriteCFAM::description() const noexcept
{
    return errDesc;
}
const char* WriteCFAM::what() const noexcept
{
    return errWhat;
}
const char* ReadCFAM::name() const noexcept
{
    return errName;
}
const char* ReadCFAM::description() const noexcept
{
    return errDesc;
}
const char* ReadCFAM::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace Access
} // namespace Host
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <org/open_power/Common/Callout/error.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Common
{
namespace Callout
{
namespace Error
{
const char* Procedure::name() const noexcept
{
    return errName;
}
const char* Procedure::description() const noexcept
{
    return errDesc;
}
const char* Procedure::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace Callout
} // namespace Common
} // namespace open_power
} // namespace org
} // namespace sdbusplus

#include <org/open_power/Host/error.hpp>

namespace sdbusplus
{
namespace org
{
namespace open_power
{
namespace Host
{
namespace Error
{
const char* Event::name() const noexcept
{
    return errName;
}
const char* Event::description() const noexcept
{
    return errDesc;
}
const char* Event::what() const noexcept
{
    return errWhat;
}
const char* MaintenanceProcedure::name() const noexcept
{
    return errName;
}
const char* MaintenanceProcedure::description() const noexcept
{
    return errDesc;
}
const char* MaintenanceProcedure::what() const noexcept
{
    return errWhat;
}

} // namespace Error
} // namespace Host
} // namespace open_power
} // namespace org
} // namespace sdbusplus
