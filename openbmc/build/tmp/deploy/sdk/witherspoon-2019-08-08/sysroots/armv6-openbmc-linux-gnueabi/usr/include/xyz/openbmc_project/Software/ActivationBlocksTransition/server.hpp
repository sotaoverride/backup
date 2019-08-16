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
namespace Software
{
namespace server
{

class ActivationBlocksTransition
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
        ActivationBlocksTransition() = delete;
        ActivationBlocksTransition(const ActivationBlocksTransition&) = delete;
        ActivationBlocksTransition& operator=(const ActivationBlocksTransition&) = delete;
        ActivationBlocksTransition(ActivationBlocksTransition&&) = delete;
        ActivationBlocksTransition& operator=(ActivationBlocksTransition&&) = delete;
        virtual ~ActivationBlocksTransition() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        ActivationBlocksTransition(bus::bus& bus, const char* path);






    private:


        static constexpr auto _interface = "xyz.openbmc_project.Software.ActivationBlocksTransition";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Software_ActivationBlocksTransition_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Software
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

