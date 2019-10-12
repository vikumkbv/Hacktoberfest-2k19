n = int(input())
s = 0
while n!=1:
    if n%2 == 0:
        n = n/2
    else:
        n = n*3+1
    s =s +1
print(s)
