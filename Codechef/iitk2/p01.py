T = int(raw_input())
for i in xrange(1,T+1) :
	coins = 0
	n,k = (raw_input().split(' '))
	n = int(n)
	k = int(k)
	while (n>0) :
		l = (log(n)/log(k))
		po = pow(k,l)
		q = n/po
		coins = coins + q
		n = n - (q*po)
	print coins
