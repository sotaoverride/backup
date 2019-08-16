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
namespace Inventory
{
namespace Item
{
namespace server
{

class PCIeDevice
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
        PCIeDevice() = delete;
        PCIeDevice(const PCIeDevice&) = delete;
        PCIeDevice& operator=(const PCIeDevice&) = delete;
        PCIeDevice(PCIeDevice&&) = delete;
        PCIeDevice& operator=(PCIeDevice&&) = delete;
        virtual ~PCIeDevice() = default;

        /** @brief Constructor to put object onto bus at a dbus path.
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         */
        PCIeDevice(bus::bus& bus, const char* path);


        using PropertiesVariant = std::variant<
                std::string>;

        /** @brief Constructor to initialize the object from a map of
         *         properties.
         *
         *  @param[in] bus - Bus to attach to.
         *  @param[in] path - Path to attach at.
         *  @param[in] vals - Map of property name to value for initialization.
         */
        PCIeDevice(bus::bus& bus, const char* path,
                     const std::map<std::string, PropertiesVariant>& vals,
                     bool skipSignal = false);



        /** Get value of DeviceType */
        virtual std::string deviceType() const;
        /** Set value of DeviceType with option to skip sending signal */
        virtual std::string deviceType(std::string value,
               bool skipSignal);
        /** Set value of DeviceType */
        virtual std::string deviceType(std::string value);
        /** Get value of Function0ClassCode */
        virtual std::string function0ClassCode() const;
        /** Set value of Function0ClassCode with option to skip sending signal */
        virtual std::string function0ClassCode(std::string value,
               bool skipSignal);
        /** Set value of Function0ClassCode */
        virtual std::string function0ClassCode(std::string value);
        /** Get value of Function0DeviceClass */
        virtual std::string function0DeviceClass() const;
        /** Set value of Function0DeviceClass with option to skip sending signal */
        virtual std::string function0DeviceClass(std::string value,
               bool skipSignal);
        /** Set value of Function0DeviceClass */
        virtual std::string function0DeviceClass(std::string value);
        /** Get value of Function0DeviceId */
        virtual std::string function0DeviceId() const;
        /** Set value of Function0DeviceId with option to skip sending signal */
        virtual std::string function0DeviceId(std::string value,
               bool skipSignal);
        /** Set value of Function0DeviceId */
        virtual std::string function0DeviceId(std::string value);
        /** Get value of Function0FunctionType */
        virtual std::string function0FunctionType() const;
        /** Set value of Function0FunctionType with option to skip sending signal */
        virtual std::string function0FunctionType(std::string value,
               bool skipSignal);
        /** Set value of Function0FunctionType */
        virtual std::string function0FunctionType(std::string value);
        /** Get value of Function0RevisionId */
        virtual std::string function0RevisionId() const;
        /** Set value of Function0RevisionId with option to skip sending signal */
        virtual std::string function0RevisionId(std::string value,
               bool skipSignal);
        /** Set value of Function0RevisionId */
        virtual std::string function0RevisionId(std::string value);
        /** Get value of Function0SubsystemId */
        virtual std::string function0SubsystemId() const;
        /** Set value of Function0SubsystemId with option to skip sending signal */
        virtual std::string function0SubsystemId(std::string value,
               bool skipSignal);
        /** Set value of Function0SubsystemId */
        virtual std::string function0SubsystemId(std::string value);
        /** Get value of Function0SubsystemVendorId */
        virtual std::string function0SubsystemVendorId() const;
        /** Set value of Function0SubsystemVendorId with option to skip sending signal */
        virtual std::string function0SubsystemVendorId(std::string value,
               bool skipSignal);
        /** Set value of Function0SubsystemVendorId */
        virtual std::string function0SubsystemVendorId(std::string value);
        /** Get value of Function0VendorId */
        virtual std::string function0VendorId() const;
        /** Set value of Function0VendorId with option to skip sending signal */
        virtual std::string function0VendorId(std::string value,
               bool skipSignal);
        /** Set value of Function0VendorId */
        virtual std::string function0VendorId(std::string value);
        /** Get value of Function1ClassCode */
        virtual std::string function1ClassCode() const;
        /** Set value of Function1ClassCode with option to skip sending signal */
        virtual std::string function1ClassCode(std::string value,
               bool skipSignal);
        /** Set value of Function1ClassCode */
        virtual std::string function1ClassCode(std::string value);
        /** Get value of Function1DeviceClass */
        virtual std::string function1DeviceClass() const;
        /** Set value of Function1DeviceClass with option to skip sending signal */
        virtual std::string function1DeviceClass(std::string value,
               bool skipSignal);
        /** Set value of Function1DeviceClass */
        virtual std::string function1DeviceClass(std::string value);
        /** Get value of Function1DeviceId */
        virtual std::string function1DeviceId() const;
        /** Set value of Function1DeviceId with option to skip sending signal */
        virtual std::string function1DeviceId(std::string value,
               bool skipSignal);
        /** Set value of Function1DeviceId */
        virtual std::string function1DeviceId(std::string value);
        /** Get value of Function1FunctionType */
        virtual std::string function1FunctionType() const;
        /** Set value of Function1FunctionType with option to skip sending signal */
        virtual std::string function1FunctionType(std::string value,
               bool skipSignal);
        /** Set value of Function1FunctionType */
        virtual std::string function1FunctionType(std::string value);
        /** Get value of Function1RevisionId */
        virtual std::string function1RevisionId() const;
        /** Set value of Function1RevisionId with option to skip sending signal */
        virtual std::string function1RevisionId(std::string value,
               bool skipSignal);
        /** Set value of Function1RevisionId */
        virtual std::string function1RevisionId(std::string value);
        /** Get value of Function1SubsystemId */
        virtual std::string function1SubsystemId() const;
        /** Set value of Function1SubsystemId with option to skip sending signal */
        virtual std::string function1SubsystemId(std::string value,
               bool skipSignal);
        /** Set value of Function1SubsystemId */
        virtual std::string function1SubsystemId(std::string value);
        /** Get value of Function1SubsystemVendorId */
        virtual std::string function1SubsystemVendorId() const;
        /** Set value of Function1SubsystemVendorId with option to skip sending signal */
        virtual std::string function1SubsystemVendorId(std::string value,
               bool skipSignal);
        /** Set value of Function1SubsystemVendorId */
        virtual std::string function1SubsystemVendorId(std::string value);
        /** Get value of Function1VendorId */
        virtual std::string function1VendorId() const;
        /** Set value of Function1VendorId with option to skip sending signal */
        virtual std::string function1VendorId(std::string value,
               bool skipSignal);
        /** Set value of Function1VendorId */
        virtual std::string function1VendorId(std::string value);
        /** Get value of Function2ClassCode */
        virtual std::string function2ClassCode() const;
        /** Set value of Function2ClassCode with option to skip sending signal */
        virtual std::string function2ClassCode(std::string value,
               bool skipSignal);
        /** Set value of Function2ClassCode */
        virtual std::string function2ClassCode(std::string value);
        /** Get value of Function2DeviceClass */
        virtual std::string function2DeviceClass() const;
        /** Set value of Function2DeviceClass with option to skip sending signal */
        virtual std::string function2DeviceClass(std::string value,
               bool skipSignal);
        /** Set value of Function2DeviceClass */
        virtual std::string function2DeviceClass(std::string value);
        /** Get value of Function2DeviceId */
        virtual std::string function2DeviceId() const;
        /** Set value of Function2DeviceId with option to skip sending signal */
        virtual std::string function2DeviceId(std::string value,
               bool skipSignal);
        /** Set value of Function2DeviceId */
        virtual std::string function2DeviceId(std::string value);
        /** Get value of Function2FunctionType */
        virtual std::string function2FunctionType() const;
        /** Set value of Function2FunctionType with option to skip sending signal */
        virtual std::string function2FunctionType(std::string value,
               bool skipSignal);
        /** Set value of Function2FunctionType */
        virtual std::string function2FunctionType(std::string value);
        /** Get value of Function2RevisionId */
        virtual std::string function2RevisionId() const;
        /** Set value of Function2RevisionId with option to skip sending signal */
        virtual std::string function2RevisionId(std::string value,
               bool skipSignal);
        /** Set value of Function2RevisionId */
        virtual std::string function2RevisionId(std::string value);
        /** Get value of Function2SubsystemId */
        virtual std::string function2SubsystemId() const;
        /** Set value of Function2SubsystemId with option to skip sending signal */
        virtual std::string function2SubsystemId(std::string value,
               bool skipSignal);
        /** Set value of Function2SubsystemId */
        virtual std::string function2SubsystemId(std::string value);
        /** Get value of Function2SubsystemVendorId */
        virtual std::string function2SubsystemVendorId() const;
        /** Set value of Function2SubsystemVendorId with option to skip sending signal */
        virtual std::string function2SubsystemVendorId(std::string value,
               bool skipSignal);
        /** Set value of Function2SubsystemVendorId */
        virtual std::string function2SubsystemVendorId(std::string value);
        /** Get value of Function2VendorId */
        virtual std::string function2VendorId() const;
        /** Set value of Function2VendorId with option to skip sending signal */
        virtual std::string function2VendorId(std::string value,
               bool skipSignal);
        /** Set value of Function2VendorId */
        virtual std::string function2VendorId(std::string value);
        /** Get value of Function3ClassCode */
        virtual std::string function3ClassCode() const;
        /** Set value of Function3ClassCode with option to skip sending signal */
        virtual std::string function3ClassCode(std::string value,
               bool skipSignal);
        /** Set value of Function3ClassCode */
        virtual std::string function3ClassCode(std::string value);
        /** Get value of Function3DeviceClass */
        virtual std::string function3DeviceClass() const;
        /** Set value of Function3DeviceClass with option to skip sending signal */
        virtual std::string function3DeviceClass(std::string value,
               bool skipSignal);
        /** Set value of Function3DeviceClass */
        virtual std::string function3DeviceClass(std::string value);
        /** Get value of Function3DeviceId */
        virtual std::string function3DeviceId() const;
        /** Set value of Function3DeviceId with option to skip sending signal */
        virtual std::string function3DeviceId(std::string value,
               bool skipSignal);
        /** Set value of Function3DeviceId */
        virtual std::string function3DeviceId(std::string value);
        /** Get value of Function3FunctionType */
        virtual std::string function3FunctionType() const;
        /** Set value of Function3FunctionType with option to skip sending signal */
        virtual std::string function3FunctionType(std::string value,
               bool skipSignal);
        /** Set value of Function3FunctionType */
        virtual std::string function3FunctionType(std::string value);
        /** Get value of Function3RevisionId */
        virtual std::string function3RevisionId() const;
        /** Set value of Function3RevisionId with option to skip sending signal */
        virtual std::string function3RevisionId(std::string value,
               bool skipSignal);
        /** Set value of Function3RevisionId */
        virtual std::string function3RevisionId(std::string value);
        /** Get value of Function3SubsystemId */
        virtual std::string function3SubsystemId() const;
        /** Set value of Function3SubsystemId with option to skip sending signal */
        virtual std::string function3SubsystemId(std::string value,
               bool skipSignal);
        /** Set value of Function3SubsystemId */
        virtual std::string function3SubsystemId(std::string value);
        /** Get value of Function3SubsystemVendorId */
        virtual std::string function3SubsystemVendorId() const;
        /** Set value of Function3SubsystemVendorId with option to skip sending signal */
        virtual std::string function3SubsystemVendorId(std::string value,
               bool skipSignal);
        /** Set value of Function3SubsystemVendorId */
        virtual std::string function3SubsystemVendorId(std::string value);
        /** Get value of Function3VendorId */
        virtual std::string function3VendorId() const;
        /** Set value of Function3VendorId with option to skip sending signal */
        virtual std::string function3VendorId(std::string value,
               bool skipSignal);
        /** Set value of Function3VendorId */
        virtual std::string function3VendorId(std::string value);
        /** Get value of Function4ClassCode */
        virtual std::string function4ClassCode() const;
        /** Set value of Function4ClassCode with option to skip sending signal */
        virtual std::string function4ClassCode(std::string value,
               bool skipSignal);
        /** Set value of Function4ClassCode */
        virtual std::string function4ClassCode(std::string value);
        /** Get value of Function4DeviceClass */
        virtual std::string function4DeviceClass() const;
        /** Set value of Function4DeviceClass with option to skip sending signal */
        virtual std::string function4DeviceClass(std::string value,
               bool skipSignal);
        /** Set value of Function4DeviceClass */
        virtual std::string function4DeviceClass(std::string value);
        /** Get value of Function4DeviceId */
        virtual std::string function4DeviceId() const;
        /** Set value of Function4DeviceId with option to skip sending signal */
        virtual std::string function4DeviceId(std::string value,
               bool skipSignal);
        /** Set value of Function4DeviceId */
        virtual std::string function4DeviceId(std::string value);
        /** Get value of Function4FunctionType */
        virtual std::string function4FunctionType() const;
        /** Set value of Function4FunctionType with option to skip sending signal */
        virtual std::string function4FunctionType(std::string value,
               bool skipSignal);
        /** Set value of Function4FunctionType */
        virtual std::string function4FunctionType(std::string value);
        /** Get value of Function4RevisionId */
        virtual std::string function4RevisionId() const;
        /** Set value of Function4RevisionId with option to skip sending signal */
        virtual std::string function4RevisionId(std::string value,
               bool skipSignal);
        /** Set value of Function4RevisionId */
        virtual std::string function4RevisionId(std::string value);
        /** Get value of Function4SubsystemId */
        virtual std::string function4SubsystemId() const;
        /** Set value of Function4SubsystemId with option to skip sending signal */
        virtual std::string function4SubsystemId(std::string value,
               bool skipSignal);
        /** Set value of Function4SubsystemId */
        virtual std::string function4SubsystemId(std::string value);
        /** Get value of Function4SubsystemVendorId */
        virtual std::string function4SubsystemVendorId() const;
        /** Set value of Function4SubsystemVendorId with option to skip sending signal */
        virtual std::string function4SubsystemVendorId(std::string value,
               bool skipSignal);
        /** Set value of Function4SubsystemVendorId */
        virtual std::string function4SubsystemVendorId(std::string value);
        /** Get value of Function4VendorId */
        virtual std::string function4VendorId() const;
        /** Set value of Function4VendorId with option to skip sending signal */
        virtual std::string function4VendorId(std::string value,
               bool skipSignal);
        /** Set value of Function4VendorId */
        virtual std::string function4VendorId(std::string value);
        /** Get value of Function5ClassCode */
        virtual std::string function5ClassCode() const;
        /** Set value of Function5ClassCode with option to skip sending signal */
        virtual std::string function5ClassCode(std::string value,
               bool skipSignal);
        /** Set value of Function5ClassCode */
        virtual std::string function5ClassCode(std::string value);
        /** Get value of Function5DeviceClass */
        virtual std::string function5DeviceClass() const;
        /** Set value of Function5DeviceClass with option to skip sending signal */
        virtual std::string function5DeviceClass(std::string value,
               bool skipSignal);
        /** Set value of Function5DeviceClass */
        virtual std::string function5DeviceClass(std::string value);
        /** Get value of Function5DeviceId */
        virtual std::string function5DeviceId() const;
        /** Set value of Function5DeviceId with option to skip sending signal */
        virtual std::string function5DeviceId(std::string value,
               bool skipSignal);
        /** Set value of Function5DeviceId */
        virtual std::string function5DeviceId(std::string value);
        /** Get value of Function5FunctionType */
        virtual std::string function5FunctionType() const;
        /** Set value of Function5FunctionType with option to skip sending signal */
        virtual std::string function5FunctionType(std::string value,
               bool skipSignal);
        /** Set value of Function5FunctionType */
        virtual std::string function5FunctionType(std::string value);
        /** Get value of Function5RevisionId */
        virtual std::string function5RevisionId() const;
        /** Set value of Function5RevisionId with option to skip sending signal */
        virtual std::string function5RevisionId(std::string value,
               bool skipSignal);
        /** Set value of Function5RevisionId */
        virtual std::string function5RevisionId(std::string value);
        /** Get value of Function5SubsystemId */
        virtual std::string function5SubsystemId() const;
        /** Set value of Function5SubsystemId with option to skip sending signal */
        virtual std::string function5SubsystemId(std::string value,
               bool skipSignal);
        /** Set value of Function5SubsystemId */
        virtual std::string function5SubsystemId(std::string value);
        /** Get value of Function5SubsystemVendorId */
        virtual std::string function5SubsystemVendorId() const;
        /** Set value of Function5SubsystemVendorId with option to skip sending signal */
        virtual std::string function5SubsystemVendorId(std::string value,
               bool skipSignal);
        /** Set value of Function5SubsystemVendorId */
        virtual std::string function5SubsystemVendorId(std::string value);
        /** Get value of Function5VendorId */
        virtual std::string function5VendorId() const;
        /** Set value of Function5VendorId with option to skip sending signal */
        virtual std::string function5VendorId(std::string value,
               bool skipSignal);
        /** Set value of Function5VendorId */
        virtual std::string function5VendorId(std::string value);
        /** Get value of Function6ClassCode */
        virtual std::string function6ClassCode() const;
        /** Set value of Function6ClassCode with option to skip sending signal */
        virtual std::string function6ClassCode(std::string value,
               bool skipSignal);
        /** Set value of Function6ClassCode */
        virtual std::string function6ClassCode(std::string value);
        /** Get value of Function6DeviceClass */
        virtual std::string function6DeviceClass() const;
        /** Set value of Function6DeviceClass with option to skip sending signal */
        virtual std::string function6DeviceClass(std::string value,
               bool skipSignal);
        /** Set value of Function6DeviceClass */
        virtual std::string function6DeviceClass(std::string value);
        /** Get value of Function6DeviceId */
        virtual std::string function6DeviceId() const;
        /** Set value of Function6DeviceId with option to skip sending signal */
        virtual std::string function6DeviceId(std::string value,
               bool skipSignal);
        /** Set value of Function6DeviceId */
        virtual std::string function6DeviceId(std::string value);
        /** Get value of Function6FunctionType */
        virtual std::string function6FunctionType() const;
        /** Set value of Function6FunctionType with option to skip sending signal */
        virtual std::string function6FunctionType(std::string value,
               bool skipSignal);
        /** Set value of Function6FunctionType */
        virtual std::string function6FunctionType(std::string value);
        /** Get value of Function6RevisionId */
        virtual std::string function6RevisionId() const;
        /** Set value of Function6RevisionId with option to skip sending signal */
        virtual std::string function6RevisionId(std::string value,
               bool skipSignal);
        /** Set value of Function6RevisionId */
        virtual std::string function6RevisionId(std::string value);
        /** Get value of Function6SubsystemId */
        virtual std::string function6SubsystemId() const;
        /** Set value of Function6SubsystemId with option to skip sending signal */
        virtual std::string function6SubsystemId(std::string value,
               bool skipSignal);
        /** Set value of Function6SubsystemId */
        virtual std::string function6SubsystemId(std::string value);
        /** Get value of Function6SubsystemVendorId */
        virtual std::string function6SubsystemVendorId() const;
        /** Set value of Function6SubsystemVendorId with option to skip sending signal */
        virtual std::string function6SubsystemVendorId(std::string value,
               bool skipSignal);
        /** Set value of Function6SubsystemVendorId */
        virtual std::string function6SubsystemVendorId(std::string value);
        /** Get value of Function6VendorId */
        virtual std::string function6VendorId() const;
        /** Set value of Function6VendorId with option to skip sending signal */
        virtual std::string function6VendorId(std::string value,
               bool skipSignal);
        /** Set value of Function6VendorId */
        virtual std::string function6VendorId(std::string value);
        /** Get value of Function7ClassCode */
        virtual std::string function7ClassCode() const;
        /** Set value of Function7ClassCode with option to skip sending signal */
        virtual std::string function7ClassCode(std::string value,
               bool skipSignal);
        /** Set value of Function7ClassCode */
        virtual std::string function7ClassCode(std::string value);
        /** Get value of Function7DeviceClass */
        virtual std::string function7DeviceClass() const;
        /** Set value of Function7DeviceClass with option to skip sending signal */
        virtual std::string function7DeviceClass(std::string value,
               bool skipSignal);
        /** Set value of Function7DeviceClass */
        virtual std::string function7DeviceClass(std::string value);
        /** Get value of Function7DeviceId */
        virtual std::string function7DeviceId() const;
        /** Set value of Function7DeviceId with option to skip sending signal */
        virtual std::string function7DeviceId(std::string value,
               bool skipSignal);
        /** Set value of Function7DeviceId */
        virtual std::string function7DeviceId(std::string value);
        /** Get value of Function7FunctionType */
        virtual std::string function7FunctionType() const;
        /** Set value of Function7FunctionType with option to skip sending signal */
        virtual std::string function7FunctionType(std::string value,
               bool skipSignal);
        /** Set value of Function7FunctionType */
        virtual std::string function7FunctionType(std::string value);
        /** Get value of Function7RevisionId */
        virtual std::string function7RevisionId() const;
        /** Set value of Function7RevisionId with option to skip sending signal */
        virtual std::string function7RevisionId(std::string value,
               bool skipSignal);
        /** Set value of Function7RevisionId */
        virtual std::string function7RevisionId(std::string value);
        /** Get value of Function7SubsystemId */
        virtual std::string function7SubsystemId() const;
        /** Set value of Function7SubsystemId with option to skip sending signal */
        virtual std::string function7SubsystemId(std::string value,
               bool skipSignal);
        /** Set value of Function7SubsystemId */
        virtual std::string function7SubsystemId(std::string value);
        /** Get value of Function7SubsystemVendorId */
        virtual std::string function7SubsystemVendorId() const;
        /** Set value of Function7SubsystemVendorId with option to skip sending signal */
        virtual std::string function7SubsystemVendorId(std::string value,
               bool skipSignal);
        /** Set value of Function7SubsystemVendorId */
        virtual std::string function7SubsystemVendorId(std::string value);
        /** Get value of Function7VendorId */
        virtual std::string function7VendorId() const;
        /** Set value of Function7VendorId with option to skip sending signal */
        virtual std::string function7VendorId(std::string value,
               bool skipSignal);
        /** Set value of Function7VendorId */
        virtual std::string function7VendorId(std::string value);
        /** Get value of Manufacturer */
        virtual std::string manufacturer() const;
        /** Set value of Manufacturer with option to skip sending signal */
        virtual std::string manufacturer(std::string value,
               bool skipSignal);
        /** Set value of Manufacturer */
        virtual std::string manufacturer(std::string value);

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

