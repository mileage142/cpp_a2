/******************************************************************************
 * game_location.h  CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#pragma once
#include <string>
#include <vector>
#include <memory>
//for login manager
#include <map>

//#include "character.h"
//#include "game_location.h"
//#include "item.h"
//#include "login_manager.h"
//#include "io.h"
//#include "model.h"

namespace model
{
    namespace game_location 
    {
        
        enum class direction 
        {
            NORTH,
            SOUTH,
            EAST,
            WEST,
            UP,
            DOWN,
            INVALID
        };
     
       //forward declaration    
       class area;
       class room;

       class room 
        {
            // Attributes
            private:         
                //TODO move this elsewhere?  (NUM_DIRECTIONS)
                static const int NUM_DIRECTIONS = 1; 
                int g_room_no;
                int l_room_no;
                area * myarea;
                std::string name;
                std::string description;
                std::unique_ptr<room> exits[NUM_DIRECTIONS];
            public:
                room(void): g_room_no(), l_room_no(), myarea(), name(),
                description(), exits(){}
        };
        
        struct connection 
        {
                room * start_room;
                room * end_room;
                model::game_location::direction dir;
        };


        class area 
        {
            // Attributes
            private:
                int id;
                std::string name;
                //TODO all stl_containers set at std::vector to
                //start with
                std::vector<connection> entrances;
                std::vector<connection> exits;
                std::vector<std::unique_ptr<room>> rooms;
                std::string description;
            public:
                area(void): id(), name(), entrances(), exits(), rooms(),
                description(){}
        };

        

    }
}
