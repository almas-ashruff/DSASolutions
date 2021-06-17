#include <bits/stdc++.h>
using namespace std;

// Write an efficient algorithm that searches for a value in an m x n matrix. 
// This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// https://leetcode.com/problems/search-a-2d-matrix/
// https://www.algoexpert.io/questions/Search%20In%20Sorted%20Matrix


// Solution - 

// Start at the top right index - first row, last column.

// If value in the matrix is less than the target value
// ... all values to the left in the same row will definitely be smaller. So, move down.
// If value in the matrix is larger than the target, 
// ... all values below will definitely be larger, so move left.

// O(m + n) time and O(1) space

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int endRow = matrix.size();
    int col = matrix[0].size() - 1;
    int row = 0;
    
    while(col >= 0 && row < endRow) {
        if(matrix[row][col] < target) {
            row++;
        }  else if(matrix[row][col] > target) {
            col--;
        } else {
            return true;
        }
    }
    return false;
}