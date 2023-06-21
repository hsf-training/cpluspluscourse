
all: functions
solution: functions.sol

clean:
	rm -f *o *~ functions functions.sol

%.o: %.cpp %.h
	${CXX} -std=c++17 -Wall -Wextra -c  -o $@ $<

functions : functions.cpp Structs.o
	${CXX} -std=c++17 -Wall -Wextra -o $@ $^

functions.sol : solution/functions.sol.cpp Structs.o
	${CXX} -I. -std=c++17 -Wall -Wextra -o $@ $^
