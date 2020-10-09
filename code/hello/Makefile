all: libhello.so hello
solution: all

clean:
	rm -f *o *so hello *~ callgrind.out.*

libhello.so: hello.cpp hello.hpp
	$(CXX) --std=c++17 -g -Wall -Wextra -shared -fPIC -o $@ $<

hello : main.cpp libhello.so
	$(CXX) --std=c++17 -g -Wall -Wextra -o $@ $^
