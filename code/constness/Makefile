all: constplay

clean:
	rm -f *o constplay *~ constplay.sol

constplay : constplay.cpp
	${CXX} -Wall -Wextra -L. -o $@ $<
