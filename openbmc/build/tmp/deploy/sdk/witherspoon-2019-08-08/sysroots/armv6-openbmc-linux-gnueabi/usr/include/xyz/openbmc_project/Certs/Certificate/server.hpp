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

class Certificate
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
        Certificate() = delete;
        Certificate(const Certificate&) = delete;
        Certificate& operator=(const Certificate&) = delete;
        Certificate(Certificate&&) = delete;
        Certificate& operator=(Certificate&&) = delete;
        virtual ~Certificate() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Certificate(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                uint64_t,
                std::vector<std::string>,
                std::string>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        Certificate(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of CertificateString */
        virtual std::string certificateString() const;
        /** Set value of CertificateString with option to skip sending signal */
        virtual std::string certificateString(std::string value,
               bool skipSignal);
        /** Set value of CertificateString */
        virtual std::string certificateString(std::string value);
        /** Get value of KeyUsage */
        virtual std::vector<std::string> keyUsage() const;
        /** Set value of KeyUsage with option to skip sending signal */
        virtual std::vector<std::string> keyUsage(std::vector<std::string> value,
               bool skipSignal);
        /** Set value of KeyUsage */
        virtual std::vector<std::string> keyUsage(std::vector<std::string> value);
        /** Get value of Issuer */
        virtual std::string issuer() const;
        /** Set value of Issuer with option to skip sending signal */
        virtual std::string issuer(std::string value,
               bool skipSignal);
        /** Set value of Issuer */
        virtual std::string issuer(std::string value);
        /** Get value of Subject */
        virtual std::string subject() const;
        /** Set value of Subject with option to skip sending signal */
        virtual std::string subject(std::string value,
               bool skipSignal);
        /** Set value of Subject */
        virtual std::string subject(std::string value);
        /** Get value of ValidNotAfter */
        virtual uint64_t validNotAfter() const;
        /** Set value of ValidNotAfter with option to skip sending signal */
        virtual uint64_t validNotAfter(uint64_t value,
               bool skipSignal);
        /** Set value of ValidNotAfter */
        virtual uint64_t validNotAfter(uint64_t value);
        /** Get value of ValidNotBefore */
        virtual uint64_t validNotBefore() const;
        /** Set value of ValidNotBefore with option to skip sending signal */
        virtual uint64_t validNotBefore(uint64_t value,
               bool skipSignal);
        /** Set value of ValidNotBefore */
        virtual uint64_t validNotBefore(uint64_t value);

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

        /** @brief sd-bus callback for get-property 'CertificateString' */
        static int _callback_get_CertificateString(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'CertificateString' */
        static int _callback_set_CertificateString(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'KeyUsage' */
        static int _callback_get_KeyUsage(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'KeyUsage' */
        static int _callback_set_KeyUsage(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Issuer' */
        static int _callback_get_Issuer(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Issuer' */
        static int _callback_set_Issuer(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Subject' */
        static int _callback_get_Subject(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Subject' */
        static int _callback_set_Subject(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'ValidNotAfter' */
        static int _callback_get_ValidNotAfter(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'ValidNotAfter' */
        static int _callback_set_ValidNotAfter(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'ValidNotBefore' */
        static int _callback_get_ValidNotBefore(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'ValidNotBefore' */
        static int _callback_set_ValidNotBefore(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Certs.Certificate";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Certs_Certificate_interface;
        sdbusplus::SdBusInterface *_intf;

        std::string _certificateString{};
        std::vector<std::string> _keyUsage{};
        std::string _issuer{};
        std::string _subject{};
        uint64_t _validNotAfter{};
        uint64_t _validNotBefore{};

};


} // namespace server
} // namespace Certs
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

