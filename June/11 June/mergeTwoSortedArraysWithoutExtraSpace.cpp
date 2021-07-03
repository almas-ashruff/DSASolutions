#include <bits/stdc++.h>
using namespace std;

// Given two sorted arrays arr1[] of size N and arr2[] of size M. 
// Each array is sorted in increasing order. 
// Merge the two arrays into one sorted array in increasing order 
// without using any extra space.

// GFG Medium 

// https://www.youtube.com/watch?v=59VkIo4Pk3Y


// SOLUTION 

// Since the arrays are sorted, we only need to swap values between the two arrays.
// Put one pointer1 at the end of array1  and pointer2 at the end of array2.
// if array1[ptr1] > array2[ptr2], swap the values.
// Decrease ptr1, increase ptr2.
// When above condition isn't true, break, as no more values will exist since the arrays were sorted.
// Sort both the new arrays.

void merge(int arr1[], int arr2[], int n, int m) {
    int i = n - 1;
    int j = 0;
    
    while(i >= 0 && j < m) {
        if(arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        } else {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}