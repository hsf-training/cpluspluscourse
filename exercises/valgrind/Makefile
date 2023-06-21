all: debug
solution: debug.sol

clean:
	rm -f *o debug *~ debug.sol core

debug : debug.cpp
	${CXX} -std=c++17 -g -O0 -L. -o $@ $<

debug.sol : solution/debug.sol.cpp
	${CXX} -std=c++17 -g -O0 -Wall -Wextra -L. -o $@ $<
