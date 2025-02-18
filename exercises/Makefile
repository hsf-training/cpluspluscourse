TESTDIRS = asan callgrind condition_variable control cppcheck debug functions \
           header_units helgrind hello loopsRefsAuto memcheck modern_oo modules \
           move operators polymorphism python race smartPointers templates \
           valgrind virtual_inheritance
NOCOMPILETESTDIRS = basicTypes constness stl variadic

all:
	for dir in ${TESTDIRS}; do \
		cd $${dir}; \
		make $@; \
		cd ..; \
	done

solution clean:
	for dir in ${TESTDIRS} ${NOCOMPILETESTDIRS}; do \
		cd $${dir}; \
		make $@; \
		cd ..; \
	done

clobber: clean
