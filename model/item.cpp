/******************************************************************************
 * item.h             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "model.h"
/*
item::item* return_item (int id)
{
    for(item in itemsi
*/


std::string item::get_wear_location(wear_location loc)
{
    std::string wear_loc_name[] = {"WRISTS", "ARMS", "HANDS", "LEGS", "FEET",
    "HEAD", "TORSO", "SHIELD", "WIELDED", "NO_LOC"};
    return wear_loc_name[wear_loc];
}
/*
std::string item::item_type::get_item_type(wear_loc)
{
    //std::string item_type_name[] = {"WEAPON", "ARMOR", "INVALID"}
    //only weapons are wielded and a weapon must be able ot be wielded
    if(item::wear_location::get_wear_location(wear_loc) == "WIELDED")
    {
        return "WEAPON";
    }
    //any type that isn't weapon or armor
    if(item::wear_location::get_wear_location(wear_loc) == "NO_LOC")
    {
        return "INVALID";
    }
    //hence everything else must be armor
    else
    {
        return "ARMOR";
    }
  */  
