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
#include <iostream>

#include "character.h"
#include "game_location.h"
#include "item.h"
//#include "login_manager.h"
#include "io.h"

//using namespace model;

namespace model
{
    //forward declarations
    //class character::player;
    //class character::shopkeeper;


    class model 
    {
        // Attributes
        // TODO make PRIVATE!
        public :
            //TODO all datatructures curtrently 
            //std::vector to compile, adjust later
            static std::unique_ptr<model> instance;
            std::vector<character::player> players;
            std::vector<character::shopkeeper> shopkeepers;
            std::vector<game_location::area> areas;
            std::vector<item::item> items;
        // Operations
        public :

            model() : players(0), shopkeepers(0), areas(0), items(0){}
            virtual ~model(){}
            bool binary_save (const std::string& name);
            bool binary_load (const std::string& name);
            bool ascii_save (const std::string& name);
            bool ascii_load (void);
            character::player& get_player (unsigned int id);
            game_location::area* get_area (int id);
            game_location::room* get_room (int id);
            character::shopkeeper& get_shop_keeper (unsigned int id);
            item::item* get_item (int id);
            friend class ascii_loader;
            friend class ascii_player_loader;
            static model* get_instance(void)
            {
                if(instance != nullptr)
                {
                    std::cout << "well i guess i can't print the instance" << std::endl;
                }
                if(instance == nullptr)
                {
                    instance = std::unique_ptr<model>(new model());
                }
                return instance.get();
            }


    };
}
