#pragma once
#include <map>
#include <string>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <systemd/sd-bus.h>
#include <tuple>
#include <variant>


namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Network
{
namespace Neighbor
{
namespace server
{

class CreateStatic
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
        CreateStatic() = delete;
        CreateStatic(const CreateStatic&) = delete;
        CreateStatic& operator=(const CreateStatic&) = delete;
        CreateStatic(CreateStatic&&) = delete;
        CreateStatic& operator=(CreateStatic&&) = delete;
        virtual ~CreateStatic() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        CreateStatic(bus::bus& bus, const char* path);



        /** @brief Implementation for Neighbor
         *  Create a static neighbor entry.
         *
         *  @param[in] iPAddress - IP Address.
         *  @param[in] mACAddress - MAC Address.
         *
         *  @return path[sdbusplus::message::object_path] - The path for the created neighbor object.
         */
        virtual sdbusplus::message::object_path neighbor(
            std::string iPAddress,
            std::string mACAddress) = 0;




    private:

        /** @brief sd-bus callback for Neighbor
         */
        static int _callback_Neighbor(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Network.Neighbor.CreateStatic";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Network_Neighbor_CreateStatic_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Neighbor
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

