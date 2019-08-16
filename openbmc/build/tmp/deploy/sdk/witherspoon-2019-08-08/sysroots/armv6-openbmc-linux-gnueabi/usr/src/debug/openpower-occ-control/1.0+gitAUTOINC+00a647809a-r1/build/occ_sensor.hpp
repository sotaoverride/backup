// WARNING: Generated header. Do not edit!

#pragma once

#include <map>
#include <string>
#include <tuple>

namespace open_power
{
namespace occ
{

using instanceID = int;
using sensorID = uint8_t;
using sensorName = std::string;
using sensorDefs = std::tuple<sensorID, sensorName>;
const std::map<instanceID, sensorDefs> Status::sensorMap = {
    {0, {8, "None"}},
    {1, {9, "None"}},
};

} // namespace occ
} // namespace open_power
