/******************************************************************************
 * login_manager.cpp    CPT323  Assingment 2        Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#include "login_manager.h"

using namespace model;

bool login()
{
    model::model * m = model::model::get_instance();
    for(auto i=0; i < m->players.size(); ++i)
    {
        auto login_details =
        std::make_tuple(m->players[i].username, m->players[i].password);
        view::display_manager display;
        if(login_details == display.display_login_details())
        {
            return true;
        }
    }
    return false;
}    

bool is_logged_in (const character::player& player)
{
    return login_manager::logins.find(player);
}

character::player& get_current_player(void)
{
    model::model * m = model::model::get_instance();
    for(auto i=0; i < m->players.size(); ++i)
    {
        if(is_logged_in(m->players[i]))
        {
            return m->players[i];
        }
    }
}
