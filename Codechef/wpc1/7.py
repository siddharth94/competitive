# def egcd(a, b):
#   if a == 0:
#       return (b, 0, 1)
#   else:
#       g, y, x = egcd(b % a, a)
#       return (g, x - (b // a) * y, y)

# # def modinv(a, m):
# #     g, x, y = egcd(a, m)
# #     return x % m

# def modinv(a, p):
#   '''
#   The multiplicitive inverse of a in the integers modulo p.
#   Return b s.t.
#   a * b == 1 mod p
#   '''
  
#   for d in xrange(1, p):
#     r = (d * a) % p
#     if r == 1:
#       break
#   return d

def pow_mod(x, y):
  number = 1
  while y:
      if y & 1:
          number = number * x
      y >>= 1
      x = x * x
  return number

T = (int)(raw_input())
while T :
	T=T-1
	num = raw_input().split(" ")
	n = [int(x) for x in num]
	x=n[0]
	m=n[1]
	n=n[2]

	ans = (pow_mod(x,(m+1))-1)
	an = ans/(x-1)
	ank = an % n
	print ank