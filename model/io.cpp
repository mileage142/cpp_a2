/******************************************************************************
 * io.h             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "io.h"
using namespace model;

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

bool io::ascii_item_loader::create_item()
{
    std::cout << "create_item()?!!!!!!" << std::endl;
    unsigned int item_length = 5;
    
    //for(unsigned int i=-1; i > this->tokens.size(); ++i)
    
    //{
        //using postincrement in order to keep indexes unsigned
        unsigned int i = 0;
        std::cout << i << std::endl;   

        std::cout << this->tokens.size() << std::endl;   
        do 
        {
           std::string::size_type sz;
            //std::cout << "first class" << std::endl;
            //item::item tokens[i+1](std::stoi(tokens[++i]), tokens[++i],
            //tokens[++i], tokens[++i], (std::stoi(tokens[++i]), 0, 0);
            
            int id = std::stoi(this->tokens[i++], nullptr);
            std::cout << id << std::endl;
            std::string loc = this->tokens[i++];
            item::wear_location worn_loc = item::wear_location(loc);
            //std::cout << worn_loc << std::endl;
            std::string name = this->tokens[i++];
            std::cout << name << std::endl;
            std::string description = this->tokens[i++];
            std::cout << description << std::endl;
            int price = std::stoi(this->tokens[i++], nullptr);
            std::cout << price << std::endl;
            //std::cout << this->tokens[++i] << std::endl;
            item::item_type type = item::item_type(1);
            item::item an_item(id, worn_loc, name, description, price, type, 0);
            

            std::cout << i << std::endl;

            std::cout << "end of class" << std::endl;
            
       } while(i < (this->tokens.size()));
    //}
    return true;
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
            

