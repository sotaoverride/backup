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
namespace Object
{
namespace server
{

class Delete
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
        Delete() = delete;
        Delete(const Delete&) = delete;
        Delete& operator=(const Delete&) = delete;
        Delete(Delete&&) = delete;
        Delete& operator=(Delete&&) = delete;
        virtual ~Delete() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Delete(bus::bus& bus, const char* path);



        /** @brief Implementation for Delete
         *  Delete the object implementing Delete.
         */
        virtual void delete_(
            ) = 0;




    private:

        /** @brief sd-bus callback for Delete
         */
        static int _callback_Delete(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Object.Delete";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Object_Delete_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Object
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

