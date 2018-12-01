SHELL=/bin/bash

.PHONY: dynamic static test clean
dynamic:
	pushd build/; make -j; popd

static:
	pushd build/; make -j libmagician.a; popd

test:
	pushd test/; make -j; ./test.out; popd > /dev/null

clean:
	rm -f libmagician.a
	pushd build/; make clean; popd
	pushd test/; make clean; popd
