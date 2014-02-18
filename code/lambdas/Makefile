all: test

clean:
	rm -f *o test *~ test.sol test.nostl

test : test.cpp
	${CXX} -g -std=c++11 -O0 -Wall -Wextra -L. -o $@ $<

test.sol : test.sol.cpp
	${CXX} -g -std=c++11 -O0 -Wall -Wextra -L. -o $@ $<
