/******************************************************************************
 * io.cpp             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *This file populates the model from the data files.
 *
 *
 * ***************************************************************************/
#include "io.h"
using namespace model;

bool io::ascii_loader::load_file(std::string in_file)
{
    std::ifstream file(in_file, std::ifstream::in);
    std::string line;

    if(!file.is_open() || file.fail())
    {
        std::cout << "Player file could not be opened" << std::endl;
        return false;
        //TODO needs proper exception handling

    }
    else
    {
        while(getline(file, line))
        {
            //check for empty line
            if (line == "")
            {
                //TODO check if continue is approros here
                continue;
                //add line
                
            }
            else
            {
                //custom seperator just tabs
                boost::char_separator<char> delim("\t");
                boost::tokenizer<boost::char_separator<char>> tok(line, delim);
                for(boost::tokenizer<boost::char_separator<char>>::iterator 
                it = tok.begin(); it != tok.end(); ++it)
                {
                    this->tokens.push_back(*it);

                }   
            }
        }

    }
    return true;

}

std::vector<character::player> io::ascii_player_loader::create_players()

{
    model * m = model::get_instance();
    unsigned int i = 0;
    //create vector to store all players
    std::vector<character::player> players;
    do 
    {
        //0
        int id = std::stoi(this->tokens[i++], nullptr);
        //1
        std::string username = this->tokens[i++];
        //2    
        long password = std::stol(this->tokens[i++], nullptr);
        //3 room id for game_location::room
        //TODO build function get_room
        game_location::room* location = m->get_room(std::stoi(this->tokens[i++]));
        //4-12 wear slots 1-9
        //TODO create pointer to model::items to make this work
        std::array<item::item*, character::player::NUM_WEAR_SLOTS> equipment
        {};   
            //TODO need to make loop for this, ignore null
        for(int j=0; j<9; ++j)
        {
            std::string temp_equip = this->tokens[i++];
            int temp_int = -1;
            if(temp_equip == "NULL")
            {
                equipment[j] = m->get_item(temp_int); 
            } 
            else
            {
            equipment[j] = m->get_item(std::stoi(temp_equip)); 
            }
        }
        
        //13 # of items in inventory

        if(std::stoi(this->tokens[i++]) == 0)
        {
            std::vector<item::item*> inventory;
        }
        //this else would be different if inventory carryig implemented
        else
        {
            std::vector<item::item*> inventory;
        }
        //only here because the if loop not recognised
        std::vector<item::item*> inventory;
        //14 # of GP
        int gp = std::stoi(this->tokens[i++], nullptr);
        //15 Intelligence
        int intelligence = std::stoi(this->tokens[i++], nullptr);
        //16 Wisdom
        int wisdom = std::stoi(this->tokens[i++], nullptr);
        //17 Strength
        int strength = std::stoi(this->tokens[i++], nullptr);
        //18 Dexterity
        int dexterity = std::stoi(this->tokens[i++], nullptr);
        //19 Constitution
        int constitution = std::stoi(this->tokens[i++], nullptr);
        //20 Hit Points
        int hp = std::stoi(this->tokens[i++], nullptr);
        //21 Mana
        int mana = std::stoi(this->tokens[i++], nullptr);
        //22 Movement allowance
        int moves = std::stoi(this->tokens[i++], nullptr);
            
        //create player
        character::player a_player(id, username, password, intelligence, wisdom, 
        strength, dexterity, constitution, hp, mana, moves, location, equipment, 
        inventory, gp);
        //push player into vector
        players.push_back(a_player);

    }while(i < (this->tokens.size()));
    
    return players;

}

std::vector<game_location::area> io::ascii_area_loader::create_areas()

