#include <algorithm>
#include <map>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>
#include <xyz/openbmc_project/Common/error.hpp>
#include <xyz/openbmc_project/Network/Client/Create/server.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Network
{
namespace Client
{
namespace server
{

Create::Create(bus::bus& bus, const char* path) :
    _xyz_openbmc_project_Network_Client_Create_interface(bus, path, _interface,
                                                         _vtable, this),
    _intf(bus.getInterface())
{
}

int Create::_callback_Client(sd_bus_message* msg, void* context,
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

        std::string address{};
        uint16_t port{};

        m.read(address, port);

        auto o = static_cast<Create*>(context);
        auto r = o->client(address, port);

        auto reply = m.new_method_return();
        reply.append(convertForMessage(std::move(r)));

        reply.method_return();
    }
    catch (sdbusplus::internal_exception_t& e)
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
namespace Create
{
static const auto _param_Client =
    utility::tuple_to_array(message::types::type_id<std::string, uint16_t>());
static const auto _return_Client =
    utility::tuple_to_array(message::types::type_id<std::string>());
} // namespace Create
} // namespace details

const vtable::vtable_t Create::_vtable[] = {
    vtable::start(),

    vtable::method("Client", details::Create::_param_Client.data(),
                   details::Create::_return_Client.data(), _callback_Client),
    vtable::end()};

} // namespace server
} // namespace Client
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
