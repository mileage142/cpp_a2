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

item::wear_location item::get_wear_location(std::string loc)
{
    std::array<std::string, 10>wear_loc_name{"WRISTS", "ARMS", "HANDS", "LEGS", "FEET",
    "HEAD", "TORSO", "SHIELD", "WIELDED", "NO_LOC"};
    for(unsigned int i; i < wear_loc_name.size(); ++i)
    {
        if(wear_loc_name[i] == loc)
        {
            //return wear_loc_name[i];
            wear_location location = static_cast<wear_location>(i);
            return location;
        }
    }
    //return wear_loc_name[9];
    //
    //return static_cast<item::wear_location>(-1);
}

/*
//Version of get_wear location returns int cast to wear_location
item::wear_location get_wear_location(std::string loc)
{
    std::array<std::string, 10>wear_loc_name{"WRISTS", "ARMS", "HANDS", "LEGS", "FEET",
    "HEAD", "TORSO", "SHIELD", "WIELDED", "NO_LOC"};
    for(unsigned int i; i < wear_loc_name.size(); ++i)
    {
        if(wear_loc_name[i] == loc)
        {
            item::wear_location location = static_cast<item::wear_location>(i);
            return location; 
        
        }
    }
    return static_cast<item::wear_location>(-1);
}


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
