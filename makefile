
CXX = g++

CXXFLAGS = -std=c++0x

CXXFLAGS += -Wall

CXXFLAGS += -pedantic-errors

CXXFLAGS += -g

#CXXFLAGS += -O3

#LDFLAGS = -lboost_date_time



OBJS = main.o inputvalidation.o creature.o vampyre.o hero.o game.o daughterrooms.o item.o room.o

SRCS = main.cpp inputvalidation.cpp creature.cpp vampyre.cpp hero.cpp game.cpp daughterrooms.cpp item.cpp room.cpp

HEADERS = inputvalidation.hpp creature.hpp vampyre.hpp hero.hpp game.hpp daughterrooms.hpp item.hpp room.hpp



finalproject: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o finalproject


clean:
	rm *.o finalproject
