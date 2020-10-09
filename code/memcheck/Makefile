all: libpoly.so memleak
solution: libpolysol.so memleak.sol

clean:
	rm -f *o *so memleak *~ memleak.sol vgcore*

libpoly.so: Polygons.cpp Polygons.hpp
	$(CXX) -g -Wall -Wextra -shared -fPIC -o $@ $<

memleak : memleak.cpp libpoly.so
	$(CXX) -g -Wall -Wextra -o $@ $^

libpolysol.so: solution/Polygons.sol.cpp solution/Polygons.sol.hpp
	$(CXX) -g -Wall -Wextra -shared -fPIC -o $@ $<

memleak.sol : solution/memleak.sol.cpp libpolysol.so
	$(CXX) -g -Wall -Wextra -o $@ $^
