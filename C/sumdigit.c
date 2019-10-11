#include<stdio.h>
void main()
{ int num,sum,digit;
  sum=0;
  printf("enter the number\n");
  scanf("%d",&num);
  while(num!=0)
  { digit=num%10;
    sum=sum+digit;
    num=num/10;
  }
 printf("the sum of the number digit is%d\n",sum);
}

