all: operators
solution: operators_sol

clean:
	rm -f *o operators *~ operators_sol

operators : operators.cpp
	${CXX} -g -std=c++20 -O0 -Wall -Wextra -L. -o $@ $<

operators_sol : solution/operators_sol.cpp
	${CXX} -g -std=c++20 -O0 -Wall -Wextra -L. -o $@ $<
