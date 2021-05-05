CXX:=clang++
CXXFLAGS:= -std=c++17 -O3 -g -I include

.PHONY: all 01

all: 01

01: src/problem_01.cc
	$(CXX) $(CXXFLAGS) $^ -o $@


02: src/problem_02.cc
	$(CXX) $(CXXFLAGS) $^ -o $@
