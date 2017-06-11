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
    game_location::direction direct;
    for(unsigned int i=0; i < direction_name.size(); ++i)
    {
        if(direction_name[i] == dir)
        {
            //return wear_loc_name[i];
            direct = static_cast<direction>(i);
            return direct;
        }
        else
        {
            direct = static_cast<direction>(6);
            //return direct;
        }
    }
    return direct;
}
