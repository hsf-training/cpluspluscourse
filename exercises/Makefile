TESTDIRS = callgrind cppcheck header_units control hello modules move python smartPointers templates virtual_inheritance \
	   debug helgrind memcheck polymorphism race stl valgrind basicTypes
NOCOMPILETESTDIRS = constness

solution:
	for dir in ${TESTDIRS}; do \
		cd $${dir}; \
		make $@; \
		cd ..; \
	done

clean:
	for dir in ${TESTDIRS} ${NOCOMPILETESTDIRS}; do \
		cd $${dir}; \
		make clean; \
		cd ..; \
	done

clobber: clean
