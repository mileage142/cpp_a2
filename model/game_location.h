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
#include <array>
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
            public:         
                //TODO move this elsewhere?  (NUM_DIRECTIONS)
                static const int NUM_DIRECTIONS = 4; 
                int g_room_no;
                int l_room_no;
                area * myarea;
                std::string name;
                std::string description;
                std::array<room*, NUM_DIRECTIONS> exits;
            public:
                room(void): g_room_no(), l_room_no(), myarea(), name(),
                description(), exits(){}
                room(int _g_room_no, int _l_room_no, area* _myarea, 
                std::string _name, std::string _description, 
                std::array<room*, NUM_DIRECTIONS> _exits):
                g_room_no(_g_room_no), l_room_no(_l_room_no), 
                myarea(_myarea), name(_name), description(_description),
                exits(_exits){}

        };
        
        struct connection 
        {
                room * start_room;
                room * end_room;
                model::game_location::direction dir;
                
                connection(void): start_room(nullptr), end_room(nullptr), 
                dir(){}
                connection(room* _start_room, room* _end_room, 
                model::game_location::direction _dir): start_room(_start_room),
                end_room(_end_room), dir(_dir){}
                
        };


        class area 
        {
            // Attributes
            public:
                int id;
                std::string name;
                //TODO all stl_containers set at std::vector to
                std::string description;
                std::vector<connection> entrances;
                std::vector<connection> exits;
                std::vector<room*> rooms;
                
            public:
                area(void): id(), name(), description(), entrances(), exits(), 
                rooms(){}
                area(int _id, std::string _name, std::string _description, 
                std::vector<connection> _entrances, std::vector<connection> 
                _exits, std::vector<room*> _rooms): id(_id), 
                name(_name), description(_description), entrances(_entrances), 
                exits(_exits), rooms(_rooms){}
        };
        game_location::direction get_direction(std::string dir);
        

    }
}
