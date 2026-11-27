CXX=g++
CXXFLAGS=-std=c++20 -I..

test-%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $*
	./$* < $*.in

run-%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $*
	./$*
