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

class CSR
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
        CSR() = delete;
        CSR(const CSR&) = delete;
        CSR& operator=(const CSR&) = delete;
        CSR(CSR&&) = delete;
        CSR& operator=(CSR&&) = delete;
        virtual ~CSR() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        CSR(bus::bus& bus, const char* path);



        /** @brief Implementation for CSR
         *  Method to get the CSR string.
Object which implements this interface should implement xyz.openbmc_project.Object.Delete to allow the deletion of CSR objects.
         *
         *  @return cSRString[std::string] - CSR string in the Base-64 encoded PEM format.
         */
        virtual std::string cSR(
            ) = 0;




    private:

        /** @brief sd-bus callback for CSR
         */
        static int _callback_CSR(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Certs.CSR";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Certs_CSR_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Certs
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

