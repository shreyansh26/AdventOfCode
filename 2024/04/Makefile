# Makefile for compiling 01_1.cpp and 01_2.cpp

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGETS = 04_1 04_2 04_1_v2

all: $(TARGETS)

04_1: 04_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

04_2: 04_2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

04_1_v2: 04_1_v2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)