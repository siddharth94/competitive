import sys
def mul(po,s,e,m):
	if s==e:
		return po[s]
	else :
		mid = (s+e)/2
		s1 = mul(po,s,mid,m)
		s2 = mul(po,mid+1,e,m)
		return (s1*s2)%m

test = int(sys.stdin.readline())
cases = sys.stdin.readlines()
for i in cases:
	k = 0
	for x in i :
		if x == ' ':
			break
		else :
			k = k+1;
	m = int(i[0:k])
	s = i[k+1:]
	ex = s.split("*");
	l = len(ex)
	po = []
	for j in xrange(0,l):
		if (j>0 and ex[j-1] == '') or (j<l-1 and ex[j+1] == ''):
			continue;
		elif ex[j] != '' and ((j<l-1 and ex[j+1] != '') or j==l-1) and ((j>0 and ex[j-1] != '')or j==0):
			po.append(int(ex[j])%m)
		elif ex[j] == '':
			po.append((int(ex[j-1]) ** int(ex[j+1]))%m)
	ans = mul(po,0,len(po)-1,m)
	print ans
	