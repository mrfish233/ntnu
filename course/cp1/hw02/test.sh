make

for i in $(seq 1 5); do
	j=0
	for file in test/0$i/in/*.in; do
		if [ $j -lt 10 ]; then
			./hw020$i < $file  > test/0$i/out/0$j.out
		else
			./hw020$i < $file  > test/0$i/out/$j.out
		fi

		j=$((j+1))
	done

	echo "test0$i done"
done
