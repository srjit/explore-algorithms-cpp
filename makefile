CC=gcc
CXX=g++
RM=rm -f

SRCS=insertion.cc
OBJS=$(subst .cc,.o,$(SRCS))

all: tool

tool: $(OBJS)
    $(CXX) -o $(OBJS)

# tool.o: tool.cc support.hh

# support.o: support.hh support.cc

clean:
    $(RM) $(OBJS)

distclean: clean
    $(RM) tool
