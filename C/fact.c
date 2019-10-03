#include<stdio.h>
int main()
{
int t,n;
printf("Enter the number:");
scanf("%d",&n);
long long int fact=1,mod=1000000007;
for(i=1;i<n;i++)
fact=((fact%mod)*(i%mod))%mod;
printf("Factorial:%lld",fact);
return 0;
}
