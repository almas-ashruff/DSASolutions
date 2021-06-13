#include <bits/stdc++.h>
using namespace std;

// Given an array of integers. Find the Inversion Count in the array. 
// Inversion Count: For an array, inversion count indicates 
// how far (or close) the array is from being sorted. 
// If array is already sorted then the inversion count is 0. 
// If an array is sorted in the reverse order then the inversion count is the maximum. 
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// GFG - Medium if you know merge sort, otherwisw Hard

// https://www.youtube.com/watch?v=kQ1mJlwW-c0
// https://www.youtube.com/watch?v=jYww4YDOZEE

int helper(int *array, int start, int end);

int inversionCount(int array[], int n) {
    int start = 0, end = n - 1;
    return helper(array, start, end);
}

int helper(int *array, int start, int end) {
    if(start >= end) {
        return 0;
    }
    
    int mid = (start + end) / 2;
    int leftCount = helper(array, start, mid);
    int rightCount = helper(array, mid + 1, end);

    // temp is the temporary array to work on, for merging the two smaller arrays.
    int temp[end - start + 1];

    long i = start, j = mid + 1, count = 0, k = 0;

    // count stores the inversions of current merging of smaller arrays
    // k is the index pointer for the temporary array

    while(i <= mid && j <= end) {
        if(array[j] < array[i]) { // when inversion exists
            count += mid - i + 1; 
            // since the inversion will be for 
            // all elements greater than the current element in the array

            temp[k] = array[j];
            k++;
            j++;
        } else { // if no inversion
            temp[k] = array[i];
            k++;
            i++;
        }
    }
    // the two loops below are for when one side ends first
    // before the other side is finished

    while(i <= mid) { 
        temp[k] = array[i];
        k++; 
        i++;
    }
    while(j <= end) {
        temp[k] = array[j];
        k++;
        j++;
    }


    int t = 0;

    for(int idx = start; idx <= end; idx++) {
        array[idx] = temp[t];
        t++;
    }
    // putting the elements at their correct place in the sorted array

    return leftCount + rightCount + count;
    // leftCount and rightCOunt are getting returned from the smaller left and right arrays
    // from when their inversions were fixed. This is getting added to the inversion count of the current array.
}

