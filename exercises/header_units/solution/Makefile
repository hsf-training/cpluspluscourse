all: header_units

clean:
	rm -rf *.o header_units gcm.cache

algorithm numeric random vector:
	${CXX} -std=c++20 -fmodules-ts -x c++-system-header $@

Complex_header_unit: ../Complex.hpp
	${CXX} -std=c++20 -g -O0 -Wall -Wextra -fmodules-ts -x c++-header $<

main.o: main.cpp Complex_header_unit algorithm numeric random vector
	${CXX} -std=c++20 -fmodules-ts -g -O0 -Wall -Wextra -o $@ -c $<

header_units: main.o
	${CXX} -std=c++20 -fmodules-ts -g -O0 -Wall -Wextra -o $@ $^
