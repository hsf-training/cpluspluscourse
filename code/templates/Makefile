all: test

clean:
	rm -f *o *so test *~ test.sol

test : test.cpp OrderedVector.hpp Complex.hpp
	$(CXX) -g -O0 -Wall -Wextra -o $@ $<

test.sol : test.sol.cpp OrderedVector.hpp Complex.hpp
	$(CXX) -g -O0 -Wall -Wextra -o $@ $<
