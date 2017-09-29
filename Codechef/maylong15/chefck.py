N = (int)(raw_input())
A = [0 for i in xrange(1,10000)]
a = (int)(raw_input())
b = (int)(raw_input())
c = (int)(raw_input())
d = (int)(raw_input())
e = (int)(raw_input())
f = (int)(raw_input())
r = (int)(raw_input())
s = (int)(raw_input())
t = (int)(raw_input())
m = (int)(raw_input())
A[1] = (int)(raw_input())
for x in xrange( 2, N):
	if((t**x) % s  <= r):        # Here t^x signifies "t to the power of x"
		A[x] = (a*(A[x-1]**2) + b*A[x-1] + c) % m
	else:
		A[x] = (d*(A[x-1]**2) + e*A[x-1] + f) % m
for i in xrange(1,N):
	print A[i]