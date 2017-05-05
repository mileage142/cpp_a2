/******************************************************************************
 * game_location.h             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "model.h"

//using namespace model::model;

//dummy main for testing
int main(int argv, char** argc)
{
    std::cout << "something" << std::endl;
    model::model m;
    m.ascii_load("fake_name");
    std::cout << "possibly this worked" << std::endl;
}


bool binary_save (const std::string& name)
{
    return true;
}    

bool binary_load (const std::string& name)
{
    return true;
}

bool ascii_save (const std::string& name)
{
    return true;
}
bool model::model::ascii_load (const std::string & name)
{
    model model1;
    //player player0;
    //character::player player1("fred", 123)  ;
    //character player2;
    io::ascii_player_loader player_load();
    std::unique_ptr<character::player> pptr = std::make_unique<character::player>("fred", 123);
    //model1.players.push_back(pptr);
    
    return true;
}

//just work out how to return the unique pointers
//probably through move...

model::character::player& model::model::get_player (unsigned int id)
{
    for(unsigned int i; i == players.size(); ++i)
        if(i == id)
            return players[i];
        //TODO needs exception handling if no players present
    else
        return players[id];
}
model::game_location::area& model::model::get_area (unsigned int id)

{
    for(unsigned int i = 0 ;i == areas.size(); ++i)
        if(i == id)
            return areas[i];
        else
        //TODO execption!
        return areas[id];
}
/*
model::game_location::room& model::model::get_room (int id)
{
    //TODO this is more complex, requires call to game_location
    for(int i = rooms.front; i = rooms.back; ++i)
        if(i == id)
            return rooms[i];
}
*/
model::character::shopkeeper& model::model::get_shop_keeper (unsigned int id)
{
    for(unsigned int i = 0; i == shopkeepers.size(); ++i)
        if(i == id)
            return shopkeepers[i];
    else
        //TODO this should be an exception
        return shopkeepers[id];
}
model::item::item& model::model::get_item (unsigned int id)
{
    for(unsigned int i =0; i == items.size(); ++i)
        if(i == id)
            return items[i];
        else        
        //TODO exeptions!!!
            return items[id];
}
