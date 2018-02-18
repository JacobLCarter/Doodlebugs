CXX = g++
CXXFLAGS = -g
CXXFLAGS += -Wall
CXXFLAGS += -std=c++11

SRCES = board.cpp Critter.cpp Ant.cpp Doodlebug.cpp Game.cpp utils.cpp main.cpp
HDRS = board.hpp Critter.hpp Ant.hpp Doodlebug.hpp Game.hpp utils.hpp
OBJS = board.o Critter.o Ant.o Doodlebug.o Game.o utils.o main.o

predPrey: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o predPrey -ggdb

board.o: board.cpp board.hpp
	${CXX} ${CXXFLAGS} -c board.cpp

Critter.o: Critter.cpp Critter.hpp
	${CXX} ${CXXFLAGS} -c Critter.cpp

Ant.o: Ant.cpp Ant.hpp
	${CXX} ${CXXFLAGS} -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
	${CXX} ${CXXFLAGS} -c Doodlebug.cpp

Game.o: Game.cpp Game.hpp
	${CXX} ${CXXFLAGS} -c Game.cpp

utils.o: utils.cpp utils.hpp
	${CXX} ${CXXFLAGS} -c utils.cpp

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clean: 
	 rm *.o predPrey
