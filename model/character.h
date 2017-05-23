/******************************************************************************
 * character.h             CPT323  Assingment 2            Miles Thomas    s3494949
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
#include "game_location.h"
#include "item.h"
//#include "login_manager.h"
//#include "io.h"
//#include "model.h"

//TODO dummy to make complile
//static const int NUM_WEAR_SLOTS = 5;

using namespace model;

namespace model 
{
    namespace character 
    
    {
        //class shopkeeper;
        //class player;
   
   //enums upadted to enum class to prevent redeclartation errors
        enum class purchase_result 
        {
            SUCCESS,
            NOSHOPKEEPER,
            INSUFFICIENT_FUNDS,
            OTHER_FAILURE
        };
        enum class wear_result 
        {
            SUCCESS,
            TOO_LOW_LEVEL,
            WEAR_LOCATION_OCCUPIED,
            NOT_WEARABLE
        };
        enum class move_result 
        {
            SUCCESS,
            DOOR_CLOSED,
            NOEXIT_THERE,
            OTHER_FAILURE
        };

        class shopkeeper 
        {
            // Attributes
            private :
                static const int NUM_WEAR_SLOTS = 5;
                game_location::room * current_room;
                item::item* equipment[NUM_WEAR_SLOTS];
                std::vector<item::item*> inventory;                
                purchase_result buy (int listnum);
                purchase_result buy (std::string name);
                int balance ();
                wear_result wear (const item::item& item);
                void move (game_location::direction dir);

            // Operations
            public :
                shopkeeper(void) : current_room(), equipment(), inventory(){}
                int sell (int id, int value);
                std::string display_wares ();
        };
    /**
     * \brief As we are only modelling a single player game, there is no need to attach operations to the player other than those that change the player state. Otherwise, these should be represented as command requests sent to the controller. 
     */
        class player 
        {
            // Attributes
            public :
                static const int NUM_WEAR_SLOTS = 9;
                int id;
                std::string username;
                /// the hash of the password
                int password;
                const int intelligence;
                const int wisdom;
                const int strength;
                const int dexterity;
                const int constitution;
                int hp;
                int mana;
                int moves;
                /// the room the player is currently in
                model::game_location::room *  location = nullptr;
                //TODO equipment converted from [] to std::array for compilation
                //not really that urgent
                std::array<item::item*, NUM_WEAR_SLOTS> equipment;
                std::vector<model::item::item*> inventory;
                int gold_pieces = 0;
            // Operations
            public :
                 player() : id(0),  username("test"), 
                password(0), intelligence(0), wisdom(0), strength(0), 
                dexterity(0), constitution(0), hp(0), mana(0), moves(0), 
                location(0), equipment(), inventory(), gold_pieces(){}


                
                player(int _id, std::string _username, int _password,int _intelligence, 
                int _wisdom, int _strength, int _dexterity, int _constitution, 
                int _hp, int _mana, int _moves, game_location::room *_location, 
                std::array<item::item*, NUM_WEAR_SLOTS> _equipment, 
                std::vector<item::item*> _inventory, int _gold_pieces) : 
                id(_id), username(_username), password(_password), 
                intelligence(_intelligence), wisdom(_wisdom), 
               strength(_strength), dexterity(_dexterity), 
                constitution(_constitution), hp(_hp), mana(_mana), 
                moves(_moves), location(_location), equipment(_equipment),
                inventory(_inventory), gold_pieces(_gold_pieces){}

                character::purchase_result buy (int listnum);
                character::purchase_result buy (std::string name);
                int balance ();
                character::wear_result wear (const item::item& item);
                void move (game_location::direction dir);
        };
    }
}

