/******************************************************************************
 * io.h             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "io.h"
using namespace model;

std::unique_ptr<model::model> model::model::instance = nullptr;

bool io::ascii_loader::load_file(std::string in_file)
{
    //std::vector<std::string> lines;
    //std::list<std::unique_ptr<character::player>> players;
    std::ifstream file(in_file, std::ifstream::in);
    //file.open(in_file);
    std::string line;
    //io::ascii_loader loader; 

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
            std::cout << "into file processing" << std::endl;
            //check for empty line
            if (line == "")
            {
                //TODO check if continue is approros here
                continue;
                //add line
                
            }
            else
            {

                std::cout << "tokenising" << std::endl;
                //TODO may need to make custom seperator
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
}

std::vector<character::player> io::ascii_player_loader::create_player()
{
    model * m = model::get_instance();
    std::cout << "create_player()?!!!!!!" << std::endl;
    unsigned int i = 0;
    std::cout << i << std::endl;   
    std::cout << this->tokens.size() << std::endl;   
    //create vector to store all players
    std::vector<character::player> players;
    do 
    {
        //0
        int id = std::stoi(this->tokens[i++], nullptr);
        std::cout << id << std::endl;
        //1
        std::string username = this->tokens[i++];

        std::cout << "username loaded" << std::endl;
        //2    
        long password = std::stol(this->tokens[i++], nullptr);
        std::cout << password << std::endl;
        
        std::cout << "password loaded" << std::endl;
        //3 room id for game_location::room
        //TODO build function get_room
        game_location::room* location = m->get_room(std::stoi(this->tokens[i++]));
        std::cout << "room loaded" << std::endl;
        //4-12 wear slots 1-9
        //TODO create pointer to model::items to make this work
        std::array<item::item*, character::player::NUM_WEAR_SLOTS> equipment
        {};   
        std::cout << "load equip" << std::endl;
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
            std::cout << temp_equip << std::endl;
            std::cout << "temp_equip" << std::endl;
        }
            /*
            m->get_item(std::stoi(this->tokens[i++])),
            m->get_item(std::stoi(this->tokens[i++])),
            m->get_item(std::stoi(this->tokens[i++])),
            m->get_item(std::stoi(this->tokens[i++])),
            m->get_item(std::stoi(this->tokens[i++])),
            m->get_item(std::stoi(this->tokens[i++])),
            m->get_item(std::stoi(this->tokens[i++])),
            m->get_item(std::stoi(this->tokens[i++]))
            */        
        std::cout << "equipment loaded" << std::endl;
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
        std::cout << "gp" << std::endl;
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
        //troubleshooting
        std::cout << a_player.username << std::endl;            
        //TODO move this code for accessing players!
        std::cout << "player loaded" << std::endl;
        for(auto it = players.begin(); it != players.end(); ++it)
        { 
            if(it->id == 2)
            {
                std::cout << it->username << std::endl;
            }
        }
        std::cout << i << std::endl;
        std::cout << "end of class" << std::endl;
            
    }while(i < (this->tokens.size()));
    
    return players;
}

std::vector<game_location::area> io::ascii_area_loader::create_area()
{ 
    //model * m = model::get_instance();
    std::cout << "create_area()?!!!!!!" << std::endl;
    unsigned int i = 0;
    std::cout << i << std::endl;   
    std::cout << this->tokens.size() << std::endl;   
    //create vector to store all areas
    std::vector<game_location::area> areas;
    do 
    {
        std::cout << "start area" << std::endl;

        int id = std::stoi(this->tokens[i++], nullptr);
        std::cout << id << std::endl;

        std::string name = this->tokens[i++];
        std::string description = this->tokens[i++];
        std::cout << description << std::endl;
        std::vector<game_location::connection> entrances;
        std::vector<game_location::connection> exits;
        std::vector<game_location::room*> rooms;
        game_location::area an_area(id, name, description, entrances, exits,
        rooms);

        //push area into vector
        areas.push_back(an_area);
        //troubleshooting
        //std::cout << an_area.description << std::endl;            
       
        std::cout << i << std::endl;
        std::cout << "end of class" << std::endl;
    }while(i < (this->tokens.size()));
    //build the rooms and put them into the rooms variable   
    io::ascii_room_loader room_loader;
    room_loader.load_file("data/rooms.txt");
    auto temp_room = room_loader.create_room();
    std::cout << "rooms loaded" << std::endl;
    for(auto tr = temp_room.begin(); tr!=temp_room.end(); ++tr)
    {
        for(auto a=areas.begin(); a!=areas.end(); ++a)
        {
            std::cout << temp_room[5].g_room_no << std::endl;
            std::cout << a->id << std::endl;
            //THIS IS THE ISSUE!!!
            //circular reference, need to give temp room an int in building
            //then turn it into an area later.
            std::cout << tr->area_id << std::endl;
            if(tr->area_id == a->id)
            {
                std::cout << temp_room[1].g_room_no << std::endl;
                std::cout << tr->area_id << std::endl;
                //game_location::room* room = &(*tr);
                a->rooms.push_back(&(*tr));
            }

        }
    }
   
   //m->areas.rooms = room_loader.create_room();
    
    //build connections and populate to rooms and area


    return areas;
}

