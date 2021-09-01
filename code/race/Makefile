all: racing
solution: racing.sol

clean:
	rm -f *o racing *~ core racing.sol

racing : racing.cpp
	${CXX} -g -std=c++11 -O0 -pthread -Wall -Wextra -L. -o $@ $<

racing.sol : solution/racing.sol.cpp
	${CXX} -g -std=c++11 -O0 -pthread -Wall -Wextra -L. -o $@ $<
