def f(x):
	global s
	if x<=2:
		if x!=1:
			s+=str(x)
		print(s)
		return
	k=1
	power=0
	while k<=x:
		power+=1
		k = k<<1
	k = k>>1
	power-=1
	s+="2"
	if power!=1:
		s+="("
	f(power);
	x-=k;
	if x!=0:
		if power!=1:
			s+=")+"
			if x!=1:
				f(x);
			else:
				s+="2(0)"
		else:
			s+="+2(0)"
	elif power!=1:
		s+=")"

while 1:
	s=''
	try:
		x=int(input())
		s=str(x)+'='
		f(x)
	except:
		break;