all: randomize
solution: randomize.sol

clean:
	rm -f *o randomize *~ randomize.sol

randomize : randomize.cpp
	${CXX} -g -std=c++11 -O0 -Wall -Wextra -L. -o $@ $<

randomize.sol : solution/randomize.sol.cpp
	${CXX} -g -std=c++11 -O0 -Wall -Wextra -L. -I. -o $@ $<
