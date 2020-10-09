all: trypoly
solution: trypoly.sol

clean:
	rm -f *o *so trypoly *~ trypoly.sol

libpoly.so: Polygons.cpp Polygons.hpp
	$(CXX) -g -Wall -Wextra -shared -fPIC -o $@ $<

trypoly : trypoly.cpp libpoly.so
	$(CXX) -g -Wall -Wextra -o $@ $^

trypoly.sol : solution/trypoly.sol.cpp libpoly.so
	$(CXX) -g -Wall -Wextra -I. -o $@ $^
