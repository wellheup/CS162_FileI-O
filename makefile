


CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += O3
#LDFLAGS = -lboost_date_time

OBJS = main.o isValidInput.o menuShell.o letterCounter.o

SRCS = isValidInput.cpp menuShell.cpp letterCounter.cpp main.cpp

HEADERS = isValidInput.hpp menuShell.hpp letterCounter.hpp

main: ${OBJS} ${HEADERS}
	${CXX}  ${OBJS} -o main

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
