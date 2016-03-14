all: test

clean:
	rm -f *o test *~ test.sol test.nostl core

test : test.cpp
	${CXX} -g -O0 -L. -o $@ $<

test.sol : test.sol.cpp
	${CXX} -g -O0 -Wall -Wextra -L. -o $@ $<
