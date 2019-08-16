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
namespace CSR
{
namespace server
{

class Create
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
        Create() = delete;
        Create(const Create&) = delete;
        Create& operator=(const Create&) = delete;
        Create(Create&&) = delete;
        Create& operator=(Create&&) = delete;
        virtual ~Create() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        Create(bus::bus& bus, const char* path);



        /** @brief Implementation for GenerateCSR
         *  This command is used to initiate a certificate signing request. This command only returns the D-Bus path name for the new CSR object. User need to listen on InterfacesAdded signal emitted by /xyz/openbmc_project/Certs to retrieve the CSR string after successful CSR creation.
Note: Following Parameters are mandatory or optional based on the
      Redfish documentation.

      Caller is responsible for the input parameter validation.

      If the caller does not wish a field to be included in the
      CSR Request, initialize the Parameter with blank for strings
      and zero for integers.
         *
         *  @param[in] alternativeNames - Additional hostnames of the component that is being secured.
         *  @param[in] challengePassword - The challenge password to be applied to the certificate for revocation requests.
         *  @param[in] city - The city or locality of the organization making the request. For Example Austin This is a required parameter.
         *  @param[in] commonName - The fully qualified domain name of the component that is being secured. This is a required parameter.
         *  @param[in] contactPerson - The name of the user making the request.
         *  @param[in] country - The country of the organization making the request. This is a required parameter.
         *  @param[in] email - The email address of the contact within the organization making the request.
         *  @param[in] givenName - The given name of the user making the request.
         *  @param[in] initials - The initials of the user making the request.
         *  @param[in] keyBitLength - The length of the key in bits, if needed based on the value of the KeyPairAlgorithm parameter.
Refer https://www.openssl.org/docs/man1.0.2/man1/genpkey.html
         *  @param[in] keyCurveId - The curve ID to be used with the key, if needed based on the value of the KeyPairAlgorithm parameter.
Refer https://www.openssl.org/docs/man1.0.2/man1/genpkey.html
         *  @param[in] keyPairAlgorithm - The type of key pair for use with signing algorithms.
Valid built-in algorithm names for private key generation are RSA and EC.
         *  @param[in] keyUsage - Key usage extensions define the purpose of the public key contained in a certificate.
Valid Key usage extensions and its usage description.
ClientAuthentication: The public key is used for TLS WWW client
                      authentication.
CodeSigning: The public key is used for the signing of executable code. CRLSigning: The public key is used for verifying signatures on
            certificate revocation lists (CLRs).
DataEncipherment: The public key is used for directly enciphering
                  raw user data without the use of an intermediate
                  symmetric cipher.
DecipherOnly: The public key could be used for deciphering data
              while performing key agreement.
DigitalSignature: The public key is used for verifying digital
                  signatures, other than signatures on certificates
                  and CRLs.
EmailProtection: The public key is used for email protection. EncipherOnly: The public key could be used for enciphering data
              while performing key agreement.
KeyCertSign: The public key is used for verifying signatures on
             public key certificates.
KeyEncipherment: The public key is used for enciphering private or
                 secret keys.
NonRepudiation: The public key is used to verify digital signatures,
                other than signatures on certificates and CRLs,
                and used to provide a non- repudiation service that
                protects against the signing entity falsely denying
                some action.
OCSPSigning: The public key is used for signing OCSP responses. ServerAuthentication: The public key is used for TLS WWW server
                      authentication.
Timestamping: The public key is used for binding the hash of an
              object to a time.
         *  @param[in] organization - The legal name of the organization. This should not be abbreviated and should include suffixes such as Inc, Corp, or LLC. For example, IBM Corp. This is a required parameter.
         *  @param[in] organizationalUnit - The name of the unit or division of the organization making the request. This is a required parameter.
         *  @param[in] state - The state or province where the organization is located. This should not be abbreviated. For example, Texas. This is a required parameter.
         *  @param[in] surname - The surname of the user making the request.
         *  @param[in] unstructuredName - The unstructured name of the subject.
         *
         *  @return path[std::string] - The object path of the D-Bus object to be watch for retrieving the CSR string.
         */
        virtual std::string generateCSR(
            std::vector<std::string> alternativeNames,
            std::string challengePassword,
            std::string city,
            std::string commonName,
            std::string contactPerson,
            std::string country,
            std::string email,
            std::string givenName,
            std::string initials,
            int64_t keyBitLength,
            std::string keyCurveId,
            std::string keyPairAlgorithm,
            std::vector<std::string> keyUsage,
            std::string organization,
            std::string organizationalUnit,
            std::string state,
            std::string surname,
            std::string unstructuredName) = 0;




    private:

        /** @brief sd-bus callback for GenerateCSR
         */
        static int _callback_GenerateCSR(
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Certs.CSR.Create";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Certs_CSR_Create_interface;
        sdbusplus::SdBusInterface *_intf;


};


} // namespace server
} // namespace CSR
} // namespace Certs
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

