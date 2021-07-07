#include <bits/stdc++.h>
using namespace std;

// Find the minimum number of swaps required to sort the array in strictly increasing order.
// https://practice.geeksforgeeks.org/problems/minimum-swaps/1#

// IMPORTANT - Uses properties of Disjoint set and cycle detection algo
// Basically, there will be some cycles getting formed in the array of the numbers that can be 
// ... swaped within themselved to sort the array. 
// ... The sum of (sizes of these cycles - 1) is the required number of swaps.

// All these cycles are the disjoint sets. They will not have common numbers.

int minSwaps(vector<int>&nums) {
    unordered_map<int, int> correctPos;
    vector<int> sortedNums;
    int swapCount = 0;
    // create a map to store the correct position of all numbers

    for(int num : nums) {
        sortedNums.push_back(num);
    }

    sort(sortedNums.begin(), sortedNums.end());
    // create a sorted array to find the correct position of all numbers by sorting it

    for(int i = 0; i < nums.size(); i++) {
        correctPos[sortedNums[i]] = i;
    }
    // store the correct position in the map


    for(int i = 0; i < n; i++) {
        while(nums[i] != sortedNums[i]) {
            // while number is not at its correct sorted position, 
            // ... swap it with the number at its sorted position
            swap(nums[i], nums[sortedNums[nums[i]]]);
            swapCount++;
        }
    }
    return swapCount;
}