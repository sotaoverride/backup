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
namespace Time
{
namespace server
{

class EpochTime
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
        EpochTime() = delete;
        EpochTime(const EpochTime&) = delete;
        EpochTime& operator=(const EpochTime&) = delete;
        EpochTime(EpochTime&&) = delete;
        EpochTime& operator=(EpochTime&&) = delete;
        virtual ~EpochTime() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        EpochTime(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                uint64_t>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        EpochTime(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of Elapsed */
        virtual uint64_t elapsed() const;
        /** Set value of Elapsed with option to skip sending signal */
        virtual uint64_t elapsed(uint64_t value,
               bool skipSignal);
        /** Set value of Elapsed */
        virtual uint64_t elapsed(uint64_t value);

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

        /** @brief sd-bus callback for get-property 'Elapsed' */
        static int _callback_get_Elapsed(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Elapsed' */
        static int _callback_set_Elapsed(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Time.EpochTime";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Time_EpochTime_interface;
        sdbusplus::SdBusInterface *_intf;

        uint64_t _elapsed{};

};


} // namespace server
} // namespace Time
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

