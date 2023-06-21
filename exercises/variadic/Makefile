all: variadic
solution: variadic.sol

clean:
	rm -f *o variadic *~ variadic.sol

variadic : variadic.cpp
	$(CXX) -std=c++20 -g -O0 -Wall -Wextra -o $@ $<

variadic.sol : solution/variadic.sol.cpp
	$(CXX) -std=c++20 -g -O0 -Wall -Wextra -o $@ $<
