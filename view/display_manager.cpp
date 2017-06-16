#include "display_manager.h"
/*
int main(int argc, char** argv)
{
    view::display_manager display;
    controller::controller* c = controller::controller::get_instance(); 
    display.view::display_manager::display_welcome_screen();

}
*/

std::tuple<std::string, int> view::display_manager::display_login_details()
{
    std::string username;
    std::string raw_password;
    int password;
    std::cout   << "Welcome to Explore World" << std::endl
                << "-------------------------"  << std::endl
                << "Please enter your username: " << std::endl;
    std::cin >> username;
    std::cout   << "Please enter your password" << std::endl;
    std::cin >> raw_password;
    //hashing password in view before it can go anywhere else
    std::hash<std::string> hash_fn;
    password = hash_fn(raw_password);

    auto login = std::make_tuple(username, password);
    return login;
}
    
    
    //TODO note that all password references neeed to be hashed
   /* while(password != "dino")
    {
        std::cout << "Error: invalid password entered.  Please try again" 
        << std::endl;
        std::cin >> password;
    }
    if(password == "dino")
    {
        std::cout << "Welcome to Explore World.  We hope you enjoy your stay!" 
        << std::endl;
    }
    */


//void display_room (game_location::room& room)


std::string get_input()
{
    std::string input;
    std::cin >> input;
    return input;
}

void display_welcome_screen()
{
    
    controller::controller* c = controller::controller::get_instance(); 
    /*while(c->login() == false)
    {
        std::cout << "Error: invalid password entered.  Please try again" 
        << std::endl;
    }
        
    std::cout << "Welcome to Explore World.  We hope you enjoy your stay!"
    << std::endl;
    */
}








