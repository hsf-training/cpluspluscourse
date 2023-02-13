all: trymove
solution: trymove.sol

clean:
	rm -f *o trymove trymove.sol *~ callgrind.out.*

trymove : trymove.cpp
	${CXX} -g -std=c++17 -O2 -Wall -Wextra -L. -o $@ $<

trymove.sol : solution/trymove.sol.cpp
	${CXX} -g -std=c++17 -O2 -Wall -Wextra -L. -o $@ $<
