all: randomize.nostl randomize
solution: randomize.sol

clean:
	rm -f *o randomize *~ randomize.sol randomize.nostl

randomize : randomize.cpp
	${CXX} -std=c++17 -g -O0 -Wall -Wextra -L. -o $@ $<

randomize.nostl : randomize.nostl.cpp
	${CXX} -std=c++17 -g -O0 -Wall -Wextra -L. -o $@ $<

randomize.sol : solution/randomize.sol.cpp
	${CXX} -std=c++17 -g -O0 -Wall -Wextra -I. -L. -o $@ $<
