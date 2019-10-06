#include<iostream>
using namespace std;

bool binSearch(int arr[], int ele, int start, int end) {
	if (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == ele)
			return true;
		else if (arr[mid] > ele) {
			return binSearch(arr, ele, start, mid - 1);
		} else {
			return binSearch(arr, ele, mid + 1, end);
		}
	}
	return false;
}

int main() {
	int arr[] = {1,2,3,4,5};
	int ele = 5;
	cout << binSearch(arr, ele, 0, 4);
}
