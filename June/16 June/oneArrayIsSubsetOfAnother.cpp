#include <bits/stdc++.h>
using namespace std;

// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. 
// Task is to check whether a2[] is a subset of a1[] or not. 
// Both the arrays can be sorted or unsorted. It may be assumed that elements in both array are distinct.

// https://practice.geeksforgeeks.org/problems/array-subset-of-another-array2317/1#\

// READ IMP - https://www.geeksforgeeks.org/find-whether-an-array-is-subset-of-another-array-set-1/

string isSubset(int a1[], int a2[], int n, int m) {
    set<int> hashSet;
    for(int i = 0; i < n; i++) {
        hashSet.insert(a1[i]);
    }
    for(int i = 0; i < m; i++) {
        if(hashSet.find(a2[i]) == hashSet.end()) {
            return "No";
        }
    }
    return "Yes";
}