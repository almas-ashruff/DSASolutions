#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1#

// Minimize the Heights II 
// Given an array arr[] denoting heights of N towers and a positive integer K, 
// you have to modify the height of each tower either by 
// increasing or decreasing them by K only once. 
// After modifying, height should be a non-negative integer. 
// Find out what could be the possible minimum difference of the 
// height of shortest and longest towers after you have modified each tower.


// DIFFICULT AND IMPORTANT 

// HINT - https://free-style-coding.blogspot.com/2021/05/minimize-heights-ii-geeks-for-geeks.html

int getMinDiff(int arr[], int n, int k) {
    sort(arr, arr + n);
    int limit = 0;
    int result = arr[n - 1] - arr[0];

    for(int i = 0; i < n; i++) {
        if(arr[i] >= k) {
            limit = i;
            break;
        }
    }

    for(int partitionIdx = limit; partitionIdx < n; partitionIdx++) {

        int maxElement = arr[n - 1] - k;

        if(partitionIdx > 0) {
            maxElement = max(maxElement, arr[partitionIdx - 1] + k);
        }

        int minElement = min(arr[0] + k, arr[partitionIdx] - k);
        result = min(result, maxElement - minElement);

    }
    return result;
}

// Essentially, we need to find the index of partition at which - 
//      1. All number before partitionIdx are going to be incremented.
//      2. All number after partitionIdx are going to be decremented.

// Sort the numbers.
// Now, since all numbers need to be positive after the modification (+ or - k), the partitionIdx
// cannot lie between the numbers less than k. 
// Now, we start looking for that partition. So we loop.
// For the partition, the maximum value will be either - 
//      1. Last index value - k.
//      2. Or (Partition index - 1)th value + k.
// And the minimum value will either be -
//      1. 0th index value + k.
//      2. Or (partition index) value - k.

// These min and max values are the extreme values that we are looking for. 
// Finding the partition index for which the difference of these two extremes is the lowest gives the answer.
