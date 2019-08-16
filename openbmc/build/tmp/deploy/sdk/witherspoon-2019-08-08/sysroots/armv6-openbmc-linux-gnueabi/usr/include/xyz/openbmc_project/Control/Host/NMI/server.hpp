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
namespace Control
{
namespace Host
{
namespace server
{

class NMI
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
        NMI() = delete;
        NMI(const NMI&) = delete;
        NMI& operator=(const NMI&) = delete;
        NMI(NMI&&) = delete;
        NMI& operator=(NMI&&) = delete;
        virtual ~NMI() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        NMI(bus::bus& bus, const char* path);



        /** @brief Implementation for NMI
         *  Generic method to initiate non maskable interrupt on all host processors.
         */
        virtual void nMI(
            ) = 0;




    private:

        /** @brief sd-bus callback for NMI
         */
        static int _callback_NMI(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Control.Host.NMI";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Control_Host_NMI_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Host
} // namespace Control
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

