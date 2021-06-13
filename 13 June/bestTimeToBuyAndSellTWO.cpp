#include <bits/stdc++.h>
using namespace std;


// The cost of stock on each day is given in an array A[] of size N. 
// Find all the days on which you buy and sell the stock so that 
// in between those days your profit is maximum.


// https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1#
vector<vector<int> > stockBuySell(vector<int> array, int n){
    vector<vector<int>> result;
    
    for(int i = 1; i < n; i++) {
        vector<int> currentTrade; 
        // Create array to store result.

        if(array[i - 1] < array[i]) {
            currentTrade.push_back(i - 1);
            // if local minima is found - last value less than current value,
            // push the local minima index (i - 1) in the result array 
            i++;
            // increment i to to move to next index.

            while(i < n) { 
                // check if end of array isn't reached

                if(array[i - 1] < array[i]) {
                    // while array keeps increasing, keep going
                    i++;
                } else {
                    break;
                    // when local maxima is found, break
                }
            } 
            currentTrade.push_back(i - 1);
            //push the local maxima value, i.e. i-1
            result.push_back(currentTrade);
            //push into result
        }
    }
    return result;
}