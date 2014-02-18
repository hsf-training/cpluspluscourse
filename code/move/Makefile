all: test

clean:
	rm -f *o test *~

test : test.cpp Complex.hpp NVector.hpp
	${CXX} -g -std=c++11 -O0 -Wall -Wextra -L. -o $@ $<
