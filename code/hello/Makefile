all: libhello.so hello

clean:
	rm -f *o *so hello *~

libhello.so: hello.cpp hello.hpp
	$(CXX) -g -Wall -Wextra -shared -fPIC -o $@ $<

hello : test.cpp libhello.so
	$(CXX) -g -Wall -Wextra -o $@ $^
