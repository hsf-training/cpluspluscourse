all: header_units
solution: header_units.sol

clean:
	rm -rf *.o header_units gcm.cache solution/header_units solution/*.o solution/gcm.cache

main.o: main.cpp Complex.hpp
	${CXX} -std=c++20 -fmodules-ts -g -O0 -Wall -Wextra -o $@ -c $<

header_units : main.o
	${CXX} -std=c++20 -fmodules-ts -g -O0 -Wall -Wextra -o $@ $^

header_units.sol:
	$(MAKE) -C solution header_units
