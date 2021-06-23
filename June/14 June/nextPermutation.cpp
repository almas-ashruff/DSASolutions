#include <bits/stdc++.h>
using namespace std;

// Implement next permutation, which rearranges numbers into 
// the lexicographically next greater permutation of numbers.
// If such an arrangement is not possible, it must rearrange it 
// as the lowest possible order (i.e., sorted in ascending order).


// https://leetcode.com/problems/next-permutation/
// https://www.youtube.com/watch?v=LuLCLgMElus

// Solution -
// 1. Traverse from the back, such that the value of index k is less than value of index k + 1.
// 2. Traverse from the back again, and find the index which has a bigger value 
//     than the value at index k we got from the above step. INDEX l.
// 3. Swap values at index k and index l.
// 4. Reverse the value from after index k till the end. This will SORT the array from after index k,
//     and will give the first permutation of the array after the given permutation.
void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int k, l;
    for(k = n - 2; k >= 0; k--) {
        if(nums[k] < nums[k + 1]) {
            break;
        }
    }
    
    if(k < 0) {
        reverse(nums.begin(), nums.end());
    } else {
        for(l = n - 1; l > k; l--) {
            if(nums[l] > nums[k]) {
                break;
            }
        } 
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}