std::vector<game_location::room> io::ascii_room_loader::create_room()
{
    model * m = model::get_instance();
    std::cout << "create_room()?!!!!!!" << std::endl;
    unsigned int i = 0;
    std::cout << i << std::endl;   
    std::cout << this->tokens.size() << std::endl;   
    //create vector to store all rooms
    std::vector<game_location::room> rooms;
    do 
    {
        int g_room_no = std::stoi(this->tokens[i++], nullptr);
        //global id
        int l_room_no = std::stoi(this->tokens[i++], nullptr);
        
        int area_id = std::stoi(this->tokens[i++], nullptr);
        
        //this has been replaced with getting an area_id int. 
        //returns pointer to area
        //game_location::area* area = m->get_area(std::stoi(this->tokens[i++], nullptr));
        game_location::area* area = nullptr;

        std::string name = this->tokens[i++];
        std::string description = this->tokens[i++];
        std::cout << description << std::endl;

        std::array<game_location::room*, 4> exits { };
      
        game_location::room a_room(g_room_no, l_room_no, area_id, area, name, description, exits);

        //push room into vector
        rooms.push_back(a_room);
        //troubleshooting
        //std::cout << a_room.description << std::endl;            
        //TODO move this code for accessing rooms!
        std::cout << i << std::endl;
        std::cout << this->tokens.size() << std::endl;
        std::cout << "end of room" << std::endl;
            
    }while(i < (this->tokens.size()));
    //std::unique_ptr<rooms> p_rooms = std::make_unique<rooms>();    
    std::cout << "out of room loop" << std::endl;
    return rooms;
}

std::vector<game_location::connection> io::ascii_connection_loader::create_connection()
{
    model * m = model::get_instance();
    std::cout << "create_connection()?!!!!!!" << std::endl;
    unsigned int i = 0;
    std::cout << i << std::endl;   
    std::cout << this->tokens.size() << std::endl;   
    //create vector to store all connections
    std::vector<game_location::connection> connections;
    do 
    {
        game_location::room* start_room = m->get_room(std::stoi(this->tokens[i++], nullptr));

        game_location::room* end_room = m->get_room(std::stoi(this->tokens[i++], nullptr));
       
        std::string dir = this->tokens[i++];
        //TODO write enum cast for direction
        game_location::direction direction = game_location::get_direction(dir);

        

        //create connection object
        game_location::connection a_connection(start_room, end_room, direction);

        //push connection into vector
        connections.push_back(a_connection);
        //troubleshooting
        std::cout << i << std::endl;
        std::cout << "end of connection" << std::endl;
            
    }while(i < (this->tokens.size()));
    
    return connections;
}

std::vector<item::item> io::ascii_item_loader::create_item()
{
    std::cout << "create_item()?!!!!!!" << std::endl;
    unsigned int i = 0;
    std::cout << i << std::endl;   
    std::cout << this->tokens.size() << std::endl;   
    //create vector to store all items
    std::vector<item::item> items;
    do 
    {
        int id = std::stoi(this->tokens[i++], nullptr);
        std::cout << id << std::endl;

        std::string loc = this->tokens[i++];
        item::wear_location worn_loc = item::get_wear_location(loc);
            
        std::string name = this->tokens[i++];
        std::cout << name << std::endl;
            
        std::string description = this->tokens[i++];
        std::cout << description << std::endl;
            
        int price = std::stoi(this->tokens[i++], nullptr);
        std::cout << price << std::endl;
            
        item::item_type type = item::get_item_type(worn_loc);
        //create item
        item::item an_item(id, worn_loc, name, description, price, type, 0);
        //push item into vector
        items.push_back(an_item);
        //troubleshooting
        std::cout << an_item.description << std::endl;            
        //TODO move this code for accessing items!
        for(auto it = items.begin(); it != items.end(); ++it)
        { 
            if(it->id == 9)
            {
                std::cout << it->description << std::endl;
            }
        }
        std::cout << i << std::endl;
        std::cout << "end of item" << std::endl;
            
    }while(i < (this->tokens.size()));
    
    return items;
}


            /*
std::list<std::unique_ptr<character::player>> io::ascii_player_loader::load(std::string player_file)
{
    std::list<std::unique_ptr<character::player>> players;
    std::ifstream file("/data/players.txt");
    std::string line;
    

    if(!file.is_open() || file.fail())
    {
        std::cout << "Player file could not be opened" << std::endl;
        return players;
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
        }
        else
        {
            //TODO may need to make custom seperator
            boost::tokenizer<boost::char_separator<char>> tok(line);
            boost::tokenizer<boost::char_separator<char>>::iterator it = tok.begin(); 
            std::string player_ID = *it;
            //player::player() player_ID;
            ++it;
            std::string username = *it;
            ++it;
            int pass_hash = std::stoi(*it);
            //putting character details into an array for eaisier handling
            int details[20];
            int count = 0;
            for(; it != tok.end(); ++it)
            {
                details[count] = std::stoi(*it);
                ++count;
            }
            //TODO pre build location equipment inventory
            int temp_location = -1; 
            //TODO needs to be an object with these things
            int temp_equipment[] = {details[1], details[2], details[4], details[5],
            details[6], details[7], details[8], details[9]};
            
            
            //if inventory is empty
            std::vector<item::item*> temp_inventory;
            if(details[13] == 0)
            {
                item::item* temp_inventory = nullptr;
            }
            else
            {
                //add the number of items specified in player file
                for(int i = 0; i < details[13]; ++i)
                {
                    //item::item::return_item(i);
                   // std::unique_ptr<item::item> item = std::make_unique<item::item>(i, 
                    temp_inventory.push_back(std::move(item::item::return_item(i)));
                }
             }
            std::cout << &temp_inventory << std::endl;
            //std::unique_ptr<character::player> pptr = 
            //std::make_unique<character::player>
            player player_ID(username, 
            pass_hash, details[12], details[13], details[14], details[15], 
            details[16], details[17], details[18], details[19], temp_location, 
            temp_equipment, temp_inventory, details[11])
        }
        return players;

}
*/
            

