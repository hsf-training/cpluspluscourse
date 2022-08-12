all: fibocrunch
solution : fibocrunch.sol

clean:
	rm -f *o fibocrunch *~ fibocrunch.sol fibocrunch.nostl core callgrind.out.*

fibocrunch : fibocrunch.cpp
	${CXX} -std=c++17 -g -O0 -Wall -Wextra -L. -o $@ $<

fibocrunch.sol : solution/fibocrunch.sol.cpp
	${CXX} -std=c++17 -Wall -Wextra -L. -o $@ $<
