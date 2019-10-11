#include<iostream>
using namespace std;
int binary_search(int a[],int lb,int ub,int ele)
{ int mid;
  if(lb<ub)
  { mid=(lb+ub)/2;
    if(a[mid]==ele)
    { return(mid+1);}
    else if(a[mid]<ele)
    { return binary_search(a,mid+1,ub,ele);
      }
    else
    { return binary_search(a,lb,mid-1,ele);
      }
   }
   else
   { return (-1);}
}
int main()
{ int i,n,k;
  cout<<"enter the size of array\n";
  cin>>n;
  int a[n];
  cout<<"enter the array elements\n";
  for(i=0;i<n;++i)
  { cin>>a[i];}
  cout<<"enter the element to be searched\n";
  cin>>k;
  int z=binary_search(a,0,n-1,k);
  cout<<z;
  return 0;
}
  
