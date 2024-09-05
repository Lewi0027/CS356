# C++ Makefile for PA1

CXX = g++
CXXFLAGS = -Wall -std=c++17
OBJS = main.o block.o stream.o utility.o
EXEC = cipher

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^


main.o: main.cpp block.h stream.h utility.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

block.o: block.cpp block.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

stream.o: stream.cpp stream.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

utility.o: utility.cpp utility.h
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS) $(EXEC) cipher.exe

