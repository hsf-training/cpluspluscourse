all: trymove
solution: trymove.sol

clean:
	rm -f *o trymove trymove.sol *~ callgrind.out.*

trymove : trymove.cpp NVector.hpp
	${CXX} -g -std=c++11 -O0 -Wall -Wextra -L. -o $@ $<

trymove.sol : solution/trymove.sol.cpp solution/NVector.sol.hpp
	${CXX} -g -std=c++11 -O0 -Wall -Wextra -L. -o $@ $<
