#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] of size N and an element k. 
// The task is to find all elements in array that appear more than n/k times.

// https://practice.geeksforgeeks.org/problems/count-element-occurences/1

// Solution -

// Store count of occurances in a hash map.
// Reiterate over the array. Increase the count. 
// Change the value of the iterated over value's count to -1.std

int countOccurence(int arr[], int n, int k) {
    unordered_map<int, int> numCount;
    int result = 0;
    for(int i = 0; i < n; i++) {
        numCount[arr[i]]++;
    }
    
    for(int i = 0; i < n; i++) {
        if(numCount[arr[i]] > n / k) {
            result++;
            numCount[arr[i]] = -1;
        }
    }
    return result;
}