
for each in $(ls | grep "txt"); do
	mv $each $each.bak
	./go < $each.bak > $each
done
