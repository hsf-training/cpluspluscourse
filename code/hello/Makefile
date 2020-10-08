all: libhello.so hello

clean:
	rm -f *o *so hello *~

libhello.so: hello.cpp hello.hpp
	$(CXX) --std=c++17 -g -Wall -Wextra -shared -fPIC -o $@ $<

hello : test.cpp libhello.so
	$(CXX) --std=c++17 -g -Wall -Wextra -o $@ $^
