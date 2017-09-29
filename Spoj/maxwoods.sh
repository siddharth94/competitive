count="0"
while [ 1 ]; do
	./gen >maxwoods1.in                    
	./maxwoods <maxwoods1.in >maxwoods1.out          
	./maxwoods_corr <maxwoods1.in >maxwoods1_corr.out
	diff maxwoods1.out maxwoods1_corr.out >maxwoods.diff
	i="$(cat maxwoods.diff)"
	if [ ${#i} -ne 0 ]; then
		echo $i
		echo ${#i}
		break
	else 
		echo "$count"
	fi
	count=$((count + 1))
done