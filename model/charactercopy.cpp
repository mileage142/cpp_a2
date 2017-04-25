#include "character.h"

using namespace model::character;


//shopkeeper
int model::character::shopkeeper::sell (int id, int value)
{
    //TODO replace this with int of item
    return 1; 
}

std::string model::character::shopkeeper::display_wares()
{
    //TODO replace this with wares
    return "item";
}



//player
purchase_result player::buy (int listnum)
{
    //TODO write logic
    return purchase_result::SUCCESS;
}

purchase_result player::buy (std::string name)
{
    //TODO write logic
    return purchase_result::SUCCESS;
}

int player::balance()
{
    return gold_pieces;

}

wear_result player::wear (const item::item& item)
{
    //TODO Write logic
    return wear_result::SUCCESS;
}

void player::move (game_location::direction dir)
{
    
}

