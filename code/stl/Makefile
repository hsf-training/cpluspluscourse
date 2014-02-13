all: test.nostl test

clean:
	rm -f *o test *~ test.sol test.nostl

test : test.cpp
	${CXX} -g -O0 -Wall -Wextra -L. -o $@ $<

test.nostl : test.nostl.cpp
	${CXX} -g -O0 -Wall -Wextra -L. -o $@ $<

test.sol : test.sol.cpp
	${CXX} -g -O0 -Wall -Wextra -L. -o $@ $<
