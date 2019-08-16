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
namespace User
{
namespace server
{

class PrivilegeMapper
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
        PrivilegeMapper() = delete;
        PrivilegeMapper(const PrivilegeMapper&) = delete;
        PrivilegeMapper& operator=(const PrivilegeMapper&) = delete;
        PrivilegeMapper(PrivilegeMapper&&) = delete;
        PrivilegeMapper& operator=(PrivilegeMapper&&) = delete;
        virtual ~PrivilegeMapper() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        PrivilegeMapper(bus::bus& bus, const char* path);



        /** @brief Implementation for Create
         *  Creates a mapping for the group to the privilege.
         *
         *  @param[in] groupName - Group Name to which the privilege is to be assigned. In the case of LDAP, the GroupName will be the LDAP group the user is part of.
         *  @param[in] privilege - The privilege associated with the group. The set of available privileges are xyz.openbmc_project.User.Manager.AllPrivileges. xyz.openbmc_project.Common.Error.InvalidArgument exception will be thrown if the privilege is invalid. Additional documentation on privilege is available here. https://github.com/openbmc/docs/blob/master/user_management.md
         *
         *  @return path[sdbusplus::message::object_path] - The path for the created privilege mapping object.
         */
        virtual sdbusplus::message::object_path create(
            std::string groupName,
            std::string privilege) = 0;




    private:

        /** @brief sd-bus callback for Create
         */
        static int _callback_Create(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.User.PrivilegeMapper";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_User_PrivilegeMapper_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace User
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

