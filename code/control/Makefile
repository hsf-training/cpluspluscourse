
all: control
solution: control.sol

clean:
	rm -f *o *~ control control.sol

control : control.cpp
	$(CXX) --std=c++17 -g -Wall -Wextra -o $@ $^

control.sol: solution/control.sol.cpp
	$(CXX) --std=c++17 -g -Wall -Wextra -o $@ $^
