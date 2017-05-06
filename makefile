SHELL=/bin/bash

.PHONY: test lib clean
lib:
	pushd build/; make; popd

test:
	pushd test/; make; ./test.out; popd > /dev/null

clean:
	rm -f libmagician.a
	pushd build/; make clean; popd
	pushd test/; make clean; popd