        /** @brief sd-bus callback for get-property 'DeviceType' */
        static int _callback_get_DeviceType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'DeviceType' */
        static int _callback_set_DeviceType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function0ClassCode' */
        static int _callback_get_Function0ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function0ClassCode' */
        static int _callback_set_Function0ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function0DeviceClass' */
        static int _callback_get_Function0DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function0DeviceClass' */
        static int _callback_set_Function0DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function0DeviceId' */
        static int _callback_get_Function0DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function0DeviceId' */
        static int _callback_set_Function0DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function0FunctionType' */
        static int _callback_get_Function0FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function0FunctionType' */
        static int _callback_set_Function0FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function0RevisionId' */
        static int _callback_get_Function0RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function0RevisionId' */
        static int _callback_set_Function0RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function0SubsystemId' */
        static int _callback_get_Function0SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function0SubsystemId' */
        static int _callback_set_Function0SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function0SubsystemVendorId' */
        static int _callback_get_Function0SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function0SubsystemVendorId' */
        static int _callback_set_Function0SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function0VendorId' */
        static int _callback_get_Function0VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function0VendorId' */
        static int _callback_set_Function0VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function1ClassCode' */
        static int _callback_get_Function1ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function1ClassCode' */
        static int _callback_set_Function1ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function1DeviceClass' */
        static int _callback_get_Function1DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function1DeviceClass' */
        static int _callback_set_Function1DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function1DeviceId' */
        static int _callback_get_Function1DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function1DeviceId' */
        static int _callback_set_Function1DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function1FunctionType' */
        static int _callback_get_Function1FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function1FunctionType' */
        static int _callback_set_Function1FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function1RevisionId' */
        static int _callback_get_Function1RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function1RevisionId' */
        static int _callback_set_Function1RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function1SubsystemId' */
        static int _callback_get_Function1SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function1SubsystemId' */
        static int _callback_set_Function1SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function1SubsystemVendorId' */
        static int _callback_get_Function1SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function1SubsystemVendorId' */
        static int _callback_set_Function1SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function1VendorId' */
        static int _callback_get_Function1VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function1VendorId' */
        static int _callback_set_Function1VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function2ClassCode' */
        static int _callback_get_Function2ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function2ClassCode' */
        static int _callback_set_Function2ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function2DeviceClass' */
        static int _callback_get_Function2DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function2DeviceClass' */
        static int _callback_set_Function2DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function2DeviceId' */
        static int _callback_get_Function2DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function2DeviceId' */
        static int _callback_set_Function2DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function2FunctionType' */
        static int _callback_get_Function2FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function2FunctionType' */
        static int _callback_set_Function2FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function2RevisionId' */
        static int _callback_get_Function2RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function2RevisionId' */
        static int _callback_set_Function2RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function2SubsystemId' */
        static int _callback_get_Function2SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function2SubsystemId' */
        static int _callback_set_Function2SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function2SubsystemVendorId' */
        static int _callback_get_Function2SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function2SubsystemVendorId' */
        static int _callback_set_Function2SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function2VendorId' */
        static int _callback_get_Function2VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function2VendorId' */
        static int _callback_set_Function2VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function3ClassCode' */
        static int _callback_get_Function3ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function3ClassCode' */
        static int _callback_set_Function3ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function3DeviceClass' */
        static int _callback_get_Function3DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function3DeviceClass' */
        static int _callback_set_Function3DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function3DeviceId' */
        static int _callback_get_Function3DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function3DeviceId' */
        static int _callback_set_Function3DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function3FunctionType' */
        static int _callback_get_Function3FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function3FunctionType' */
        static int _callback_set_Function3FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function3RevisionId' */
        static int _callback_get_Function3RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function3RevisionId' */
        static int _callback_set_Function3RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function3SubsystemId' */
        static int _callback_get_Function3SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function3SubsystemId' */
        static int _callback_set_Function3SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function3SubsystemVendorId' */
        static int _callback_get_Function3SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function3SubsystemVendorId' */
        static int _callback_set_Function3SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function3VendorId' */
        static int _callback_get_Function3VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function3VendorId' */
        static int _callback_set_Function3VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function4ClassCode' */
        static int _callback_get_Function4ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function4ClassCode' */
        static int _callback_set_Function4ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function4DeviceClass' */
        static int _callback_get_Function4DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function4DeviceClass' */
        static int _callback_set_Function4DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function4DeviceId' */
        static int _callback_get_Function4DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function4DeviceId' */
        static int _callback_set_Function4DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function4FunctionType' */
        static int _callback_get_Function4FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function4FunctionType' */
        static int _callback_set_Function4FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function4RevisionId' */
        static int _callback_get_Function4RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function4RevisionId' */
        static int _callback_set_Function4RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function4SubsystemId' */
        static int _callback_get_Function4SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function4SubsystemId' */
        static int _callback_set_Function4SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function4SubsystemVendorId' */
        static int _callback_get_Function4SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function4SubsystemVendorId' */
        static int _callback_set_Function4SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function4VendorId' */
        static int _callback_get_Function4VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function4VendorId' */
        static int _callback_set_Function4VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function5ClassCode' */
        static int _callback_get_Function5ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function5ClassCode' */
        static int _callback_set_Function5ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function5DeviceClass' */
        static int _callback_get_Function5DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function5DeviceClass' */
        static int _callback_set_Function5DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function5DeviceId' */
        static int _callback_get_Function5DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function5DeviceId' */
        static int _callback_set_Function5DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function5FunctionType' */
        static int _callback_get_Function5FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function5FunctionType' */
        static int _callback_set_Function5FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function5RevisionId' */
        static int _callback_get_Function5RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function5RevisionId' */
        static int _callback_set_Function5RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function5SubsystemId' */
        static int _callback_get_Function5SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function5SubsystemId' */
        static int _callback_set_Function5SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function5SubsystemVendorId' */
        static int _callback_get_Function5SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function5SubsystemVendorId' */
        static int _callback_set_Function5SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function5VendorId' */
        static int _callback_get_Function5VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function5VendorId' */
        static int _callback_set_Function5VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function6ClassCode' */
        static int _callback_get_Function6ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function6ClassCode' */
        static int _callback_set_Function6ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function6DeviceClass' */
        static int _callback_get_Function6DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function6DeviceClass' */
        static int _callback_set_Function6DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function6DeviceId' */
        static int _callback_get_Function6DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function6DeviceId' */
        static int _callback_set_Function6DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function6FunctionType' */
        static int _callback_get_Function6FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function6FunctionType' */
        static int _callback_set_Function6FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function6RevisionId' */
        static int _callback_get_Function6RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function6RevisionId' */
        static int _callback_set_Function6RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function6SubsystemId' */
        static int _callback_get_Function6SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function6SubsystemId' */
        static int _callback_set_Function6SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function6SubsystemVendorId' */
        static int _callback_get_Function6SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function6SubsystemVendorId' */
        static int _callback_set_Function6SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function6VendorId' */
        static int _callback_get_Function6VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function6VendorId' */
        static int _callback_set_Function6VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function7ClassCode' */
        static int _callback_get_Function7ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function7ClassCode' */
        static int _callback_set_Function7ClassCode(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function7DeviceClass' */
        static int _callback_get_Function7DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function7DeviceClass' */
        static int _callback_set_Function7DeviceClass(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function7DeviceId' */
        static int _callback_get_Function7DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function7DeviceId' */
        static int _callback_set_Function7DeviceId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function7FunctionType' */
        static int _callback_get_Function7FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function7FunctionType' */
        static int _callback_set_Function7FunctionType(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function7RevisionId' */
        static int _callback_get_Function7RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function7RevisionId' */
        static int _callback_set_Function7RevisionId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function7SubsystemId' */
        static int _callback_get_Function7SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function7SubsystemId' */
        static int _callback_set_Function7SubsystemId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function7SubsystemVendorId' */
        static int _callback_get_Function7SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function7SubsystemVendorId' */
        static int _callback_set_Function7SubsystemVendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Function7VendorId' */
        static int _callback_get_Function7VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Function7VendorId' */
        static int _callback_set_Function7VendorId(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);

        /** @brief sd-bus callback for get-property 'Manufacturer' */
        static int _callback_get_Manufacturer(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);
        /** @brief sd-bus callback for set-property 'Manufacturer' */
        static int _callback_set_Manufacturer(
            sd_bus*, const char*, const char*, const char*,
            sd_bus_message*, void*, sd_bus_error*);


        static constexpr auto _interface = "xyz.openbmc_project.Inventory.Item.PCIeDevice";
        static const vtable::vtable_t _vtable[];
        sdbusplus::server::interface::interface
                _xyz_openbmc_project_Inventory_Item_PCIeDevice_interface;
        sdbusplus::SdBusInterface *_intf;

        std::string _deviceType{};
        std::string _function0ClassCode{};
        std::string _function0DeviceClass{};
        std::string _function0DeviceId{};
        std::string _function0FunctionType{};
        std::string _function0RevisionId{};
        std::string _function0SubsystemId{};
        std::string _function0SubsystemVendorId{};
        std::string _function0VendorId{};
        std::string _function1ClassCode{};
        std::string _function1DeviceClass{};
        std::string _function1DeviceId{};
        std::string _function1FunctionType{};
        std::string _function1RevisionId{};
        std::string _function1SubsystemId{};
        std::string _function1SubsystemVendorId{};
        std::string _function1VendorId{};
        std::string _function2ClassCode{};
        std::string _function2DeviceClass{};
        std::string _function2DeviceId{};
        std::string _function2FunctionType{};
        std::string _function2RevisionId{};
        std::string _function2SubsystemId{};
        std::string _function2SubsystemVendorId{};
        std::string _function2VendorId{};
        std::string _function3ClassCode{};
        std::string _function3DeviceClass{};
        std::string _function3DeviceId{};
        std::string _function3FunctionType{};
        std::string _function3RevisionId{};
        std::string _function3SubsystemId{};
        std::string _function3SubsystemVendorId{};
        std::string _function3VendorId{};
        std::string _function4ClassCode{};
        std::string _function4DeviceClass{};
        std::string _function4DeviceId{};
        std::string _function4FunctionType{};
        std::string _function4RevisionId{};
        std::string _function4SubsystemId{};
        std::string _function4SubsystemVendorId{};
        std::string _function4VendorId{};
        std::string _function5ClassCode{};
        std::string _function5DeviceClass{};
        std::string _function5DeviceId{};
        std::string _function5FunctionType{};
        std::string _function5RevisionId{};
        std::string _function5SubsystemId{};
        std::string _function5SubsystemVendorId{};
        std::string _function5VendorId{};
        std::string _function6ClassCode{};
        std::string _function6DeviceClass{};
        std::string _function6DeviceId{};
        std::string _function6FunctionType{};
        std::string _function6RevisionId{};
        std::string _function6SubsystemId{};
        std::string _function6SubsystemVendorId{};
        std::string _function6VendorId{};
        std::string _function7ClassCode{};
        std::string _function7DeviceClass{};
        std::string _function7DeviceId{};
        std::string _function7FunctionType{};
        std::string _function7RevisionId{};
        std::string _function7SubsystemId{};
        std::string _function7SubsystemVendorId{};
        std::string _function7VendorId{};
        std::string _manufacturer{};

};


} // namespace server
} // namespace Item
} // namespace Inventory
} // namespace openbmc_project
} // namespace xyz
} // namespace sdbusplus

