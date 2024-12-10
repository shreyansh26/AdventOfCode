CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGETS = 10_1 10_2

all: $(TARGETS)

10_1: 10_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

10_2: 10_2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)