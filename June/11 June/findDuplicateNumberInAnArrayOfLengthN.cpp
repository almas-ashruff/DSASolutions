#include <bits/stdc++.h>
using namespace std;


//  Find the Duplicate Number
// Given an array of integers nums containing n + 1 integers 
// where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums 
// and uses only constant extra space.

// LEETCODE MEDIUM 
// https://leetcode.com/problems/find-the-duplicate-number/
// https://www.youtube.com/watch?v=32Ll35mhWg0


// FLOYD'S TORTOISE HARE SOLUTION FOR CYCLE DETECTION IMPORTANT

// IDK WHY DO WHILE IS NECESSARY AND WHIE LEADS TO TLE.

int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = slow;
    
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast) ;
    
    fast = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
    
}