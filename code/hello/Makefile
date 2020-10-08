all: hello

clean:
	rm -f *o hello *~

hello : hello.cpp
	${CXX} -Wall -Wextra -L. -o $@ $<
