#pragma once
#include <map>
#include <string>
#include <sdbusplus/sdbus.hpp>
#include <sdbusplus/server.hpp>
#include <systemd/sd-bus.h>
#include <tuple>
#include <variant>

#include <xyz/openbmc_project/Network/IP/server.hpp>

namespace sdbusplus
{
namespace xyz
{
namespace openbmc_project
{
namespace Network
{
namespace IP
{
namespace server
{

class Create
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
        Create() = delete;
        Create(const Create&) = delete;
        Create& operator=(const Create&) = delete;
        Create(Create&&) = delete;
        Create& operator=(Create&&) = delete;
        virtual ~Create() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Create(bus::bus& bus, const char* path);



        /** @brief Implementation for IP
         *  Create ipaddress object.
         *
         *  @param[in] protocolType - protocol type can be IPv4 or IPv6 etc.
         *  @param[in] address - IP Address.
         *  @param[in] prefixLength - Prefix Length.
         *  @param[in] gateway - Gateway Address.
         *
         *  @return path[sdbusplus::message::object_path] - The path for the created ipaddress object.
         */
        virtual sdbusplus::message::object_path iP(
            xyz::openbmc_project::Network::server::IP::Protocol protocolType,
            std::string address,
            uint8_t prefixLength,
            std::string gateway) = 0;




    private:

        /** @brief sd-bus callback for IP
         */
        static int _callback_IP(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Network.IP.Create";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Network_IP_Create_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace IP
} // namespace Network
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus
