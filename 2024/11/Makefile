CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
TARGETS = 11_1 11_2

all: $(TARGETS)

11_1: 11_1.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

11_2: 11_2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGETS)