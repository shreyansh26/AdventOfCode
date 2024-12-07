CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGETS = 01_1 01_2

all: $(TARGETS)

01_1: 01_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

01_2: 01_2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)