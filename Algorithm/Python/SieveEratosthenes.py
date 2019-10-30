from math import sqrt
def sieve_Of_Eratosthenes(n):
       primeArr=[1]*(n+1)
       primeArr[0]=0
       primeArr[1]=0
       for i in range(2,int(sqrt(n))+1):
              j=2
              if primeArr[i]==1:
                     while(i*j<=n):
                            primeArr[i*j]=0
                            j+=1
       return primeArr
from collections import deque
t=int(input())
for i in range(t):
       number=int(input())
       a=sieve_Of_Eratosthenes(number)
       array=deque()
       for i in range(2,number+1):
              if a[i]==1:
                     array.append(i)
       print(array)
