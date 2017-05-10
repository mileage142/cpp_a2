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
            public :
                item(): name(0), description(0), wear_loc(), type(), armour_class(0){}
                item(std::string _name, std::string _description,
                wear_location _wear_loc, item_type _type, int _armour_class):        
                name(_name), description(_description), wear_loc(_wear_loc),
                type(_type), armour_class(_armour_class){}
                item* return_item (int id);

        };
    }
}
