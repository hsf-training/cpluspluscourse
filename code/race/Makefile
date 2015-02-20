all: test

clean:
	rm -f *o test *~ core

test : test.cpp
	${CXX} -g -std=c++11 -O0 -pthread -Wall -Wextra -L. -o $@ $<

