all: basicTypes
solution: basicTypes.sol

clean:
	rm -f *o *so basicTypes *~ basicTypes.sol

% : %.cpp PrintHelper.h
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $<

%.sol : solution/%.sol.cpp PrintHelper.h
	$(CXX) -g -std=c++20 -Wall -Wextra -o $@ $< -I .
