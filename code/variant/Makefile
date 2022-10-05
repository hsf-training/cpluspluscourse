all: variant
solution: solution1 solution2
solution1: variant.sol1
solution2: variant.sol2

clean:
	rm -f *o *so variant *~ variant.sol

% : %.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol1 : solution/%.sol1.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol2 : solution/%.sol2.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<
