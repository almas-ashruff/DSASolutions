#include <bits/stdc++.h>
using namespace std;

// Knapsack problem from algoexpert - Also return the list of items used

// https://www.algoexpert.io/questions/Knapsack%20Problem

// Solved using dynamic programming O(Number of items * Capacity) space and time


vector<vector<int>> getKnapsackItems(vector<vector<int>> knapsackValues, vector<vector<int>> items, int weight);
vector<vector<int>> knapsackProblem (vector<vector<int>> items, int capacity) {
    vector<vector<int>> knapsackValues(items.size() + 1, vector<int>(capacity + 1, 0));
    // stores the maximum value that can be held in the knapsack of capacity column, 
    // ... when you have values from the items array upto item index row - 1.
    // first row contains the value 0 as it represents the case when an items array of size 0 is given.

    
    for(int i = 1; i < items.size() + 1; i++) {
        int currentValue = items[i - 1][0];
        int currentWeight = items[i - 1][1];

        for(int c = 0; c < capacity + 1; c++) {
            if(currentWeight > c) {
                knapsackValues[i][c] = knapsackValues[i - 1][c];
            } else {
                knapsackValues[i][c] = max(knapsackValues[i - 1][c], knapsackValues[i - 1][c - currentWeight] + currentValue);
            }
        }
    }
	 // return currentValues[items.size()[capacity]; -> if you just wanna return the capacity

    return getKnapsackItems(knapsackValues, items, knapsackValues[items.size()][capacity]);
    
}

vector<vector<int>> getKnapsackItems(vector<vector<int>> knapsackValues, vector<vector<int>> items, int weight) {
    vector<vector<int>> solution = {{}, {}};

    int i = knapsackValues.size() - 1;
    int c = knapsackValues[0].size() - 1;

    while( i > 0) {
    	if(knapsackValues[i][c] == knapsackValues[i - 1][c]) {
            i--; // current item is not included;
        } else {
        	solution[1].insert(solution[1].begin(), i - 1);

            c = c - items[i - 1][1];
            i--;
        }

            if(c == 0) {
                break;
            }
        }
    solution[0].push_back(weight);

    return solution; 
}