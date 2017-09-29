def getKey(item):
	return item[0]

k = 1000
primes = []
divsum_prime = [(2,2,1)]
for i in xrange(2,1000):
	is_prime = True
	for j in xrange(2,i):
		if i%j is 0 :
			is_prime = False;
	if is_prime:
		primes.append(i)
print primes

for i in xrange(0, len(primes)):
	tmp = primes[i]**2
	power = 2
	while (tmp < 1000000):
		divsum_prime.append((tmp,primes[i], power))
		tmp *= primes[i]
		power += 1

divsum_prime = sorted(divsum_prime, key=getKey)

print [x[0] for x in divsum_prime]
print len(divsum_prime)