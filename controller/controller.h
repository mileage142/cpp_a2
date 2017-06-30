#pragma once
#include <functional>
#include <memory>
#include <iostream>
#include <stdexcept>
#include "../model/model.h"
#include "../view/display_manager.h"
#include <boost/program_options.hpp>
#include <boost/filesystem.hpp>
namespace controller 
{
    /**
     * \brief This class contains all the methods for invoking commands. All requests to change the state of the game should be routed through this controller object. The view should not change the data model (anything in the model namespace) directly.
     */
    namespace po = boost::program_options;
    
    class controller 
    {
        private:
        static std::unique_ptr<controller> instance;
        public:
        std::string i_ascii_dir;
        std::string i_binary_file;
        std::string o_ascii_dir;
        std::string o_binary_file;
        public:
        controller(){}
        virtual ~controller(){}
        bool login(void);
        bool game_loop(void);
        po::variables_map vm;
        bool load_options(int, char**);
        //get controller singelton instance
        static controller* get_instance(void)
        {
            if(instance == nullptr)
            {
                instance = std::unique_ptr<controller>(new controller());
            }
            return instance.get();
        }
    };
}


