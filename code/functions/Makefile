all: functions

clean:
	rm -f *o functions *~

%.o: %.cpp %.h
	${CXX} -std=c++17 -Wall -Wextra -c  -o $@ $<

functions : functions.cpp Structs.o
	${CXX} -std=c++17 -Wall -Wextra -o $@ $^

