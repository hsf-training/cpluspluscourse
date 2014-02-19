all: test

clean:
	rm -f *o *so test *~ test.sol

libpoly.so: Polygons.cpp Polygons.hpp
	$(CXX) -g -Wall -Wextra -shared -fPIC -o $@ $<

test : test.cpp libpoly.so
	$(CXX) -g -Wall -Wextra -o $@ $^

test.sol : test.sol.cpp libpoly.so
	$(CXX) -g -Wall -Wextra -o $@ $^
