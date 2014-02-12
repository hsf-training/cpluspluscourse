all: libpoly.so test

clean:
	rm *o *so test *~

libpoly.so: Polygons.cpp
	g++ -Wall -Wextra -shared -fPIC -o $@ $<

test : test.cpp
	g++ -Wall -Wextra -L. -l poly -o $@ $<

test.sol : test.sol.cpp
	g++ -Wall -Wextra -L. -l poly -o $@ $<
