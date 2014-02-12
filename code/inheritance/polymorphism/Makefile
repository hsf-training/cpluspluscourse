all: libpoly.so test

clean:
	rm -f *o *so test *~ test.sol

libpoly.so: Polygons.cpp
	$(CXX) -Wall -Wextra -shared -fPIC -o $@ $<

test : test.cpp libpoly.so
	$(CXX) -Wall -Wextra -L. -l poly -o $@ $<

test.sol : test.sol.cpp libpoly.so
	$(CXX) -Wall -Wextra -L. -l poly -o $@ $<
