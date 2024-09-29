PROGRAM_NAME=racing

all: $(PROGRAM_NAME)
solution: $(PROGRAM_NAME).sol1 $(PROGRAM_NAME).sol2


clean:
	rm -f *o $(PROGRAM_NAME) *~ core $(PROGRAM_NAME).sol?

$(PROGRAM_NAME) : $(PROGRAM_NAME).cpp
	${CXX} ${CXXFLAGS} -g -std=c++17 -O2 -pthread -Wall -Wextra -L. -o $@ $<

$(PROGRAM_NAME).sol1 : solution/$(PROGRAM_NAME).sol1.cpp
	${CXX} ${CXXFLAGS} -g -std=c++17 -O2 -pthread -Wall -Wextra -L. -o $@ $<

$(PROGRAM_NAME).sol2 : solution/$(PROGRAM_NAME).sol2.cpp
	${CXX} ${CXXFLAGS} -g -std=c++17 -O2 -pthread -Wall -Wextra -L. -o $@ $<
