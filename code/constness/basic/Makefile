all: test

clean:
	rm -f *o test *~ test.sol

test : test.cpp
	${CXX} -Wall -Wextra -L. -o $@ $<

test.sol : test.sol.cpp
	${CXX} -Wall -Wextra -L. -o $@ $<
