from math import cos,pi
n=int(input("enter n"))
m=int(input("enter m"))
a=1
k=1
while(a<=n/2):
    b=1
    while(b<=m/2):
        x=cos( (pi*a)/(n+1))**2
        y=cos( (pi*b)/(m+1))**2
        k= k*(4*(x+y))
        b=b+1
    a=a+1
print(int(k))
'''
enter n4
enter m7
781
'''