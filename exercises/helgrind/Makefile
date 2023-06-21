all: fiboMT
solution: fiboMT.sol

clean:
	rm -f *o fiboMT *~ fiboMT.sol core

fiboMT : fiboMT.cpp
	${CXX} -std=c++17 -g -O0 -Wall -Wextra -o $@ $<

fiboMT.sol : solution/fiboMT.sol.cpp
	${CXX} -std=c++17 -g -O0 -Wall -Wextra -o $@ $<
