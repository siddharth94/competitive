# LL arr[10005][4];
# arr = [[0 for x in xrange(4)] for x in xrange(10005)] 
arr = [[1,1,1,1],[1,1,1,1]]
# y = [0,0,0,0]

boo = True;

j=1
# arr[1][0]=1;	
# arr[1][1]=1;	
# arr[1][2]=1;	
# arr[1][3]=1;	

t = raw_input()
T = (int)(t)
while T :
	T=T-1
	t=raw_input()
	n=(int)(t)
	while j<n :
		if boo :
			arr[1][0] = arr[0][1]
			arr[1][1] = arr[0][0] + arr[0][3]
			arr[1][2] = arr[0][1] + arr[0][3]
			arr[1][3] = arr[0][2]
			boo = False
		else :
			arr[0][0] = arr[1][1]
			arr[0][1] = arr[1][0] + arr[1][3]
			arr[0][2] = arr[1][1] + arr[1][3]
			arr[0][3] = arr[1][2]
			boo = True
		j=j+1
	if boo :
		print(arr[0][0]+arr[0][1]+arr[0][2]+arr[0][3])
	else :
		print(arr[1][0]+arr[1][1]+arr[1][2]+arr[1][3])