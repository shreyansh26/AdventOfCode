# Makefile for compiling 01_1.cpp and 01_2.cpp

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGETS = 05_1 05_2

all: $(TARGETS)

05_1: 05_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

05_2: 05_2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)