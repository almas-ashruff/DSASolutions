#include <bits/stdc++.h>
using namespace std;

// There is an integer array nums sorted in ascending order (with distinct values).
// Prior to being passed to your function, nums is rotated at an unknown pivot index. 
// Given the array nums after the rotation and an integer target.
// Return the index of target if it is in nums, or -1 if it is not in nums.

// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://www.youtube.com/watch?v=QdVrY3stDD4

int search(vector<int>& nums, int target) {
    if(!nums.size()){
        return -1;
    }
       
     
    int left = 0, right = nums.size() - 1;
    
    while(left < right) {
        int mid = left + ((right - left) / 2);
        
        if(nums[mid] > nums[right]) { // abnormal for a sorted array
            left = mid + 1;             
        } else { // if left is <= right -> normal
            right = mid;
        }
    }
    // left is the index of the smallest value.
    
    int start = left;
    left = 0;
    right = nums.size() - 1;
    
    // find that side of the smallest element does the target lie
    if(target >= nums[start] && target <= nums[right]) {
        left = start;
    } else { // if target is on the left side of the smallest element
        right = start - 1;
    }
    
    // binary search in that scope
    while(left <= right) {
        int mid = left + ((right - left) / 2);
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target){
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }  
    return -1;
}