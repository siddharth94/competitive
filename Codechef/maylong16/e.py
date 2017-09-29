a = [1,2];
x = set()

def sum(cur_sum, ele, depth):
	# print depth
	if cur_sum > 1000000001:
		return
	if depth == 5:
		if cur_sum < 1000000001:
			x.add(cur_sum)
		return

	for i in xrange(len(a)):
		sum(cur_sum + a[ele], i, depth+1)

for i in xrange(0,41):
	a.append(a[i] + a[i+1])

print a
for i in xrange(len(a)):
	sum(0,i,0)
# print sorted(x)
print len(x)
