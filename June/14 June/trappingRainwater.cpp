#include <bits/stdc++.h>
using namespace std;

// Given an array arr[] of N non-negative integers representing the height of blocks. 
// If width of each block is 1, compute how much water can be trapped between the blocks 
// during the rainy season. 

// Algoexpert Hard, GFG
// https://www.algoexpert.io/questions/Water%20Area
// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

// Solution -


int trappingWater(int arr[], int n) {
    vector<int> maxes(n, 0);
    int leftMax = 0, rightMax = 0;
    
    for(int i = 0; i < n; i++) {
        int height = arr[i];
        maxes[i] = leftMax;
        leftMax = max(leftMax, height);
    } 
    // storing the maximum height leftmost of the current index
    
    for(int i = n - 1; i >= 0; i--) {
        int height = arr[i];
        int minHeight = min(rightMax, maxes[i]);
        // checking if the rightmost height is less or if the leftmost height is less.
        // The less height will be the upper cap on water height

        if(height > minHeight) {
            maxes[i] = 0; 
            // if the current index's height is more than the left and right heights (local maxima)
            // 0 quantity of water can be stored.
        } else {
            maxes[i] = minHeight - height; 
            // the amount of water that can be stored at the current index
        }
        rightMax = max(rightMax, height);
        // updating right max if current index is higher
    }
    int total = 0;
    
    for(int i = 0; i < n; i++) {
        total += maxes[i];
    }
    // totalling the quantity of water
    return total;
}