import random

print 100
for i in range(25):
	x = random.randint(2,10**18)
	print x
for i in range(50):
	x = random.randint(2,10**1000)
	print x
for i in range(25):
	num = 1
	i = 0
	turn = random.randint(1,500)
	while i<turn and num < 10**1000 :
		x = random.randint(1,10**18)
		num = num*x
		i = i+1
	print num