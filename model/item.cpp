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
}


item::item_type item::get_item_type(wear_location loc)
{
    wear_location wear_loc = loc;
    std::array<std::string, 3>item_type_name{"WEAPON", "ARMOR", "INVALID"};
    //only weapons are wielded and a weapon must be able ot be wielded
    if(wear_loc == static_cast<wear_location>(8))
    {
        return static_cast<item_type>(0);
    }
    //any type that isn't weapon or armor
    if(wear_loc == static_cast<wear_location>(9))
    {
        return static_cast<item_type>(2);
    }
    //hence everything else must be armor
    else
    {
        return static_cast<item_type>(1);
    }
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
*/

