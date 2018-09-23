CC=gcc
CXX=g++
RM=rm

SRCS=src/insertion.cc src/mergesort.cpp

all: sorts

sorts: $(SRCS)
	mkdir -p bin
	g++ -o bin/insertion src/insertion.cc
	g++ -o bin/merge src/mergesort.cpp

clean:
	$(RM) -rf bin
