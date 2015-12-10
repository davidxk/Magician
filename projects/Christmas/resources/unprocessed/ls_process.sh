
for each in $(ls $1); do
	mv $each $each.bak
	./go < $each.bak > $each
done
