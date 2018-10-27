CC=gcc
CXX=g++
RM=rm

SRCS=src/heapsort.cpp src/randomized_quicksort.cpp

all: sorts

sorts: $(SRCS)
	mkdir -p bin
	g++ -o bin/qsort src/randomized_quicksort.cpp
	g++ -o bin/heap src/heapsort.cpp

clean:
	$(RM) -rf bin
