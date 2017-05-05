/******************************************************************************
 * io.h             CPT323  Assingment 2            Miles Thomas    s3494949
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

#include "character.h"
#include "game_location.h"
#include "item.h"
#include "login_manager.h"
//#include "io.h"
#include "model.h"

namespace model
{
    namespace io {
        /**
         * \brief you are required to implement these with inheritance and template specialisation. so you should have a template specialisation for each kind of object you wish to save. 
         */
        class ascii_loader {
            // Operations
            public :
                bool load ();
                bool validate ();
        };
        /**
         * \brief combine these classes together with the different types of data to load by using multiple inheritance and templating
         */
        class ascii_saver {
            // Operations
            public :
                bool save (std::string fname);
        };
        /**
         * \brief combine these classes together with the different types of data to load by using multiple inheritance and templating
         */
        class binary_loader {
            // Operations
            public :
                bool load (std::string fname);
        };
        /**
         * \brief combine these classes together with the different types of data to load by using multiple inheritance and templating
         */
        class binary_saver {
            // Operations
            public :
                bool save (std::string fname);
        };
    }
}