all: concepts
solution: concepts.sol

clean:
	rm -f *o *so concepts *~ concepts.sol

% : %.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol : solution/%.sol.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<
