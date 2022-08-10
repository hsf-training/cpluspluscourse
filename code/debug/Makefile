all: randomize
solution: randomize.sol

clean:
	rm -f *o randomize *~ randomize.sol core

randomize : randomize.cpp
	${CXX} -std=c++17 -g -O0 -L. -o $@ $<

randomize.sol : solution/randomize.sol.cpp
	${CXX} -std=c++17 -g -O0 -Wall -Wextra -L. -o $@ $<
