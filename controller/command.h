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
             virtual bool perform_command (const std::string& command_name,  ...);
             virtual bool add_command (command command);
    };
   
   class look : public command
    {
    private:

    public:
        //look() : {}
        bool perform_command(look);
        bool add_command(look);
        //std::string item_look(std::string name);
        //std::string direction_look(std::string dir);
    };
    class move : public command
    {
        private:

        public:
        //move() : {}
        bool perform_command(move);
        bool add_command(move);

        //void move(direction) :{}
    };
    
}
