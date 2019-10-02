/*Program to find LCM of 2 numbers using function.*/

#include <stdio.h>
int temp=1;
int lcm(int m,int n)
{

    if (temp%m==0 && temp%n==0)
        return temp;

    temp=temp+1;
    lcm(m,n);
    return temp;




}
int main()
{
    int num1, num2;
    printf("Enter the two numbers separated by a space : ");
    scanf("%d %d",&num1,&num2);
    printf("LCM of %d and %d = %d\n",num1,num2,lcm(num1,num2));
}



