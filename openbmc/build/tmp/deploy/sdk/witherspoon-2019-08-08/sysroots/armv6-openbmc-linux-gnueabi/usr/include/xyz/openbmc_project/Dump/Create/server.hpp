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
namespace Dump
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



        /** @brief Implementation for CreateDump
         *  Method to create BMC Dump.
         *
         *  @return id[uint32_t] - The Dump entry id number.
         */
        virtual uint32_t createDump(
            ) = 0;




    private:

        /** @brief sd-bus callback for CreateDump
         */
        static int _callback_CreateDump(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Dump.Create";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Dump_Create_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Dump
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

