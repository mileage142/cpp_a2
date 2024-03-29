/******************************************************************************
 * model.cpp             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "model.h"

//redefining singleton function for model
std::unique_ptr<model::model> model::model::instance = nullptr;

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
//create all model objects and save into vectors in model
bool model::model::ascii_load (const std::string& name)
{
    //TODO these will need to be entered through file args
    io::ascii_item_loader item_loader;
    item_loader.load_file(name+"/items.txt");
    this->items = item_loader.create_items();
    io::ascii_player_loader player_loader;
    player_loader.load_file(name+"/players.txt");
    this->players = player_loader.create_players();
    io::ascii_area_loader area_loader;
    area_loader.load_file(name+"/areas.txt");
    this->areas = area_loader.create_areas();
    io::ascii_shop_loader shop_loader;
    //If i implement shops?
    //shop_loader.load_file("data/shopkeepers.txt")
    //this->shopkeepers = shop_loader.create_shopkeeper();
    
    return true;
}

model::character::player& model::model::get_player (unsigned int id)
{
    for(unsigned int i = 0; i == players.size(); ++i)
    {    
        if(i == id)
        {
            return players[i];
        }
       //TODO needs exception handling if no players present
       // else
        //{
           // return players[id];
        //}
    }
    return players[id];
}
model::game_location::area* model::model::get_area (int id)

{ 
    for(auto i=areas.begin();i!=areas.end(); ++i)
    {
        if(id == i->id)
        {
            return &(*i);
        }
    }
    return nullptr;
}    

model::game_location::room* model::model::get_room (int id)

{
    for(auto i=areas.begin();i!=areas.end(); ++i)
    {    
        for(auto j=i->rooms.begin(); j!=i->rooms.end(); ++j)
        {
            if(id == j->g_room_no)
            {
                auto room = &(*j);
                return room;

            }
        }
    }
    return nullptr;
}

model::character::shopkeeper& model::model::get_shop_keeper (unsigned int id)
{
    for(unsigned int i = 0; i == shopkeepers.size(); ++i)
    { 
        if(i == id)
        {
            return shopkeepers[i];
        }
        else
        {
        //TODO this should be an exception
            return shopkeepers[id];
        }
    }
    return shopkeepers[id];
}

model::item::item* model::model::get_item (int id)
{
    for(auto i=model::items.begin(); i!=model::items.end(); ++i)
    {
        if(i->id == id)
        {
            return &(*i);
        }
        //TODO exeption
    }

    return nullptr;
}
