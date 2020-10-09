all: randomize.nostl randomize
solution: randomize.sol

clean:
	rm -f *o randomize *~ randomize.sol randomize.nostl

randomize : randomize.cpp
	${CXX} -g -O0 -Wall -Wextra -L. -o $@ $<

randomize.nostl : randomize.nostl.cpp
	${CXX} -g -O0 -Wall -Wextra -L. -o $@ $<

randomize.sol : solution/randomize.sol.cpp
	${CXX} -g -O0 -Wall -Wextra -I. -L. -o $@ $<
