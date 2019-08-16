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
namespace Collection
{
namespace server
{

class DeleteAll
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
        DeleteAll() = delete;
        DeleteAll(const DeleteAll&) = delete;
        DeleteAll& operator=(const DeleteAll&) = delete;
        DeleteAll(DeleteAll&&) = delete;
        DeleteAll& operator=(DeleteAll&&) = delete;
        virtual ~DeleteAll() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        DeleteAll(bus::bus& bus, const char* path);



        /** @brief Implementation for DeleteAll
         *  Delete all objects in the collection.
         */
        virtual void deleteAll(
            ) = 0;




    private:

        /** @brief sd-bus callback for DeleteAll
         */
        static int _callback_DeleteAll(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Collection.DeleteAll";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Collection_DeleteAll_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Collection
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

