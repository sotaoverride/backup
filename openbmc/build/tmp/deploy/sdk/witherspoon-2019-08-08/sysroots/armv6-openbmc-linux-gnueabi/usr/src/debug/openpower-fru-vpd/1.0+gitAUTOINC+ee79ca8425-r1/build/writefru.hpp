// WARNING: Generated header. Do not edit!

#pragma once

#include "defines.hpp"
#include "extra-properties-gen.hpp"
#include "store.hpp"
#include "types.hpp"
#include "utils.hpp"

#include <iostream>
#include <map>

namespace openpower
{
namespace vpd
{
namespace inventory
{

/** @brief API to write parsed VPD to inventory,
 *      for a specific FRU
 *
 *  @param [in] vpdStore - Store object containing
 *      parsed VPD
 *  @param [in] path - FRU object path
 */
template <Fru F>
void writeFru(const Store& vpdStore, const std::string& path);

// Specialization of BMC
template <>
void writeFru<Fru::BMC>(const Store& vpdStore, const std::string& path)
{
    ObjectMap objects;
    InterfaceMap interfaces;
    auto iter = extra::objects.find(path);

    // Inventory manager needs object path, list of interface names to be
    // implemented, and property:value pairs contained in said interfaces

    PropertyMap xyzAssetProps;
    if (vpdStore.exists<Record::OPFR, record::Keyword::VN>())
    {
        xyzAssetProps["Manufacturer"] =
            vpdStore.get<Record::OPFR, record::Keyword::VN>();
    }
    if (vpdStore.exists<Record::OPFR, record::Keyword::VS>())
    {
        xyzAssetProps["SerialNumber"] =
            vpdStore.get<Record::OPFR, record::Keyword::VS>();
    }
    if (vpdStore.exists<Record::OPFR, record::Keyword::VP>())
    {
        xyzAssetProps["PartNumber"] =
            vpdStore.get<Record::OPFR, record::Keyword::VP>();
    }
    // Check and update extra properties
    if (extra::objects.end() != iter)
    {
        auto propIter =
            (iter->second)
                .find("xyz.openbmc_project.Inventory.Decorator.Asset");
        if ((iter->second).end() != propIter)
        {
            for (const auto& map : propIter->second)
            {
                xyzAssetProps[map.first] = map.second;
            }
        }
    }
    interfaces.emplace("xyz.openbmc_project.Inventory.Decorator.Asset",
                       std::move(xyzAssetProps));
    PropertyMap xyzItemProps;
    if (vpdStore.exists<Record::VINI, record::Keyword::DR>())
    {
        xyzItemProps["PrettyName"] =
            vpdStore.get<Record::VINI, record::Keyword::DR>();
    }
    // Check and update extra properties
    if (extra::objects.end() != iter)
    {
        auto propIter =
            (iter->second).find("xyz.openbmc_project.Inventory.Item");
        if ((iter->second).end() != propIter)
        {
            for (const auto& map : propIter->second)
            {
                xyzItemProps[map.first] = map.second;
            }
        }
    }
    interfaces.emplace("xyz.openbmc_project.Inventory.Item",
                       std::move(xyzItemProps));
    PropertyMap xyzBmcProps;
    // Check and update extra properties
    if (extra::objects.end() != iter)
    {
        auto propIter =
            (iter->second).find("xyz.openbmc_project.Inventory.Item.Bmc");
        if ((iter->second).end() != propIter)
        {
            for (const auto& map : propIter->second)
            {
                xyzBmcProps[map.first] = map.second;
            }
        }
    }
    interfaces.emplace("xyz.openbmc_project.Inventory.Item.Bmc",
                       std::move(xyzBmcProps));

    sdbusplus::message::object_path object(path);
    // Check and update extra properties
    if (extra::objects.end() != iter)
    {
        for (const auto& entry : iter->second)
        {
            if (interfaces.end() == interfaces.find(entry.first))
            {
                interfaces.emplace(entry.first, entry.second);
            }
        }
    }
    objects.emplace(std::move(object), std::move(interfaces));

    callPIM(std::move(objects));
}

// Specialization of ETHERNET
template <>
void writeFru<Fru::ETHERNET>(const Store& vpdStore, const std::string& path)
{
    ObjectMap objects;
    InterfaceMap interfaces;
    auto iter = extra::objects.find(path);

    // Inventory manager needs object path, list of interface names to be
    // implemented, and property:value pairs contained in said interfaces

    PropertyMap xyzEthernetProps;
    // Check and update extra properties
    if (extra::objects.end() != iter)
    {
        auto propIter =
            (iter->second).find("xyz.openbmc_project.Inventory.Item.Ethernet");
        if ((iter->second).end() != propIter)
        {
            for (const auto& map : propIter->second)
            {
                xyzEthernetProps[map.first] = map.second;
            }
        }
    }
    interfaces.emplace("xyz.openbmc_project.Inventory.Item.Ethernet",
                       std::move(xyzEthernetProps));
    PropertyMap xyzNetworkInterfaceProps;
    if (vpdStore.exists<Record::VINI, record::Keyword::B1>())
    {
        xyzNetworkInterfaceProps["MACAddress"] =
            vpdStore.get<Record::VINI, record::Keyword::B1>();
    }
    if (vpdStore.exists<Record::OPFR, record::Keyword::B1>())
    {
        xyzNetworkInterfaceProps["MACAddress"] =
            vpdStore.get<Record::OPFR, record::Keyword::B1>();
    }
    // Check and update extra properties
    if (extra::objects.end() != iter)
    {
        auto propIter =
            (iter->second)
                .find("xyz.openbmc_project.Inventory.Item.NetworkInterface");
        if ((iter->second).end() != propIter)
        {
            for (const auto& map : propIter->second)
            {
                xyzNetworkInterfaceProps[map.first] = map.second;
            }
        }
    }
    interfaces.emplace("xyz.openbmc_project.Inventory.Item.NetworkInterface",
                       std::move(xyzNetworkInterfaceProps));

    sdbusplus::message::object_path object(path);
    // Check and update extra properties
    if (extra::objects.end() != iter)
    {
        for (const auto& entry : iter->second)
        {
            if (interfaces.end() == interfaces.find(entry.first))
            {
                interfaces.emplace(entry.first, entry.second);
            }
        }
    }
    objects.emplace(std::move(object), std::move(interfaces));

    callPIM(std::move(objects));
}

} // namespace inventory
} // namespace vpd
} // namespace openpower
