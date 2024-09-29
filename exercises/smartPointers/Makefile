all: problem1 problem2 problem3 problem4 problem5
solution: problem1.sol problem2.sol problem3.sol problem4.sol problem5.sol

clean:
	rm -f *o *so *~ problem? problem?.sol

% : %.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol : solution/%.sol.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<
