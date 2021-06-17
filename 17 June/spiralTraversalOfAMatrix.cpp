#include <bits/stdc++.h>
using namespace std;

// Given a matrix of size r*c. Traverse the matrix in spiral form.

// https://www.algoexpert.io/questions/Spiral%20Traverse
// https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1


// Traverse with the help of startRow, endRow, startCol, endCol.
// Increment or decrement the above variables as needed after one circular traveral.
// Important - Check for the case where the startRow = endRow and startCol = endCol
//              ... make sure that it is not printed twice. Break conditions for that are given in the code.


vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
    vector<int> result;

    int startRow = 0, startCol = 0, endRow = r - 1, endCol = c - 1;

    while(startRow <= endRow && startCol <= endCol) {

        for(int col = startCol; col <= endCol; col++) {
            result.push_back(matrix[startRow][col]);
        }

        for(int row = startRow + 1; row <= endRow; row++) {
            result.push_back(matrix[row][endCol]);
        }

        for(int col = endCol - 1; col >= startCol; col--) {
            if(startRow == endRow) {
                break;
                // Note that row is checked while column is getting printed.
            }
            result.push_back(matrix[endRow][col]);
        }

        for(int row = endRow - 1; row > startRow; row--) {
            if(startCol == endCol) {
                break;
                // Note that col is checked while row is getting printed.
            } 
            result.push_back(matrix[row][startCol]);
        }

        startRow++; 
        endRow--;
        startCol++; 
        endCol--;

    }
    return result;
}
