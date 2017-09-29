T = int(raw_input())

while T>0:
	l = raw_input()

	l = raw_input()

	[num1, rest] = l.split(' + ')
	[num2, ans] = rest.split(' = ')
	
	if (not num1.isdigit()):
		num2 = int(num2)
		ans = int(ans)
		num1 = ans - num2
	elif (not num2.isdigit()):
		num1 = int(num1)
		ans = int(ans)
		num2 = ans - num1
	elif (not ans.isdigit()):
		num1 = int(num1)
		num2 = int(num2)
		ans = num1 + num2

	print num1,'+',num2,'=',ans 
	T = T-1

