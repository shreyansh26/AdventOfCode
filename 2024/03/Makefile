# Makefile for compiling 01_1.cpp and 01_2.cpp

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGETS = 03_1 03_2 03_2_v2

all: $(TARGETS)

03_1: 03_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

03_2: 03_2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

03_2_v2: 03_2_v2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)