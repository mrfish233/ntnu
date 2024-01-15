make

if [ "$#" -ne 1 ]; then
	echo "error: requires 1 argument"
	echo "$0 <question>"
	exit 1
fi

if [ $1 -lt 10 ]; then
	q="0$1"
else
	q="$1"
fi

i=0
for test_in in test/${q}/in/*.in; do
	if [ $i -lt 10 ]; then
		j="0$i"
	else
		j="$i"
	fi

	test_out="test/${q}/out/${j}.out"
	out="test/${q}/out/hw04${q}_${j}.out"
	dif="test/${q}/out/${j}.out"

	if [ ! -e $test_out ]; then
		touch $test_out
	fi

	./hw04${q} < $test_in > $test_out

	if [ -e $out ]; then
		if diff "$test_out" "$out"; then
			echo "Test $i passed"
		else
			echo "Test $i failed"
			echo ""
		fi
	else
		echo "Test $i diff skipped"
	fi

	i=$(( i+1 ))
done

echo "test${q} done"
