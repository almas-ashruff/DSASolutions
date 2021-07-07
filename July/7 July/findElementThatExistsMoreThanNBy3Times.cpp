#include <bits/stdc++.h>
using namespace std;

// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// https://leetcode.com/problems/majority-element-ii/
// https://www.youtube.com/watch?v=yDbkQd9t2ig

// Boyer-Moore voting algorithm
vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();
    int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
    
    for(int i = 0; i < n; i++) {
        if(nums[i] == num1) {
            count1++;
        } else if(nums[i] == num2) {
            count2++;
        } else if(count1 == 0) {
            num1 = nums[i];
            count1++;
        } else if(count2 == 0) {
            num2 = nums[i];
            count2++;
        } else {
            count1--;
            count2--;
        }
    }
    
    // check if both majority element are occuring more than n/3 times
    count1 = 0;
    count2 = 0;
    vector<int> ans;
    for(int num : nums) {
        if(num == num1) {
            count1++;
        } else if(num == num2) {
            count2++;
        }
    }
    
    if(count1 > n/3) {
        ans.push_back(num1);
    }
    
    if(count2 > n/3) {
        ans.push_back(num2);
    }
    
    return ans;  
}