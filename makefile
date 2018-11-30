SHELL=/bin/bash

.PHONY: dynamic static test clean
dynamic:
	pushd build/; make; popd

static:
	pushd build/; make libmagician.a; popd

test:
	pushd test/; make; ./test.out; popd > /dev/null

clean:
	rm -f libmagician.a
	pushd build/; make clean; popd
	pushd test/; make clean; popd
