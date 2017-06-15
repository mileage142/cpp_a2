#include <string>
#include <map>
#include <functional>

namespace controller 
{

    /**
     * \brief Implement your commands for the system as children of the command class. You will need to use inheritance and polymorphism
     */
    //new edits my me
    enum class commands
    {
        LOOK,
        OPEN,
        CLOSE,
        WEAR,
        REMOVE,
        MOVE,
        BUY
     };


    class command// : public std::function
    {
        // Attributes
        private :
            static std::map<std::string, command> commands;
        // Operations
        public :
            /**
             * \brief each command will have different parameters
             * \param command_name (???)
             * \param ... (???)
             * \return bool
             */
            static bool perform_command (const std::string& command_name,  ...);
            static bool add_command (command command);
    };
   /*
   class look : public command
    {
    private:

    public:
        look() : {}
        look(direction) : {}
        look(item) : {}
        std::string item_look(std::string name);
        std::string direction_look(std::string dir);
    };
    class move : public command
    {
        private:

        public:

        void move(direction) :{}
    }
    */
}
