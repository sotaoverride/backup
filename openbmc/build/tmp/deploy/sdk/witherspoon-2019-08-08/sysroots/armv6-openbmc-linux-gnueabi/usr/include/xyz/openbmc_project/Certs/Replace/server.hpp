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

class Replace
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
        Replace() = delete;
        Replace(const Replace&) = delete;
        Replace& operator=(const Replace&) = delete;
        Replace(Replace&&) = delete;
        Replace& operator=(Replace&&) = delete;
        virtual ~Replace() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Replace(bus::bus& bus, const char* path);



        /** @brief Implementation for Replace
         *  Replace the certificate and restart the associated services.
         *
         *  @param[in] path - Path of file that contains both the certificate public and private key. (Example: a .PEM file containing both signed certificate and private key).
         */
        virtual void replace(
            std::string path) = 0;




    private:

        /** @brief sd-bus callback for Replace
         */
        static int _callback_Replace(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Certs.Replace";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Certs_Replace_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Certs
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

