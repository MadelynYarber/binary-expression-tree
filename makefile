CXX=g++
CXXFLAGS=-Wall -pedantic

proj4.x: proj4_driver.cpp bet.h bet.hpp
	$(CXX) $(CXXFLAGS) -o $@ proj4_driver.cpp

.SUFFIXES: .x

.PHONY : clean

clean:
	rm -f *.o *.x core.*

%.x : $.c
	$(CC) -o $@ $<

%.x : %.cpp
	$(CXX) -o $@ $<
