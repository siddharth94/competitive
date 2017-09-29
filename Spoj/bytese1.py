import Queue

q = Queue.Queue()

T = (int(raw_input()))

for __rep in xrange(0,T):
	m,n = (raw_input().split())
	m = int(m)
	n = int(n)
	mat = [[0 for x in xrange(105)] for x in xrange(105)]
	cost = [[999999999 for x in range(105)] for x in range(105)] 
	for i in xrange(0,m):
		temp = raw_input().split(' ')
		for j in xrange(0,n):
			mat[i][j] = (int)(temp[j])
	temp = raw_input().split(' ')
	xo = int(temp[0])
	yo = int(temp[1])
	t = int(temp[2])
	cost[0][0] = 0
	q.put((0,0))

	while not q.empty():
		x, y = q.get()

		if (x>=0 and cost[x-1][y] > cost[x][y] + mat[x][y]):
			cost[x-1][y] = cost[x][y] + mat[x][y]
			if (cost[x-1][y] <= t):
				q.put((x-1,y))
		if (x<m-1 and cost[x+1][y] > cost[x][y] + mat[x][y]):
			cost[x+1][y] = cost[x][y] + mat[x][y]
			if (cost[x+1][y] <= t):
				q.put((x+1,y))
		if (y<n-1 and cost[x][y+1] > cost[x][y] + mat[x][y]):
			cost[x][y+1] = cost[x][y] + mat[x][y]
			if (cost[x][y+1] <= t):
				q.put((x,y+1))
		if (y>=0 and cost[x][y-1] > cost[x][y] + mat[x][y]):
			cost[x][y-1] = cost[x][y] + mat[x][y]
			if (cost[x][y-1] <= t):
				q.put((x,y-1))

	if (t >= cost[xo-1][yo-1] + mat[xo-1][yo-1]):
		print "YES\n%d" % (t-(cost[xo-1][yo-1] + mat[xo-1][yo-1]))
	else :
		print"NO"
