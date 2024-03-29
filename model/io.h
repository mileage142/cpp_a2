/******************************************************************************
 * io.h             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <list>
#include <fstream>
//for login manager
#include <map>

#include "character.h"
#include "game_location.h"
#include "item.h"
#include "login_manager.h"
//#include "io.h"
#include "model.h"
#include <boost/tokenizer.hpp>



namespace model
{
    namespace io 
    {
        /**
         * \brief you are required to implement these with inheritance and template specialisation. so you should have a template specialisation for each kind of object you wish to save. 
         */
        class ascii_loader 
        {
            // Operations
            protected:
                //TODO obvs this shouldnt be here
                std::vector<std::string> tokens;
            public :
                ascii_loader(): tokens(){}
                ~ascii_loader(){}
                bool load_file(std::string file);
                bool validate ();
                //virtual std::vector<std::string> load_file(std::string in_file);
                friend class model;

        };
        //This class creates a pointer to player
        class ascii_player_loader : public ascii_loader
        {
            private:
                character::player* player_temp;
            public:
            //constructor
            ascii_player_loader() : player_temp(nullptr) {}
            ~ascii_player_loader(){}
            //returns a list of pointers to player that can be added in model
            //std::list<std::unique_ptr<character::player>> load(std::string player_file);
            std::vector<character::player> create_players(void);
        };
       
        class ascii_area_loader : public ascii_loader
        {
            private:
                game_location::area* area_temp;
            public:
            ascii_area_loader() : area_temp(nullptr) {}
            ~ascii_area_loader(){}
            std::vector<game_location::area> create_areas(void); 
            friend class game_location;
            friend class model;
        };
        class ascii_room_loader : public ascii_loader
        {
            private:
                game_location::room* room_temp;
            public:
            ascii_room_loader() : room_temp(nullptr) {}
            ~ascii_room_loader(){}
            std::vector<game_location::room> create_rooms(void);
        };
         class ascii_connection_loader : public ascii_loader
        {
            private:
            game_location::connection* connection_temp;
            public:
            ascii_connection_loader() : connection_temp(nullptr) {}
            ~ascii_connection_loader(){}
            std::vector<game_location::connection> create_connections(void);
        };

        class ascii_shop_loader : public ascii_loader
        {
            private:
                character::shopkeeper* shop_temp;
            public:
            ascii_shop_loader() : shop_temp(nullptr) {}
            ~ascii_shop_loader(){}
            std::vector<character::shopkeeper> create_shopkeepers(void);
        };
        class ascii_item_loader : public ascii_loader
        {
            private:
                item::item* item_temp;
            public:
            //bool load();
            //bool validate();
            ascii_item_loader() : item_temp(nullptr) {}
            ~ascii_item_loader(){}
            std::vector<item::item> create_items(void);
            //std::list<std::unique_ptr<item::item>> load(std::string item_file); 
        };

        /**
         * \brief combine these classes together with the different types of data to load by using multiple inheritance and templating
         */
        class ascii_saver {
            // Operations
            public :
                bool save (std::string fname);
        };
        /**
         * \brief combine these classes together with the different types of data to load by using multiple inheritance and templating
         */
        class binary_loader {
            // Operations
            public :
                bool load (std::string fname);
        };
        /**
         * \brief combine these classes together with the different types of data to load by using multiple inheritance and templating
         */
        class binary_saver {
            // Operations
            public :
                bool save (std::string fname);
        };
    }
}
