def sum(n,mod):
	n3 = n**3
	n4 = n3*n
	n5 = n4*n
	a = 6*n5
	b = 15*n4
	c = 10*n3
	ans = (a+b+c-n)/30
	ans = ans
	return ans

T = (int)(raw_input())
while T :
	T = T-1
	n,mod = map(int,raw_input().split())
	# n = (int)(raw_input())
	# mod = (int)(raw_input())

	# k = sum(n,mod)
	# k = k%mod
	# print(k)
	# continue


	a = []
	sq = n**(0.5)
	i = 1
	w = 0
	prev = n
	a_prev = 0
	ans = 0
	while i<=sq :
		
		while (int)(n/i) == prev :
			i = i+1
		
		new_i = i-1
		s = sum(new_i,mod)
		a_curr = s - a_prev
		tmp = prev*a_curr
		ans = ans + tmp
		prev = (int)(n/i)
		a_prev = s
		if new_i == (int)(n/new_i) :
			break
		a.append ((int)(n/new_i))
		w = w+1

	w = w-1

	while w>=0 :
		new_i = a[w]
		w = w-1
		s = sum(new_i,mod)
		a_curr = s - a_prev
		tmp = prev*a_curr
		ans += tmp
		prev = n/i
		a_prev = s

	ans = ans % mod
	print (ans)