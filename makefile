.PHONY: test lib clean
lib:
	pushd makeproject/; make; popd

test:
	pushd test/makeproject/makeunix/; make -f Makefile.mk; popd
	test/test.out

clean:
	rm -f libmagician.a
	pushd makeproject/; make clean; popd
