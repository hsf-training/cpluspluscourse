all: modules
solution: modules.sol

clean:
	rm -rf *.o modules gcm.cache

main.o: main.cpp Complex.hpp
	${CXX} -std=c++20 -fmodules-ts -g -O0 -Wall -Wextra -o $@ -c $<

modules : main.o
	${CXX} -std=c++20 -fmodules-ts -g -O0 -Wall -Wextra -o $@ $^

modules.sol:
	$(MAKE) -C solution modules
