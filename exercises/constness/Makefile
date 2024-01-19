all: constplay

clean:
	rm -f *o constplay *~ constplay.sol

constplay : constplay.cpp
	${CXX} -std=c++17 -Wall -Wextra -L. -o $@ $<
