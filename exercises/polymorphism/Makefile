all: trypoly
solution: trypoly.sol

clean:
	rm -f *o *so trypoly *~ trypoly.sol

libpoly.so: Polygons.cpp Polygons.hpp
	$(CXX) -std=c++11 -Wsuggest-override -g -Wall -Wextra -shared -fPIC -o $@ $<

trypoly : trypoly.cpp libpoly.so
	$(CXX) -std=c++11 -Wsuggest-override -g -Wall -Wextra -o $@ $^

trypoly.sol : solution/trypoly.sol.cpp libpoly.so
	$(CXX) -std=c++11 -g -Wall -Wextra -I. -o $@ $^
