/******************************************************************************
 * game_location.h             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "game_location.h"
using namespace model;

game_location::direction game_location::get_direction(std::string dir)
{
    std::array<std::string, 7>direction_name{"NORTH", "SOUTH", "EAST", "WEST",
    "UP", "DOWN", "INVALID"};
    //direction direct;
    for(unsigned int i; i < direction_name.size(); ++i)
    {
        if(direction_name[i] == dir)
        {
            //return wear_loc_name[i];
            direction direct = static_cast<direction>(i);
            return direct;
        }
        else
        {
            direction direct = static_cast<direction>(6);
            return direct;
        }
    }
    //return direct;
}
