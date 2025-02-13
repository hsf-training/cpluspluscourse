all: classes
solution: classes_sol

clean:
	rm -f *o classes *~ classes_sol

classes : classes.cpp
	${CXX} -g -std=c++17 -O0 -Wall -Wextra -L. -o $@ $<

classes_sol : solution/classes_sol.cpp
	${CXX} -g -std=c++17 -O0 -Wall -Wextra -L. -o $@ $<
