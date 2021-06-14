#include <bits/stdc++.h>
using namespace std;

// Given an array of positive and negative numbers. 
// Find if there is a subarray (of size at-least one) with 0 sum.

// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1

bool subArrayExists(int arr[], int n)
{
    unordered_set<int> sumMap;
    int sum = 0;
    for(int idx = 0; idx < n; idx++) {
        sum += arr[idx];
        if(sum == 0 || sumMap.find(sum) != sumMap.end()) {
            return true;
        }
        sumMap.insert(sum);
    }
    return false;
}
// map stores the sum till current index
// if sum == 0, or the sum is repeated, then a subarray with sum 0 shall exist
