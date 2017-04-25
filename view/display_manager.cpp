#include "display_manager.h"

int main(int argc, char** argv)
{
    view::display_manager display;
    display.view::display_manager::display_welcome_screen();
}


void view::display_manager::display_welcome_screen()
{
    std::string username;
    std::string password;
    std::cout   << "Welcome to Explore World" << std::endl
                << "-------------------------"  << std::endl
                << "Please enter your username: " << std::endl;
    std::cin >> username;
    std::cout   << "Please enter your password" << std::endl;
    std::cin >> password;
    
    //TODO note that all password references neeed to be hashed
    while(password != "dino")
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
}

//void display_room (game_location::room& room)


std::string get_input()
{
    std::string input;
    std::cin >> input;
    return input;
}

std::tuple<std::string, int> display_login_details()
{
    //TODO turn these variables into calls to the model
    //TODO also needs to be integrated with welcome screen
    //as per uml instructions
    std::tuple<std::string, int> user_pass;
    user_pass =  std::make_tuple ("auser", 12345);
    std::cout << "Login details: "  << std::endl;
    return user_pass;

}








