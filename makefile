#CPT323 Assingment 2  Makefile

# Miles Thomas s3494949
#
#usefull -W flags, -Weffc++
#
#
#all: modell viewer control
#		g++ -o game modell view controller -g
all:  character.o game_location.o item.o io.o model.o login_manager.o display_manager.o command.o controller.o 
		g++ -o game character.o game_location.o item.o io.o model.o login_manager.o display_manager.o command.o controller.o -g 
#Model

modell:  character.o game_location.o item.o io.o model.o login_manager.o 
		g++ -o modell character.o game_location.o item.o io.o model.o login_manager.o -g 

game_location.o: model/game_location.cpp model/game_location.h
		g++ -c -Wall -pedantic -std=c++14 model/game_location.cpp

item.o: model/item.cpp model/item.h
		g++ -c -Wall -pedantic -std=c++14 model/item.cpp

login_manager.o: model/login_manager.cpp model/login_manager.h
	    g++ -c -Wall -pedantic -std=c++14  model/login_manager.cpp

io.o: model/io.cpp model/io.h
		g++ -c -Wall -Wuninitialized -pedantic -std=c++14 model/io.cpp

character.o: model/character.cpp model/character.h
		g++ -c -Wall -pedantic -std=c++14 model/character.cpp

model.o: model/model.cpp model/model.h
		g++ -c -Wall -Wuninitialized -pedantic -std=c++14 model/model.cpp




#Control

#control: command.o controller.o
#		g++ -o control command.o controller.o -g

command.o: controller/command.cpp controller/command.h
		g++ -c -Wall -pedantic -std=c++14 controller/command.cpp

controller.o: controller/controller.cpp controller/controller.h
		g++ -c -Wall -pedantic -std=c++14 controller/controller.cpp
		
#View

#viewer: display_manager.o  
#		g++ -o viewer display_manager.o -g 
		#-lboost_program_options 


display_manager.o: view/display_manager.cpp view/display_manager.h
		g++ -c -Wall -pedantic -std=c++14 view/display_manager.cpp



clean:
		rm -rf *.o modell *out.txt
