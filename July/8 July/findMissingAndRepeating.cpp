#include <bits/stdc++.h>
using namespace std;

// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} 
// is missing and one number 'B' occurs twice in array. Find these two numbers.

// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#
// Read editorial

vector<int> findTwoElement(int *arr, int n) {
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(arr[abs(arr[i]) - 1] > 0) {
            arr[abs(arr[i]) - 1] = - arr[abs(arr[i]) - 1];
        } else {
            ans.push_back(abs(arr[i]));
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) {
            ans.push_back(i + 1);
        }
    }
    return ans;
}