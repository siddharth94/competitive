T = (int)(raw_input())
while T :
    T=T-1
    num = raw_input().split()
    n = [int(x) for x in num]
    x=n[0]
    m=n[1]
    n=n[2]
     
    ans = (x**(m+1))-1
    an = ans/(x-1)
    ank = an%n
    print ank 