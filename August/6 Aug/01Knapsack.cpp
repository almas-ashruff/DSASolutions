// You are given weights and values of N items, put these items in a 
// knapsack of capacity W to get the maximum total value in the knapsack. 
// Note that we have only one quantity of each item.
// In other words, given two integer arrays val[0..N-1] and wt[0..N-1] 
// which represent values and weights associated with N items respectively. 
// Also given an integer W which represents knapsack capacity, 
// find out the maximum value subset of val[] such that sum of the weights of 
// this subset is smaller than or equal to W. You cannot break an item, 
// either pick the complete item or don’t pick it (0-1 property).

// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// https://www.algoexpert.io/questions/Knapsack%20Problem
// https://www.youtube.com/watch?v=nLmhmB6NzcM

int knapSack(int w, int wt[], int val[], int n) 
{ 
   vector<vector<int>> values(n + 1, vector<int>(w + 1, 0));
   
   for(int i = 1; i < n + 1; i++) {
       for(int j = 1; j < w + 1; j++) {
           if(wt[i - 1] <= j) {
               values[i][j] = max(values[i - 1][j], values[i - 1][j - wt[i - 1]] + val[i - 1]);
           } else {
               values[i][j] = values[i - 1][j];
           }
       }
   }
   
   return values[n][w];
}