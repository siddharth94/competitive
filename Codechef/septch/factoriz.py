prime = []
sieve = []

def make_sieve():
	size = (10**5)
	for i in range(size):
		sieve.append(0)
	j=0
	for i in range(2,size):
		if sieve[i]!=0 :
			continue
		k=i
		p=i*k
		prime.append(i)
		j = j+1
		while p<size :
			sieve[p]=1
			if i&1 :
				k = k+2
			else :
				k=k+1
			p = i*k
	return j

T = (int)(raw_input())
num = make_sieve()
while T:
	T=T-1
	n = (int)(raw_input())

	if n<10**400 :
		factors = []
		fac = 0
		i = 0
		if n<(10**5)	:
			sq = (int)(n**(0.5))
		else :
			sq = (10**5)
		while (i<num and prime[i]<=sq) :
			while n%prime[i] == 0 :
				n = n/prime[i]
				fac = fac+1
				factors.append(prime[i])
			i = i+1
		if n!=1 :
			fac = fac+1
			factors.append(n)
	
	else:
		factors = []
		fac = 0
		i = 0
		sq = (10**5)
		while (i<1000 and prime[i]<=sq) :
			while n%prime[i] == 0 :
				n = n/prime[i]
				fac = fac+1
				factors.append(prime[i])
			i = i+1
			if fac>n*10**3:
				break
		if n!=1 :
			fac = fac+1
			factors.append(n)

	print fac
	for i in range(fac):
		print factors[i]