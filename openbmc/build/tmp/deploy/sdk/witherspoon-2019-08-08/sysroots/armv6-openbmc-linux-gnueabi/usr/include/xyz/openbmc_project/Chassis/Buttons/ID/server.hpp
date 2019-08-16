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
namespace Chassis
{
namespace Buttons
{
namespace server
{

class ID
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
        ID() = delete;
        ID(const ID&) = delete;
        ID& operator=(const ID&) = delete;
        ID(ID&&) = delete;
        ID& operator=(ID&&) = delete;
        virtual ~ID() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        ID(bus::bus& bus, const char* path);



        /** @brief Implementation for simPress
         *  Emulate ID button press.
         */
        virtual void simPress(
            ) = 0;


        /** @brief Send signal 'Released'
         *
         *  ID button released signal
         */
        void released(
            );

        /** @brief Send signal 'Pressed'
         *
         *  ID button pressed signal
         */
        void pressed(
            );



    private:

        /** @brief sd-bus callback for simPress
         */
        static int _callback_SimPress(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Chassis.Buttons.ID";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Chassis_Buttons_ID_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Buttons
} // namespace Chassis
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

