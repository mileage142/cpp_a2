#pragma once
#include <functional>
#include <memory>
#include "../model/model.h"
#include "../view/display_manager.h"
namespace controller {
    /**
     * \brief This class contains all the methods for invoking commands. All requests to change the state of the game should be routed through this controller object. The view should not change the data model (anything in the model namespace) directly.
     */
    class controller 
    {
        private:
        static std::unique_ptr<controller> instance;
        public:
        //controller(){}
        //virtual ~controller(){}
        bool login(void);
        bool game_loop(void);
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

