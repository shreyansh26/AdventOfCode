# Makefile for compiling 01_1.cpp and 01_2.cpp

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGETS = 02_1 02_2

all: $(TARGETS)

02_1: 02_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

02_2: 02_2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)