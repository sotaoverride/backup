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
namespace Logging
{
namespace server
{

class IPMI
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
        IPMI() = delete;
        IPMI(const IPMI&) = delete;
        IPMI& operator=(const IPMI&) = delete;
        IPMI(IPMI&&) = delete;
        IPMI& operator=(IPMI&&) = delete;
        virtual ~IPMI() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        IPMI(bus::bus& bus, const char* path);



        /** @brief Implementation for IpmiSelAdd
         *  Log a system event record type SEL entry.
         *
         *  @param[in] message - The text to log for the event.
         *  @param[in] path - The object path that is generating the SEL entry.
         *  @param[in] sELData - An array of up to 3 bytes of SEL event data.
         *  @param[in] assert - An indicator if the SEL event is asserting or de-asserting.
         *  @param[in] generatorID - The Generator ID of the component requesting the new SEL entry. In most cases this will be 0x20 (the BMC Generator ID).
         *
         *  @return recordID[uint16_t] - The Record ID of the new SEL entry.
         */
        virtual uint16_t ipmiSelAdd(
            std::string message,
            sdbusplus::message::object_path path,
            std::vector<uint8_t> sELData,
            bool assert,
            uint16_t generatorID) = 0;

        /** @brief Implementation for IpmiSelAddOem
         *  Log an OEM record type SEL entry requested from external to the BMC.
         *
         *  @param[in] message - The text to log for the event.
         *  @param[in] sELData - An array of up to 13 bytes of SEL event data.
         *  @param[in] recordType - The OEM record type for the SEL entry.
         *
         *  @return recordID[uint16_t] - The Record ID of the new SEL entry.
         */
        virtual uint16_t ipmiSelAddOem(
            std::string message,
            std::vector<uint8_t> sELData,
            uint8_t recordType) = 0;




    private:

        /** @brief sd-bus callback for IpmiSelAdd
         */
        static int _callback_IpmiSelAdd(
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for IpmiSelAddOem
         */
        static int _callback_IpmiSelAddOem(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Logging.IPMI";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Logging_IPMI_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace Logging
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

