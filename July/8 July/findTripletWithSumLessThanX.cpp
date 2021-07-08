#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] of distinct integers of size N and a sum value X, 
// the task is to find count of triplets with the sum smaller than the given sum value X.
// https://practice.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1


long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr, arr + n);
    long long count = 0;
    for(int i = 0; i < n - 2; i++) {
        int low = i + 1;
        int high = n - 1;
        
        while(low < high) {
            int currentSum = arr[i] + arr[low] + arr[high];
            if(currentSum < sum) {
                count += (high - low); 
                // As all pairs with high less than current high will qualify
                low++;
                // check for next greater value of low now
            } else {
                high--;
                // as the value is greater, check for a lower high value
            }
        }
    }
    return count;
}
