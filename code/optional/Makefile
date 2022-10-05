all: optional
solution: optional.sol

clean:
	rm -f *o *so optional *~ optional.sol

% : %.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol : solution/%.sol.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<
