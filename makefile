CXX = g++
CXXFLAGS = -g
CXXFLAGS += -Wall
CXXFLAGS += -std=c++11

SRCES = board.cpp Critter.cpp Ant.cpp Doodlebug.cpp Game.cpp utils.cpp main.cpp
HDRS = board.hpp Critter.hpp Ant.hpp Doodlebug.hpp game.hpp utils.hpp
OBJS = board.o Critter.o Ant.o Doodlebug.o Game.o utils.o main.o

predPrey: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o predPrey -ggdb

board.o: board.cpp board.hpp
	${CXX} -c board.cpp

Critter.o: Critter.cpp Critter.hpp
	${CXX} -c Critter.cpp

Ant.o: Ant.cpp Ant.hpp
	${CXX} -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
	${CXX} -c Doodlebug.cpp

Game.o: Game.cpp Game.hpp
	${CXX} -c Game.cpp

utils.o: utils.cpp utils.hpp
	${CXX} -c utils.cpp

main.o: main.cpp
	${CXX} -c main.cpp

clean: 
	 rm *.o predPrey
