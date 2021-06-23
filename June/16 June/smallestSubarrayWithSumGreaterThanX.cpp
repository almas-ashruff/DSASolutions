#include <bits/stdc++.h>
using namespace std;

// Given an array of integers (A[])  and a number x, find the smallest subarray
//  with sum greater than the given value.

// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x5651/1#

// While right index is less than the length of the array -
//      while right index is less than length of the array and currentSum is not greater than the sum - 
//          add the value at right index to currentsum.
//          increment right pointer.
//      when currentSum is greater than the given sum and left index is less than right index - 
//          answer will be the minimum of current answer and the difference of indices.
//          currentsum will remove the value at left index as left index is incremented.



int sb(int arr[], int n, int x)
{
    int ans = n+1; // difference of left and right index
    int left=0, currentSum=0, right=0;
    // left stores the left index, right stores the right index
    while(right < n) {
        while(currentSum <= x && right < n) {
            currentSum += arr[right];
            right++;
        }
        while(currentSum > x && left < right) {
            ans = min(ans, right - left);
            currentSum -= arr[left];
            left++;
        }

    }
    return ans;
}