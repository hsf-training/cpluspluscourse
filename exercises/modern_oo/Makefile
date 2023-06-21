all: particles
solution: particles.sol

clean:
	rm -f *o particles particles.sol *~ callgrind.out.*

particles: particles.cpp
	${CXX} -g -std=c++17 -Wall -Wextra -o $@ $<

particles.sol : solution/particles.sol.cpp
	${CXX} -g -std=c++17 -Wall -Wextra -o $@ $<
