#include <bits/stdc++.h>
using namespace std;

// Implement next permutation, which rearranges numbers into 
// the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange it 
// as the lowest possible order (i.e., sorted in ascending order).


//https://practice.geeksforgeeks.org/problems/next-permutation5226/1
// https://www.youtube.com/watch?v=LuLCLgMElus

// Solution -
// 1. Traverse from the back, break where the value of index k is less than value of index k + 1.
// 2. Traverse from the back again, and find the index which has a bigger value 
//     than the value at index k we got from the above step. INDEX l.
// 3. Swap values at index k and index l.
// 4. Reverse the value from after index k till the end. This will SORT the array from after index k,
//     and will give the first permutation of the array after the given permutation.

vector<int> nextPermutation(int n, vector<int> arr){
    int k, l;
    
    for(k = n - 2; k >= 0; k--) {
        if(arr[k] < arr[k + 1] ) {
            break;
        }
    }
    
    if(k < 0) {
        reverse(arr.begin(), arr.end());
    } else {
        for(l = n - 1; l > k; l--) {
            if(arr[l] > arr[k]) {
                break;
            }
        }
        swap(arr[l], arr[k]);
        reverse(arr.begin() + k + 1, arr.end());
    }
    return arr;
}