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
namespace Certs
{
namespace server
{

class Install
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
        Install() = delete;
        Install(const Install&) = delete;
        Install& operator=(const Install&) = delete;
        Install(Install&&) = delete;
        Install& operator=(Install&&) = delete;
        virtual ~Install() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Install(bus::bus& bus, const char* path);



        /** @brief Implementation for Install
         *  Install the certificate and restart the associated services. NotAllowed error thrown if certificate already exists.
         *
         *  @param[in] path - Path of file that contains both the certificate public and private key. (Example: a .PEM file containing both signed certificate and private key).
         */
        virtual void install(
            std::string path) = 0;




    private:

        /** @brief sd-bus callback for Install
         */
        static int _callback_Install(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Certs.Install";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Certs_Install_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Certs
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

