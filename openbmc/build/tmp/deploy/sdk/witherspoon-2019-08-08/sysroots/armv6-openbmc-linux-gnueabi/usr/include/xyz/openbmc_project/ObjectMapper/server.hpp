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
namespace server
{

class ObjectMapper
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
        ObjectMapper() = delete;
        ObjectMapper(const ObjectMapper&) = delete;
        ObjectMapper& operator=(const ObjectMapper&) = delete;
        ObjectMapper(ObjectMapper&&) = delete;
        ObjectMapper& operator=(ObjectMapper&&) = delete;
        virtual ~ObjectMapper() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        ObjectMapper(bus::bus& bus, const char* path);



        /** @brief Implementation for GetObject
         *  Obtain a dictionary of service -> implemented interface(s) for the given path.
         *
         *  @param[in] path - The object path for which the result should be fetched.
         *  @param[in] interfaces - An array of result set constraining interfaces.
         *
         *  @return services[std::map<std::string, std::vector<std::string>>] - A dictionary of service -> implemented interface(s).
         */
        virtual std::map<std::string, std::vector<std::string>> getObject(
            sdbusplus::message::object_path path,
            std::vector<std::string> interfaces) = 0;

        /** @brief Implementation for GetAncestors
         *  Obtain a dictionary of ancestor -> services where ancestor is an ancestor of path and services is of the type returned by the GetObject method.
         *
         *  @param[in] path - The path for which the result should be fetched.
         *  @param[in] interfaces - An array of result set constraining interfaces.
         *
         *  @return ancestors[std::map<sdbusplus::message::object_path, std::map<std::string, std::vector<std::string>>>] - A dictionary of ancestor -> services.
         */
        virtual std::map<sdbusplus::message::object_path, std::map<std::string, std::vector<std::string>>> getAncestors(
            sdbusplus::message::object_path path,
            std::vector<std::string> interfaces) = 0;

        /** @brief Implementation for GetSubTree
         *  Obtain a dictionary of path -> services where path is in sutbtree and services is of the type returned by the GetObject method.
         *
         *  @param[in] subtree - The subtree path for which the result should be fetched.
         *  @param[in] depth - The maximum subtree depth for which results should be fetched. For unconstrained fetches use a depth of zero.
         *  @param[in] interfaces - An array of result set constraining interfaces.
         *
         *  @return objects[std::map<sdbusplus::message::object_path, std::map<std::string, std::vector<std::string>>>] - A dictionary of path -> services.
         */
        virtual std::map<sdbusplus::message::object_path, std::map<std::string, std::vector<std::string>>> getSubTree(
            sdbusplus::message::object_path subtree,
            int32_t depth,
            std::vector<std::string> interfaces) = 0;

        /** @brief Implementation for GetSubTreePaths
         *  Obtain an array of paths where array elements are in subtree.
         *
         *  @param[in] subtree - The subtree path for which the result should be fetched.
         *  @param[in] depth - The maximum subtree depth for which results should be fetched. For unconstrained fetches use a depth of zero.
         *  @param[in] interfaces - An array of result set constraining interfaces.
         *
         *  @return paths[std::vector<sdbusplus::message::object_path>] - An array of paths.
         */
        virtual std::vector<sdbusplus::message::object_path> getSubTreePaths(
            sdbusplus::message::object_path subtree,
            int32_t depth,
            std::vector<std::string> interfaces) = 0;




    private:

        /** @brief sd-bus callback for GetObject
         */
        static int _callback_GetObject(
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for GetAncestors
         */
        static int _callback_GetAncestors(
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for GetSubTree
         */
        static int _callback_GetSubTree(
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for GetSubTreePaths
         */
        static int _callback_GetSubTreePaths(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.ObjectMapper";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_ObjectMapper_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

