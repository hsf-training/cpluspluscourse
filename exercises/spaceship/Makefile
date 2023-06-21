all: spaceship
solution: spaceship.sol

clean:
	rm -f *o *so spaceship *~ spaceship.sol

% : %.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol : solution/%.sol.cpp
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<
