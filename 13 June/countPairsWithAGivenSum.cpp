#include <bits/stdc++.h>
using namespace std;

// Given an array of N integers, and an integer K, 
// find the number of pairs of elements in the array 
// whose sum is equal to K.

// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1#

// Solution

int getPairsCount(int arr[], int n, int k) {
    unordered_map<int, int> numCount; 
    // Keeps a count of the values of the array.
    int count = 0;

    for(int i = 0; i < n; i++) {
        int val = arr[i];
        int secondNum = k - val;
    
        if(numCount.find(secondNum) == numCount.end()) {
        // if the second number is not in the array
           if(numCount.find(val) == numCount.end()) {
               numCount[val] = 1;
               // if the current num is not in the array.
           } else {
               numCount[val]++;
               // if the current num exists in the array.
           }
        } else {
            count += numCount[secondNum];
            numCount[val]++;
            // if the pair exists in the array.
        }
    }
    return count;
}