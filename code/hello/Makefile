all: hello
solution: all

clean:
	rm -f *o *so hello *~ callgrind.out.*

hello : main.cpp hello.cpp
	$(CXX) --std=c++17 -g -Wall -Wextra -o $@ $^
