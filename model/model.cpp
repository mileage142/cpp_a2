/******************************************************************************
 * model.cpp             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "model.h"

//using namespace model::model;
//redefining singleton function for model
std::unique_ptr<model::model> model::model::instance = nullptr;
//dummy main for testing
/*int main(int argv, char** argc)
//this main will become model::ascii_load
{
    std::cout << "something" << std::endl;
    io::ascii_item_loader item_loader;
    item_loader.load_file("data/items.txt");
    item_loader.create_item();
    model::model * m = model::model::get_instance();
    //std::unique_ptr<model::model> m = make_unique<model::model>();

    m->ascii_load();
    //TODO take out function for checking load!
    
    for(auto it = m->items.begin(); it != m->items.end(); ++it)
    { 
        std::cout << it->name << std::endl;
        std::cout << it->description << std::endl;
    }
    for(auto it = m->areas.begin(); it != m->areas.end(); ++it)
    { 
        std::cout << it->description << std::endl;
        //std::cout << it->rooms.begin()->name <<std::endl;
        for(auto it2 = it->rooms.begin(); it2!=it->rooms.end();++it2)
        {
            //std::cout << *it2 <<std::endl;
            //std::cout << (*it2)->name << std::endl;
        }
    }
    for(auto it = m->players.begin(); it != m->players.end(); ++it)
    { 
        std::cout << it->username << std::endl;
    }
    int value = 2;
    auto temp = (m->get_room(value));
    //std::cout << temp->g_room_no << std::endl;
    //std::cout << temp->l_room_no << std::endl;
    //std::cout << temp->area_id << std::endl;
    //std::cout << temp->name << std::endl;
    //std::cout << "description " << temp->description << std::endl;
   // io::ascii_loader player_loader;
   // player_loader.load_file("data/players.txt");
    std::cout << "end of main" << std::endl;
}*/
/* 
static model::model* get_instance(void)
{
    if(instance == nullptr)
    {
        instance = std::unique_ptr<model::model>(new model::model());
    }
    return instance.get();
}
*/

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
bool model::model::ascii_load (void)
{
    //TODO these will need to be entered through file args
    io::ascii_item_loader item_loader;
    item_loader.load_file("data/items.txt");
    this->items = item_loader.create_item();
    //TODO these will load the other bits into model
    io::ascii_player_loader player_loader;
    player_loader.load_file("data/players.txt");
    this->players = player_loader.create_player();
    io::ascii_area_loader area_loader;
    area_loader.load_file("data/areas.txt");
    this->areas = area_loader.create_area();
    io::ascii_shop_loader shop_loader;
    /*shop_loader.load_file("data/shopkeepers.txt")
    this->shopkeepers = shop_loader.create_shopkeeper();
   */
   /* 
    for(auto it = items.begin(); it != items.end(); ++it)
        { 
            if(it->id == 9)
            {
                std::cout << it->description << std::endl;
            }
        }
   */
   
   // io::ascii_item_loader pl;
   // io::ascii_loader * pl1 = &pl;
   // pl1->io::ascii_loader::load_file("/data/item.txt");

    //
    //TODO call all the io::load functions and put their vectors in the object
    //player player0;
    //character::player player1("fred", 123)  ;
    //character player2;
    //io::ascii_player_loader player_load();
    //std::unique_ptr<character::player> pptr = std::make_unique<character::player>();
    //model1.players.push_back(pptr);
    //std::cout << pptr->username << std::endl;
    return true;
}

//just work out how to return the unique pointers
//probably through move...

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
            std::cout << "id: " << id <<std::endl;
            std::cout << "room no: " << j->g_room_no << std::endl;
            //std::cout << "BAD NAME: " << j->name << std::endl;
            //std::cout << "BAD DESCRIPTOR: " << j->description << std::endl;
            if(id == j->g_room_no)
            {
                auto room = &(*j);
               // std::cout << room->name << std::endl;
               // std::cout << room->description << std::endl;
                return room;

            }
        }
    }
    return nullptr;
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

    /*for(unsigned int i =0; i == items.size(); ++i)
    {
        if(i == id)
        {
            return items[i];
        }
        else        
        {
        //TODO exeptions!!!
            return items[id];
        }
    }*/ 
}
