# $Id$
# plain simple Makefile to build HW2

CXX = g++-4.8
LEX = flex
YACC = bison

CXXFLAGS = -W -Wall -Wextra -std=c++11 -g
LDFLAGS = 

HEADERS = driver.hpp parser.hpp scanner.hpp \
    FlexLexer.h stack.hh position.hh location.hh y.tab.h

all: HW2

# Generate scanner and parser

parser.cpp: parser.ypp
	$(YACC) -o parser.cpp --defines=parser.hpp parser.ypp

scanner.cpp: scanner.lpp
	$(LEX) -o scanner.cpp scanner.lpp

# Implicit rule to compile c++ files

%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Link executable

HW2: parser.o scanner.o driver.o
	$(CXX) $(LDFLAGS) -o $@ parser.o scanner.o driver.o

clean:
	rm -f HW2 *.o

extraclean: clean
	rm -f parser.cpp parser.hpp scanner.cpp
