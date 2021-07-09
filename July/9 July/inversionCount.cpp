// Given an array of integers. Find the Inversion Count in the array. 
// Inversion Count: For an array, inversion count indicates how far (or close) 
// the array is from being sorted. If array is already sorted then the inversion count is 0. 
// If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
// https://www.algoexpert.io/questions/Count%20Inversions

// Modified Merge Sort

#include <vector>
using namespace std;

int countInversions(vector<int> array) {
  return countSubArrayInversions(array, 0, array.size());
}

// Recursive function
int countSubArrayInversions(vector<int> &array, int start, int end) {
	if(end - start <= 1) {
		return 0;
        // when one element exists -> 0 inversions
	}
	int middle = start + ((end - start) / 2);
	
	int leftInversions = countSubArrayInversions(array, start, middle);
	int rightInversions = countSubArrayInversions(array, middle, end);
	int mergedArrayInversions = mergeSortAndCountInversions(array, start, middle, end);
	// sum number of inversions in the left half, right half, and the joining of the current two halves
    // this sum is the answer

	return leftInversions + rightInversions + mergedArrayInversions;
}

int mergeSortAndCountInversions(vector<int> &array, int start, int middle, int end) {
	vector<int> sortedArray;
	int left = start;
	int right = middle;
	int inversionCount = 0;
    
    // merging the two halves of the array
	while(left < middle && right < end) {
		if(array[left] <= array[right]) {
        // if no inversion exists
			sortedArray.push_back(array[left]);
			left++;
		} else {
        // if inversion is detected while joining
			inversionCount += middle - left; 
            // important -> since inversion will exist for all elements smaller than the right idx, 
            // .. as all elements to the left are supposed to be smaller

			sortedArray.push_back(array[right]);
            // push the element in the right place
			right++;
		}
	}
	
	for(int idx = left; idx < middle; idx++) {
        // for remaining left indices
		sortedArray.push_back(array[idx]);
	}
	
	for(int idx = right; idx < end; idx++) {
        // for remaining right indices
		sortedArray.push_back(array[idx]);
	}
	
	for(int idx = 0; idx < sortedArray.size(); idx++) {
        // putting the sorted elements "IN PLACE" in the original array
        // important
		int num = sortedArray[idx];
		array[start + idx] = num;
	}
	
    // return the inversion count
	return inversionCount;
}
