all: condition_variable
solution: condition_variable.sol

clean:
	rm -f *o condition_variable *~ core condition_variable.sol

% : %.cpp
	${CXX} -g -std=c++17 -O0 -pthread -Wall -Wextra -L. -o $@ $<

condition_variable.sol : solution/condition_variable.sol.cpp
	${CXX} -g -std=c++17 -O0 -pthread -Wall -Wextra -L. -o $@ $<
