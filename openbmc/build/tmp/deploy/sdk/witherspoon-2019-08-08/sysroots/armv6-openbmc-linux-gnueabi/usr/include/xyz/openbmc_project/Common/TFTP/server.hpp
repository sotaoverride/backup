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

class TFTP
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
        TFTP() = delete;
        TFTP(const TFTP&) = delete;
        TFTP& operator=(const TFTP&) = delete;
        TFTP(TFTP&&) = delete;
        TFTP& operator=(TFTP&&) = delete;
        virtual ~TFTP() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        TFTP(bus::bus& bus, const char* path);



        /** @brief Implementation for DownloadViaTFTP
         *  Download a file via TFTP.
         *
         *  @param[in] fileName - The name of the file to transfer.
         *  @param[in] serverAddress - The TFTP Server IP Address.
         */
        virtual void downloadViaTFTP(
            std::string fileName,
            std::string serverAddress) = 0;




    private:

        /** @brief sd-bus callback for DownloadViaTFTP
         */
        static int _callback_DownloadViaTFTP(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Common.TFTP";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Common_TFTP_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Common
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

