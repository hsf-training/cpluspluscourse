all: libhello.a hello

solution: all

clean:
	rm -f *.o *.a *.so hello *~ callgrind.out.*

hello.o: hello.cpp hello.hpp
	$(CXX) --std=c++17 -c -g -Wall -Wextra -o $@ $<

libhello.a: hello.o
	ar rcs $@ $<

hello : main.cpp libhello.a
	$(CXX) --std=c++17 -g -Wall -Wextra -o $@ $^
