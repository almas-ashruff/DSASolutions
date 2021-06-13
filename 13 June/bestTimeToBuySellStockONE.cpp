#include <bits/stdc++.h>
using namespace std;

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and 
// choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. 
// If you cannot achieve any profit, return 0.

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/


// Solution 

// We have to keep track of the smallest value till current index.
// Calculate max profit till current value by finding the difference.


int maxProfit(vector<int>& prices) {
    int maxProfit = 0;
    int minValue = INT_MAX;
    
    for(int price : prices) {
        minValue = min(minValue, price);
        maxProfit = max(maxProfit, price - minValue);
    }
    return maxProfit;
}