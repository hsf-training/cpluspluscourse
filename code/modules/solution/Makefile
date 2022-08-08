all: modules

clean:
	rm -rf *.o modules gcm.cache

Complex.o: Complex.cpp
	${CXX} -std=c++20 -fmodules-ts -g -O0 -Wall -Wextra -o $@ -c $<

main.o: main.cpp Complex.o
	${CXX} -std=c++20 -fmodules-ts -g -O0 -Wall -Wextra -o $@ -c $<

modules: main.o Complex.o
	${CXX} -std=c++20 -fmodules-ts -g -O0 -Wall -Wextra -o $@ $^
