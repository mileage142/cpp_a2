#pragma once
#include <string>
#include <tuple>
#include <iostream>
#include <functional>
#include "../controller/controller.h"
namespace view {
    /**
     * \brief This would be a good place to put your main function
     */
    class display_manager 
    {
        // Attributes
        private :
           //TODO fix attributes commented out for iterative design
           // controller::controller * controller;
           // model::model * model;
           std::string dummy;
        // Operations
        public :
            //TODO make display manager singleton
            display_manager(): dummy() {}
            
            void display_welcome_screen (void);
            /**
             * \brief see assignment specifications for details on the output here.
             * am room (???)
             * TODO uncomment display_room
             */
            //void display_room (game_location::room& room);
            /**
             * \brief gets input from the user during a normal turn of the game
             * \return std::string
             */
            std::string get_input ();
            /**
             * \brief displays output asking for username and password and returns a tuple with the username and hash of the password entered
             * \return std::tuple<std::string,int>
             */
            std::tuple<std::string,int> display_login_details ();
            //needs a get_login_details fn in controller (which strips out login from  model::get_player)
    };
}

