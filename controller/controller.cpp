#include "controller.h"

namespace po = boost::program_options;

std::unique_ptr<controller::controller> controller::controller::instance = nullptr;

int main(int argc, char** argv)
{
    controller::controller * c = controller::controller::get_instance();
    model::model * m = model::model::get_instance();
    try
    {    
        c->load_options(argc, argv);
    }
    catch(const std::invalid_argument& ia)
    {
        std::cout << "Invalid file or directory" << ia.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }


    
        m->ascii_load(c->i_ascii_dir);
    //TODO TEST LINES to show error in room->name
    

        model::login_manager login_manager;
        login_manager.login();

        c->controller::game_loop();
    
}

bool controller::controller::load_options(int ac, char** av)
{
    po::options_description desc("Allowed options");
    desc.add_options()
    ("ascii_load,al", po::value<std::string>(), "Select input directory")
    ("binary_load,bl", po::value<std::string>(), "Select input file")
    ("ascii_save,as", po::value<std::string>(), "Select output directory")
    ("binary_save,bs", po::value<std::string>(), "Select output file");

    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);
    //only ascii load is properly implemented
    if(vm.count("ascii_load"))
    {
        if(boost::filesystem::is_directory(vm["ascii_load"].as<std::string>()))
        {
            controller::i_ascii_dir = vm["ascii_load"].as<std::string>();
        }
    }
    else if(vm.count("binary_load"))
    {
        if(boost::filesystem::is_regular_file(vm["binary_load"].as<std::string>()))
        {
            controller::i_binary_file = vm["binary_load"].as<std::string>();
        }
    }
    else if(vm.count("ascii_save"))
    {
        if(boost::filesystem::is_directory(vm["ascii_save"].as<std::string>()))
        {
            controller::o_ascii_dir = vm["ascii_save"].as<std::string>();
        }
        else
        {
            controller::o_ascii_dir = controller::i_ascii_dir;
        }
    }
    else if(vm.count("binary_save"))
    {
        //this will pick up if no directory is entered as well
        if(boost::filesystem::is_regular_file(vm["binary_save"].as<std::string>()))
        {
            controller::o_binary_file = vm["binary_save"].as<std::string>();
        }
        else
        {
            controller::o_binary_file = controller::i_binary_file;
        }
    }
    else
    {
        
        throw std::invalid_argument("");
        return false;
    }

    return true;
}



bool controller::controller::game_loop()
{
    std::cout << "Welcome to Explore World.  We hope you enjoy your stay!" << 
    std::endl << std::endl;
    model::model * m = model::model::get_instance();
    auto room =  m->get_room(1);
    auto player =  m->get_player(1);
    std::cout << room->name << std::endl;
    std::cout << room->description << std::endl;

    std::string player_input = "";
    bool exit = false;
    //TODO fix
    //auto player = m->get_player
    
    while(exit == false)
    {
        std::cin >> player_input;
        std::cout << player_input << std::endl;
        //dummy to finish program
        exit = true;
    }        
    return true;
}

