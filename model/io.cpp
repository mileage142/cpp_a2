/******************************************************************************
 * io.h             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "io.h"
using namespace model;

std::list<std::unique_ptr<player>> io::ascii_player_loader::load(std::string player_file)
{
    std::list<std::unique_ptr<player>> players;
    std::ifstream file(player_file)
    std::string line;
    

    if(!file.is_open() || file.fail)
    {
        std::cout << Player file could not be opened << std::endl;
        return contents;
    }

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
            boost::tokenzer<boost::char_separator<char>> tokenizer;
            tokenizer tok{line}
            tokenizer::iterator it = tok.begin(); 
            int player_ID = it;
            player::player() player_ID;
            ++it;
            std::string username = it;
            ++it;
            int pass_hash = it;
            //putting character details into an array for eaisier handling
            int details[20];
            int count = 0;
            for(it; it != tok.end(); ++it)
            {
                details[count] = it;
                ++count;
            }
            //TODO pre build location equipment inventory
            temp_location = 
            //TODO needs to be an object with these things
            temp_equipment[] = {details[1], details[2], details[4], details[5],
            details[6], details[7], details[8], details[9]}
            
            
            //if inventory is empty
            std::vector<item::item*> temp_inventory;
            if(details[13] == 0)
            {
                temp_inventory = nullptr;
            }
            else
            {
                //add the number of items specified in player file
                for(int i = 0; i < details[13]; ++i]
                {
                    std::unique_ptr<item::item> i = std::make_unique<item::item>
                    temp_inventory.push_back(std::move(i));
                }
             }

            std::unique_ptr<character::player> pptr = 
            std:make_unique<character::player>player player_ID(username, 
            pass_hash, details[12], details[13], details[14], details[15], 
            details[16], details[17], details[18], details[19], temp_location, 
            temp_equipment, temp_inventory, details[11])


            

