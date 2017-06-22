/******************************************************************************
 * login_manager.h             CPT323  Assingment 2            Miles Thomas    s3494949
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
#include <utility>

#include "character.h"
//#include "game_location.h"
//#include "item.h"
//#include "login_manager.h"
//#include "io.h"
#pragma once
#include "model.h"
#include <map>

namespace model
{
    class login_manager 
    {
        // Attributes
        private :
        //using a vector to store players that are logged in.
        //if they exist in logins, they are logged in.
            std::vector<character::player*> logins;
            //std::map<const character::player, bool> logins;
        // Operations
        public :
            /**
             * \brief you will need to generate a hash from the password - use std::hash for this as that's how I am hashing passwords. 
             * \param name (???)
             * \param password (???) the password actually entered
             * \param player (???)
             * \return bool
             */
            //streamlined function, hash happens in view
            login_manager() : logins(){}
            ~login_manager(){}
            bool login();
            bool is_logged_in (const character::player player);
            character::player& get_current_player(void);
    };
}
