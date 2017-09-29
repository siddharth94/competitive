def pow_mod(x, y, z):
  number = 1
  while y:
      if y & 1:
          number = (number * x) % z
      y >>= 1
      x = (x * x) % z
  return number

def fu (x, m, n):
	if m==0 : 
		return 1
	elif m==1 :
		return (1+x)%n
	else :
		if (m&1) :
			return ((fu(x,m//2,n)) % n * (1+pow_mod(x,(m+1)/2,n))) % n
		else :
			return (pow_mod(x,m,n) + fu(x,m-1,n)) % n

T = (int)(raw_input())
while T :
	T=T-1
	num = raw_input().split(" ")
	n = [int(x) for x in num]
	x=n[0]
	m=n[1]
	n=n[2]

	print fu (x,m,n);

	# print ank