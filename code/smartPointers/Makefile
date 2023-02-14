all: smartPointers
solution: smartPointers.sol

clean:
	rm -f *o *so smartPointers *~ smartPointers.sol

% : %.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol : solution/%.sol.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<
