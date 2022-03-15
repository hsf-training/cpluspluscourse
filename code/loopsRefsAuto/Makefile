all: loopsRefsAuto
solution: loopsRefsAuto.sol

clean:
	rm -f *o *~ loopsRefsAuto loopsRefsAuto.sol

%.o: %.cpp %.h
	${CXX} -std=c++17 -Wall -Wextra -c  -o $@ $<

loopsRefsAuto : loopsRefsAuto.cpp
	${CXX} -std=c++17 -Wall -Wextra -o $@ $^

loopsRefsAuto.sol : solution/loopsRefsAuto.sol.cpp
	${CXX} -std=c++17 -Wall -Wextra -o $@ $^
