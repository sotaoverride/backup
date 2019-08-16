#include <algorithm>
#include <map>
#include <sdbusplus/exception.hpp>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <string>
#include <tuple>
#include <variant>
#include <xyz/openbmc_project/Common/File/error.hpp>
#include <xyz/openbmc_project/Dump/Create/error.hpp>
#include <xyz/openbmc_project/Dump/Internal/Create/server.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Dump
{
namespace Internal
{
namespace server
{

Create::Create(bus::bus& bus, const char* path) :
    _xyz_openbmc_project_Dump_Internal_Create_interface(bus, path, _interface,
                                                        _vtable, this),
    _intf(bus.getInterface())
{
}

int Create::_callback_Create(sd_bus_message* msg, void* context,
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

        std::string type{};
        std::vector<std::string> fullPaths{};

        m.read(type, fullPaths);

        auto o = static_cast<Create*>(context);
        o->create(convertTypeFromString(type), fullPaths);

        auto reply = m.new_method_return();
        // No data to append on reply.

        reply.method_return();
    }
    catch (sdbusplus::internal_exception_t& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }
    catch (sdbusplus::xyz::openbmc_project::Common::File::Error::Write& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }
    catch (sdbusplus::xyz::openbmc_project::Dump::Create::Error::Disabled& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }
    catch (
        sdbusplus::xyz::openbmc_project::Dump::Create::Error::QuotaExceeded& e)
    {
        return sd_bus_error_set(error, e.name(), e.description());
    }

    return true;
}

namespace details
{
namespace Create
{
static const auto _param_Create = utility::tuple_to_array(
    message::types::type_id<std::string, std::vector<std::string>>());
static const auto _return_Create =
    utility::tuple_to_array(std::make_tuple('\0'));
} // namespace Create
} // namespace details

namespace
{
/** String to enum mapping for Create::Type */
static const std::tuple<const char*, Create::Type> mappingCreateType[] = {
    std::make_tuple(
        "xyz.openbmc_project.Dump.Internal.Create.Type.ApplicationCored",
        Create::Type::ApplicationCored),
    std::make_tuple(
        "xyz.openbmc_project.Dump.Internal.Create.Type.UserRequested",
        Create::Type::UserRequested),
    std::make_tuple(
        "xyz.openbmc_project.Dump.Internal.Create.Type.InternalFailure",
        Create::Type::InternalFailure),
    std::make_tuple("xyz.openbmc_project.Dump.Internal.Create.Type.Checkstop",
                    Create::Type::Checkstop),
};

} // anonymous namespace

auto Create::convertTypeFromString(const std::string& s) -> Type
{
    auto i = std::find_if(
        std::begin(mappingCreateType), std::end(mappingCreateType),
        [&s](auto& e) { return 0 == strcmp(s.c_str(), std::get<0>(e)); });
    if (std::end(mappingCreateType) == i)
    {
        throw sdbusplus::exception::InvalidEnumString();
    }
    else
    {
        return std::get<1>(*i);
    }
}

std::string convertForMessage(Create::Type v)
{
    auto i =
        std::find_if(std::begin(mappingCreateType), std::end(mappingCreateType),
                     [v](auto& e) { return v == std::get<1>(e); });
    if (i == std::end(mappingCreateType))
    {
        throw std::invalid_argument(std::to_string(static_cast<int>(v)));
    }
    return std::get<0>(*i);
}

const vtable::vtable_t Create::_vtable[] = {
    vtable::start(),

    vtable::method("Create", details::Create::_param_Create.data(),
                   details::Create::_return_Create.data(), _callback_Create),
    vtable::end()};

} // namespace server
} // namespace Internal
} // namespace Dump
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
