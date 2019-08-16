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
namespace Common
{
namespace server
{

class FactoryReset
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
        FactoryReset() = delete;
        FactoryReset(const FactoryReset&) = delete;
        FactoryReset& operator=(const FactoryReset&) = delete;
        FactoryReset(FactoryReset&&) = delete;
        FactoryReset& operator=(FactoryReset&&) = delete;
        virtual ~FactoryReset() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        FactoryReset(bus::bus& bus, const char* path);



        /** @brief Implementation for Reset
         *  Generic method to start factory reset. Implemented by each service.
         */
        virtual void reset(
            ) = 0;




    private:

        /** @brief sd-bus callback for Reset
         */
        static int _callback_Reset(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Common.FactoryReset";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Common_FactoryReset_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

