T = (int(raw_input()))

for __rep in xrange(0,T):
	p0,p1,q,n = (raw_input().split())
	p0 = int(p0)
	p1 = int(p1)
	q = int(q)
	n = int(n)

	ans = False

	if (n == 1) :
		if (p0%q == 0):
			print "YES"
		else:
			print "NO"

	else :
		num = p0*10 + p1

		for i in xrange(2,n):
			p = (4*p1 + p0)%q
			num = num*10 + p
			p0 = p1
			p1 = p

		# print num	

		if (num%q == 0) :
			print "YES"
		else:
			print "NO"
