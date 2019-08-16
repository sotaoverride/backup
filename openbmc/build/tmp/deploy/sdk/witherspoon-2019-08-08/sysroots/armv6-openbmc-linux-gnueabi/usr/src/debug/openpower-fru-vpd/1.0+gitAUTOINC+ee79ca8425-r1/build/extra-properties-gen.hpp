// WARNING: Generated header. Do not edit!

#pragma once

#include "types.hpp"

#include <map>
#include <string>

namespace openpower
{
namespace vpd
{
namespace inventory
{
namespace extra
{

const std::map<Path, InterfaceMap> objects = {
    {"/system/chassis/motherboard/boxelder/bmc",
     {
         {"xyz.openbmc_project.Inventory.Decorator.Replaceable",
          {
              {"FieldReplaceable", false},
          }},
         {"xyz.openbmc_project.Inventory.Item",
          {
              {"Present", true},
          }},
     }},
    {"/system/chassis/motherboard/boxelder/bmc/ethernet",
     {
         {"xyz.openbmc_project.Inventory.Decorator.Replaceable",
          {
              {"FieldReplaceable", false},
          }},
         {"xyz.openbmc_project.Inventory.Item",
          {
              {"Present", true},
          }},
     }},
};

} // namespace extra
} // namespace inventory
} // namespace vpd
} // namespace openpower