{ 
    model * m = model::get_instance();
    unsigned int i = 0;
    //create vector to store all areas
    std::vector<game_location::area> areas;
    do 
    {
        int id = std::stoi(this->tokens[i++], nullptr);
        std::string name = this->tokens[i++];
        std::string description = this->tokens[i++];
        std::vector<game_location::connection> entrances;
        std::vector<game_location::connection> exits;
        std::vector<game_location::room> rooms;
        game_location::area an_area(id, name, description, entrances, exits,
        rooms);

        //push area into vector
        areas.push_back(an_area);
       

    }while(i < (this->tokens.size()));
    //build the rooms and put them into the rooms variable   
    io::ascii_room_loader room_loader;
    room_loader.load_file("data/rooms.txt");
    auto temp_room = room_loader.create_rooms();
    for(auto tr = temp_room.begin(); tr!=temp_room.end(); ++tr)
    {
        for(auto a=areas.begin(); a!=areas.end(); ++a)
        {
            if(tr->area_id == a->id)
            {
                //pointer to room inserted into vector in area
                a->rooms.push_back(*tr);
            }

        }

    }
    //This is a bit of a mess sorry.
    io::ascii_connection_loader connection_loader;
    connection_loader.load_file("data/exits.txt");
    auto temp_connection = connection_loader.create_connections();
    for(auto tc=temp_connection.begin(); tc!=temp_connection.end(); ++tc)
    {
       // std::cout << "connection " << tc->start_room << std::endl;

    }
    //std::cout << "connections loaded" << std::endl;
    //std::cout << temp_connection[1].start_room->g_room_no << std::endl;
    //std::cout << temp_connection[1].end_room << std::endl;
    for(unsigned int i=1; i<temp_connection.size(); ++i)
    {
        m->get_room(i);

    }
    
    //build connections and populate to rooms and area
    for(auto tc = temp_connection.begin(); tc!=temp_connection.end(); ++tc)
    {
        //std::cout << *tc.end_room.g_room_no <<std::endl;
        //m->get_room(tc.start_room).push_back(*tc)
                //pointer to room inserted into vector in area
                   // std::cout << "exits in room" << std::endl;

    }

   
    


    return areas;

}

std::vector<game_location::room> io::ascii_room_loader::create_rooms()

{
    unsigned int i = 0;
    //create vector to store all rooms
    std::vector<game_location::room> rooms;
    do 
    {
        //global id
        int g_room_no = std::stoi(this->tokens[i++], nullptr);
        //local id
        int l_room_no = std::stoi(this->tokens[i++], nullptr);
        //area id
        int area_id = std::stoi(this->tokens[i++], nullptr);
        
        //this has been replaced with getting an area_id int. 
        //returns pointer to area
        game_location::area* area = nullptr;
        
        std::string name;
        name.assign(this->tokens[i++]);
        std::string description = this->tokens[i++];

        std::array<game_location::room*, 4> exits { };
      
        game_location::room a_room(g_room_no, l_room_no, area_id, area, name, description, exits);

        //push room into vector
        rooms.push_back(a_room);

    }while(i < (this->tokens.size()));
    return rooms;

}

std::vector<game_location::connection> io::ascii_connection_loader::create_connections()

{
    model * m = model::get_instance();
    unsigned int i = 0;
    //create vector to store all connections
    std::vector<game_location::connection> connections;
    do 
    {
        game_location::room* start_room = m->get_room(std::stoi(this->tokens[i++], nullptr));
        game_location::room* end_room = m->get_room(std::stoi(this->tokens[i++], nullptr));
        std::string dir = this->tokens[i++];
        game_location::direction direction = game_location::get_direction(dir);
        std::string open = this->tokens[i++];

        //create connection object
        game_location::connection a_connection(start_room, end_room, direction);

        //push connection into vector
        connections.push_back(a_connection);
            
    }while(i < (this->tokens.size()));
    
    return connections;
}

std::vector<item::item> io::ascii_item_loader::create_items()
{
    unsigned int i = 0;
    //create vector to store all items
    std::vector<item::item> items;
    do 
    {
        int id = std::stoi(this->tokens[i++], nullptr);
        std::string loc = this->tokens[i++];
        item::wear_location worn_loc = item::get_wear_location(loc);
        std::string name; 
        name.assign(this->tokens[i++]);
        std::string description = this->tokens[i++];
        int price = std::stoi(this->tokens[i++], nullptr);
        item::item_type type = item::get_item_type(worn_loc);
        //create item
        item::item an_item(id, worn_loc, name, description, price, type, 0);
        //push item into vector
        items.push_back(an_item);
            
    }while(i < (this->tokens.size()));
    
    return items;
}


