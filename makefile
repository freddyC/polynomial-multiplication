all: main.cpp tools.h
	g++ -std=c++11  main.cpp -03 -g -o poly-mult