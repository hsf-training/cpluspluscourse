all: test

clean:
	rm -f *o test test.sol *~ callgrind.out.*

test : test.cpp NVector.hpp
	${CXX} -g -std=c++11 -O0 -Wall -Wextra -L. -o $@ $<

test.sol : test.sol.cpp NVector.sol.hpp
	${CXX} -g -std=c++11 -O0 -Wall -Wextra -L. -o $@ $<
