#include <bits/stdc++.h>
using namespace std;

// Knapsack problem from algoexpert - Also return the list of items used

// https://www.algoexpert.io/questions/Knapsack%20Problem

// Solved using dynamic programming O(Number of items * Capacity) space and time

vector<vector<int>> knapsackProblem (vector<vector<int>> items, int capacity) {
    vector<vector<int>> knapsackValues(items.size() + 1, vector<int>(capacity + 1, 0));
    // stores the maximum value that can be held in the knapsack of capacity column, 
    // ... when you have values from the items array upto item index row - 1.
    // first row contains the value 0 as it represents the case when an items array of size 0 is given.

    
}