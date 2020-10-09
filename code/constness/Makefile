all: constplay
solution: constplay.sol

clean:
	rm -f *o constplay *~ constplay.sol

constplay : constplay.cpp
	${CXX} -Wall -Wextra -L. -o $@ $<

constplay.sol : solution/constplay.sol.cpp
	${CXX} -Wall -Wextra -L. -o $@ $<
