/******************************************************************************
 * model.h             CPT323  Assingment 2            Miles Thomas    s3494949
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

#include "character.h"
#include "game_location.h"
#include "item.h"
//#include "login_manager.h"
//#include "io.h"

//using namespace model;

namespace model
{
    //forward declarations
    //class character::player;
    //class character::shopkeeper;


    class model 
    {
        // Attributes
        private :
            //TODO all datatructures curtrently 
            //std::vector to compile, adjust later
            std::vector<character::player> players;
            std::vector<character::shopkeeper> shopkeepers;
            std::vector<game_location::area> areas;
            std::vector<item::item> items;
        // Operations
        public :
            bool binary_save (const std::string& name);
            bool binary_load (const std::string& name);
            bool ascii_save (const std::string& name);
            bool ascii_load (const std::string & name);
            character::player& get_player (int id);
            game_location::area& get_area (int id);
            game_location::room& get_room (int id);
            character::shopkeeper& get_shop_keeper (int id);
            item::item& get_item (int id);
    };
}
