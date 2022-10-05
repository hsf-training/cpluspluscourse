all: variant
solution: variant.sol

clean:
	rm -f *o *so variant *~ variant.sol

% : %.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol : solution/%.sol.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<
