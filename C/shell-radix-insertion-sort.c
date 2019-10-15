#include<stdio.h>
//A simple, easy to understand code for shell, radix and insertion sort algorithms.
//Create your own methods for other algorithms and add them to the nice looking UI
void insertion() {
  int i,j,k,temp,n,a[100];
  printf("Size:  ");
  scanf("%d",&n);
  printf("Enter elements:\n");
  for(i=0;i<=n-1;i++)
    scanf("%d",&a[i]);
  for(i=1;i<=n-1;i++) {
    temp=a[i];
    for(j=i-1;j>=0 && a[j]>temp;j--)
      a[j+1]=a[j];
    a[j+1]=temp;
  }
  printf("Sorted numbers using Insertion Sort\n");
  for(i=0;i<=n-1;i++)
    printf("%d  ",a[i]);
}

void shell() {
  int i,j,step,temp,n,a[100];
  printf("Size: ");
  scanf("%d",&n);
  printf("Enter elements:\n");
  for(i=0;i<=n-1;i++)
    scanf("%d",&a[i]);
  for(step=n/2;step>0;step=step/2)
    for(i=step;i<n;i++) {
      temp=a[i];
      for(j=i;j>=step;j=j-step)
        if(temp<a[j-step])
          a[j]=a[j-step];
        else
          break;
      a[j]=temp;
    }
  printf("Sorted numbers using Shell Sort:\n");
  for(i=0;i<=n-1;i++)
    printf("%d  ",a[i]);
}

void radix() {
  int buckets[10][10],count[10],a[100],n;
  int passes,large,div,b_no,i,j,k;
  large=a[0];
  printf("Size: ");
  scanf("%d",&n);
  printf("Enter elements:\n");
  for(i=0;i<=n-1;i++)
    scanf("%d",&a[i]);
  for(i=1;i<n;i++)
    if(a[i]>large)
      large=a[i];
    passes=0;
  while(large>0) {
    passes++;
    large=large/10;
  }
  div=1;
  for(i=1;i<=passes;i++) {
    for(j=0;j<=9;j++)
      count[j]=0;
    for(j=0;j<n;j++){
      b_no=(a[j]/div)%10;
      buckets[b_no][count[b_no]]=a[j];
      count[b_no]++;
    }
    j=0;
    for(b_no=0;b_no<=9;b_no++)
      for(k=0;k<count[b_no];k++)
        a[j++]=buckets[b_no][k];
    div=div*10;
  }
  printf("Sorted numbers using Radix Sort:\n");
  for(i=0;i<=n-1;i++)
    printf("%d  ",a[i]);
}

int main() {
  int i,n,ch;
  while(ch!=4) {
    printf("\n1.SHELL SORT       2.RADIX SORT\n3.INSERTION SORT   4.EXIT\n");
    printf("Choice: ");
    scanf("%d",&ch);
    switch(ch) {
      case 1:shell();
             break;
      case 2:radix();
             break;
      case 3:insertion();
             break;
      case 4:break;
    }
  }
}
