#include <bits/stdc++.h>
using namespace std;

// Binary Search in a shifted / rotated sorted array.
// https://www.algoexpert.io/questions/Shifted%20Binary%20Search


int shiftedBinarySearch(vector<int> array, int target) {
  int left = 0, right = array.size() - 1;
	while(left <= right) {
		int mid = (left + right) / 2;
		int midNum = array[mid];
		int leftNum = array[left];
		int rightNum = array[right];
		
		if(target == midNum) {
			return mid;
		} else if(leftNum <= midNum) {
			if(target < midNum && target >= leftNum) {
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		} else {
			if(target > midNum && target <= rightNum) {
				left = mid + 1;
			} else{
				right = mid - 1;
			}
		}
	}
	return -1;
}
