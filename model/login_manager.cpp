/******************************************************************************
 * login_manager.cpp    CPT323  Assingment 2        Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "login_manager.h"

using namespace model;

bool login_manager::login()
{
    model * m = model::get_instance();
    std::cout << m->players[1].id << std::endl;
  /*  for(unsigned int i=0; i < m->players.size(); ++i)
    {
        auto login_details =
        std::make_tuple(m->players[i].username, m->players[i].password);
        view::display_manager display;
        if(login_details == display.display_login_details())
        {
            std::cout << m->players[i] <<std::endl;
            //this->logins.push_back(m->players[i]);
            //login_manager::logins[m->players[i]] = true;
            return true;
        }
    }*/
    return false;
}    

bool login_manager::is_logged_in (const character::player player)
{
   // return login_manager::logins.find(player);
}

character::player& login_manager::get_current_player(void)
{
    model * m = model::get_instance();
    for(unsigned int i=0; i < m->players.size(); ++i)
    {
        if(login_manager::is_logged_in(m->players[i]))
        {
            return m->players[i];
        }
    }
}
