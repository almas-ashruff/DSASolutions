#include <bits/stdc++.h>
using namespace std;


// Given an array nums[] of size n, construct a Product Array P (of same size n) such that 
// P[i] is equal to the product of all the elements of nums except nums[i].

// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1#
// https://www.algoexpert.io/questions/Array%20Of%20Products

vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
       
    vector<long long int> prod(n, 1);
    long long int leftProd = 1;
    long long int rightProd = 1;
    for(int i = 0; i < n; i++) {
        prod[i] = leftProd;
        leftProd *= arr[i];
    }
    
    for(int i = n - 1; i >= 0; i--) {
        prod[i] *= rightProd;
        rightProd *= arr[i];
    }
    
    return prod;
}