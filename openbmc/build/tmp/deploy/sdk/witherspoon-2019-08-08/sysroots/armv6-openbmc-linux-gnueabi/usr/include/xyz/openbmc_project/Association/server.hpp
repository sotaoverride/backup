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

class Association
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
        Association() = delete;
        Association(const Association&) = delete;
        Association& operator=(const Association&) = delete;
        Association(Association&&) = delete;
        Association& operator=(Association&&) = delete;
        virtual ~Association() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Association(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                std::vector<sdbusplus::message::object_path>>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        Association(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of Endpoints */
        virtual std::vector<sdbusplus::message::object_path> endpoints() const;
        /** Set value of Endpoints with option to skip sending signal */
        virtual std::vector<sdbusplus::message::object_path> endpoints(std::vector<sdbusplus::message::object_path> value,
               bool skipSignal);
        /** Set value of Endpoints */
        virtual std::vector<sdbusplus::message::object_path> endpoints(std::vector<sdbusplus::message::object_path> value);

        /** @brief Sets a property by name.
         *  @param[in] _name - A string representation of the property name.
         *  @param[in] val - A variant containing the value to set.
         */
        void setPropertyByName(const std::string& _name,
                               const PropertiesVariant& val,
                               bool skipSignal = false);

        /** @brief Gets a property by name.
         *  @param[in] _name - A string representation of the property name.
         *  @return - A variant containing the value of the property.
         */
        PropertiesVariant getPropertyByName(const std::string& _name);


    private:

        /** @brief sd-bus callback for get-property 'Endpoints' */
        static int _callback_get_Endpoints(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Endpoints' */
        static int _callback_set_Endpoints(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Association";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Association_interface;
        sdbusplus::SdBusInterface *_intf;

        std::vector<sdbusplus::message::object_path> _endpoints{};

};


} // namespace server
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

