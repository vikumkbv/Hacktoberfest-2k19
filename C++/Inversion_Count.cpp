//A program to calculate the inversion count of an array.
# include <iostream>
# include <set>

using namespace std;
/*
1. Create an empty Set in C++ STL (Note that a Set in C++ STL is
   implemented using Self-Balancing Binary Search Tree). And insert
   first element of array into the set.

2) Initialize inversion count as 0.

3) Iterate from 1 to n-1 and do following for every element in arr[i]
     a) Insert arr[i] into the set.
     b) Find the first element greater than arr[i] in set
        using upper_bound() defined Set STL.
     c) Find distance of above found element from last element in set
        and add this distance to inversion count.

4) Return inversion count.
*/
int inversionCount(int Arr[], int n)
{
    set <int> S;
    S.insert(Arr[0]);
    int Count = 0;
    for(int i = 1 ; i < n ; i++)
    {
        S.insert(Arr[i]);
        set <int> ::iterator it = S.upper_bound(Arr[i]);
        Count += distance(it, S.end());
    }
    return Count;
}

int main(void)
{
    int Arr[4] = {8, 4, 2, 1};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int Count = inversionCount(Arr, n);
    cout << "\nMinimum number of swaps required to sort the array : " << Count;
    return 0;
}
