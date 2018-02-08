CXX = g++
CXXFLAGS = -g
CXXFLAGS += -Wall
CXXFLAGS += -std=c++11

SRCES = board.cpp critter.cpp ant.cpp critter.cpp instructor.cpp game.cpp\
		utils.cpp main.cpp
HDRS = board.hpp critter.hpp ant.hpp critter.hpp instructor.hpp game.hpp \
	   utils.hpp
OBJS = board.o critter.o ant.cpp critter.o instructor.o game.o utils.o main.o

predPrey: ${OBJS} 
	${CXX} ${CXXFLAGS} ${OBJS} -o predPrey -ggdb

board.o: board.cpp board.hpp
	${CXX} -c board.cpp

critter.o: critter.cpp critter.hpp
	${CXX} -c critter.cpp

ant.o: ant.cpp ant.hpp
	${CXX} -c ant.cpp

doodlebug.o: doodlebug.cpp doodlebug.hpp
	${CXX} -c doodlebug.cpp

game.o: game.cpp game.hpp
	${CXX} -c game.cpp

main.o: main.cpp
	g++ -c main.cpp

clean: 
	 rm *.o predPrey
