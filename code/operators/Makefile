all: operators
solution: operators.sol

clean:
	rm -f *o operators *~ operators.sol

operators : operators.cpp
	${CXX} -g -std=c++17 -O0 -Wall -Wextra -L. -o $@ $<

operators.sol : solution/operators.sol.cpp
	${CXX} -g -std=c++17 -O0 -Wall -Wextra -L. -o $@ $<
