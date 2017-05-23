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
           // item::wear_location get_wear_location(std::string wear_loc)
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
            // TODO make this private again
            public :
                int id;
                model::item::wear_location wear_loc;
                std::string name;
                std::string description;
                int price;
                model::item::item_type type;
                int armour_class;
            public :
                item(): id(0), wear_loc(), name(0), description(0), price(0), type(), armour_class(0){}
                item(int _id, wear_location _wear_loc, std::string _name, 
                std::string _description, int _price, item_type _type, 
                int _armour_class):        
                id(_id), wear_loc(_wear_loc), name(_name), 
                description(_description), price(_price), 
                type(_type), armour_class(_armour_class){}
                // ~item();
                item* return_item (int id);
         //       std::string get_wear_location(item::wear_location wear_loc)
        };
        wear_location get_wear_location(std::string loc);
        item_type get_item_type(wear_location loc);
    }
}
