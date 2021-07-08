#include <bits/stdc++.h>
using namespace std;

// Given an array Arr[] of size L and a number N, you need to write a program to find if there exists 
// a pair of elements in the array whose difference is N.

// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1#

// Cant use low = 0 and high = size - 1, because Consider an array 20 50 70 80 90 and n=20
// Correct answer is true
// But a/c to your code, the initial difference between first and last element is always greater than 20. 
// So the value of r will become 0 and it will return false..

// So, start with low = 0 and high = 1;
bool findPair(int arr[], int size, int n){
    sort(arr, arr + size);
    
    int low = 0, high = 1;
    
    while(low <= high && high < size) {
        if(arr[high] - arr[low] < n){
            high++;
        } else if(arr[high] - arr[low] > n) {
            low++;
        } else {
            return true;
        }
    }
    return false;
}

