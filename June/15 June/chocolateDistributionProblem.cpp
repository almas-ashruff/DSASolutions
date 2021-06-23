#include <bits/stdc++.h>
using namespace std;

// Given an array A[ ] of positive integers of size N, where each value
//  represents the number of chocolates in a packet. 
// Each packet can have a variable number of chocolates. 
// There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student 
// and minimum number of chocolates given to a student is minimum.

// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1#

long long findMinDiff(vector<long long> a, long long n, long long m){
    long long minDifference = INT_MAX;
    sort(a.begin(), a.end());
    for(int i = 0; i + m - 1 < n; i++) {
        minDifference = min(minDifference, a[i + m - 1] - a[i]);
    }
    return minDifference;
}   

// Sort the array.
// Find the min difference between the max and min of the range in the array, 
// where the range = number of students