all: fiboMT
solution: fiboMT.sol

clean:
	rm -f *o fiboMT *~ fiboMT.sol core

fiboMT : fiboMT.cpp
	${CXX} -g -O0 -Wall -Wextra -pthread -o $@ $<

fiboMT.sol : solution/fiboMT.sol.cpp
	${CXX} -g -O0 -Wall -Wextra -pthread -o $@ $<
