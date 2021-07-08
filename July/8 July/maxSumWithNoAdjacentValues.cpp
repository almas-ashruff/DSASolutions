#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#
// https://www.algoexpert.io/questions/Max%20Subset%20Sum%20No%20Adjacent

int FindMaxSum(int arr[], int n)
{
    int maxSum[n];
    maxSum[0] = arr[0];
    maxSum[1] = max(arr[0], arr[1]);
    for(int i = 2; i < n; i++) {
        maxSum[i] = max(maxSum[i - 1], arr[i] + maxSum[i - 2]);
    }
    return maxSum[n - 1];
}