#include <bits/stdc++.h>
using namespace std;

// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
// https://leetcode.com/problems/rotate-image/
// https://www.youtube.com/watch?v=Y72QeX0Efxw

// Solution 1 - O(n) space and O(n) time
// Make another matrix of the same size.
// Store starting rows of the first matrix as the ending columns of the second matrix.

// Solution 2 - O(n) time and O(1) in-space solution


void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // transpose the matrix - row becomes columns and columns become rows
    // reverse each row.


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) { // confusion
            swap(matrix[i][j], matrix[j][i]); 
        }
    }
        
    for(int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }    
}