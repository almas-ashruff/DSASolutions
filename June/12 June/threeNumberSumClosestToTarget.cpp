#include <bits/stdc++.h>
using namespace std;

// Given an array nums of n integers and an integer target, 
// find three integers in nums such that the sum is closest to target. 
// Return the sum of the three integers. 

// https://leetcode.com/problems/3sum-closest/
// Solution 1

// Sort the array
// Iterate the array from 0 to n - 2
// Use two pointer technique. Find sum using low and high pointers.
// If sum is less than target sum, increment low.
// If sum is more than target sum, decrement hight.
// If the difference is smaller than current difference, update currentSum.


int threeSumClosest(vector<int>& nums, int target) {
        int currentSum;
        int closestSum = 9999;
        
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < nums.size() - 2; i++) {
            int low = i + 1, high = nums.size() - 1;
            
            while(low < high) {
                currentSum =  nums[i] + nums[low] + nums[high];
                
                if(abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }
                if(currentSum < target) {
                    low++;
                } else if (currentSum > target) {
                    high--;
                } else {
                    break;
                }
                
            }
        }
        return closestSum;
    }