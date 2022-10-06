all: concepts
solution: solution1 solution2
solution1: concepts.sol1
solution2: concepts.sol2

clean:
	rm -f *o *so concepts *~ concepts.sol1 concepts.sol2

% : %.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol1 : solution/%.sol1.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol2 : solution/%.sol2.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<
