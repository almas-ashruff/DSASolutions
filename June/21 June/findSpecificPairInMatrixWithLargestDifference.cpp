#include <bits/stdc++.h>
using namespace std;

// Given an n x n matrix mat[n][n] of integers, find the maximum value of mat(c, d) – mat(a, b) 
// over all choices of indexes such that both c > a and d > b.

// https://www.codingninjas.com/codestudio/problems/find-a-specific-pair-in-the-matrix_1115467?leftPanelTab=0
// https://www.geeksforgeeks.org/find-a-specific-pair-in-matrix/

// Solution 1 in o(n) time with o(n) space.

// The concept is called preprocessing a matrix. 
// You store the maximum value that you can get from indexes after the current index.
// To do this, you preprocess and store the max value in the last row and column.
// Then, you find the maximum difference that can exist for an index in the input matrix and the next values in the maxMatrix;
// You store that value in a variable, and you update the other indices of the max matrix



int findMaxValue(vector<vector<int>>& mat, int n) {
	int maxValue = INT_MIN; // stores maximum value
    int maxMatrix[n][n];
    maxMatrix[n-1][n-1] = mat[n-1][n-1];
    
    int maxV = maxMatrix[n-1][n-1];
    for(int j = n - 2; j >= 0; j--) { 
        // preprocess last row
        if(mat[n - 1][j] > maxV) {
            maxV = mat[n - 1][j];
        }
        maxMatrix[n - 1][j] = maxV;
    }
    
	maxV = maxMatrix[n-1][n-1];
    for(int i = n - 2; i >= 0; i--) {
        // preprocess last column
        if(mat[i][n - 1] > maxV) {
            maxV = mat[i][n - 1];
        } 
        maxMatrix[i][n - 1] = maxV;
    }
    
    // preprocess rest of the matrix from bottom
    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 2; j >= 0; j--) {
            maxValue = max(maxMatrix[i + 1][j + 1] - mat[i][j], maxValue);
            // Update maxValue
            maxMatrix[i][j] = max(mat[i][j], max(maxMatrix[i + 1][j], maxMatrix[i][j + 1]));
        }
    }
    return maxValue;
}