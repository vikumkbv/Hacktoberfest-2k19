//https://www.hackerrank.com/challenges/arrays-introduction/submissions/code/125864233

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,i,j,temp;
    int arr[1000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    j=i-1;
    i=0;
    while(i<j)
    {
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
