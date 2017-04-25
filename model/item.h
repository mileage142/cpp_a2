/******************************************************************************
 * item.h             CPT323  Assingment 2            Miles Thomas    s3494949
 *
 *
 *
 *
 * ***************************************************************************/
#pragma once



namespace model
{
    namespace item 
    {
        enum class wear_location 
        {
            WRISTS,
            ARMS,
            HANDS,
            LEGS,
            FEET,
            HEAD,
            TORSO,
            SHIELD,
            WIELDED,
            NO_LOC = -1
        };
        enum class item_type 
        {
            WEAPON,
            ARMOR,
            INVALID
        };
        class item 
        {
            // Attributes
            private :
                int id;
                std::string name;
                std::string description;
                model::item::wear_location wear_loc;
                model::item::item_type type;
                int armour_class;
        };
    }
}
