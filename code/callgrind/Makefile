all: test

clean:
	rm -f *o test *~ test.sol test.nostl core callgrind.out.*

test : test.cpp
	${CXX} -g -O0 -Wall -Wextra -L. -o $@ $<
