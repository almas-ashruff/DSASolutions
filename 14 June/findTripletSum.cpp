#include <bits/stdc++.h>
using namespace std;

// Given an array arr of size n and an integer X. 
// Find if there's a triplet in the array which sums up to 
// the given integer X.

// https://www.algoexpert.io/questions/Three%20Number%20Sum
// https://practice.geeksforgeeks.org/problems/triplet-sum-in-array-1587115621/1

// Solution -
// Two pointer technique in a sor
rted array
bool find3Numbers(int array[], int n, int t)
{
    sort(array, array + n);
    for(int i = 0; i < n - 2; i++) {
        int low = i + 1;
        int high = n - 1;
        
        while(low < high) {
            int currentSum = array[i] + array[low] + array[high];
            if(currentSum == t) {
                return true;
            } else if(currentSum < t) {
                low++;
            } else {
                high--;
            }
        }
    }
    return false;
}