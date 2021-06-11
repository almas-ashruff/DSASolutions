#include <bits/stdc++.h>
using namespace std;

// Given an array arr of N integers. Find the contiguous sub-array with maximum sum.
// SOLUTION 1

// Kinda like D.P.
// Max for a given position = max of (previous sum + current value) 

// If a negative number is encountered, if the mod of negative number is bigger than
// the current sum so far before the negative number, then the subarray is reset. Else
// the subarray continues.

// Max so far in the array = max of (max so far + max for that position)
// Return max so far

int maxSubarraySum(int arr[], int n){
    int maxSoFar = arr[0];
    int maxEndingHere = arr[0];
    
    for(int idx = 1; idx < n; idx++) {
        maxEndingHere = max(arr[idx], maxEndingHere + arr[idx]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    return maxSoFar;
}