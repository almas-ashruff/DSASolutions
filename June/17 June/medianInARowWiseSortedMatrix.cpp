#include <bits/stdc++.h>
using namespace std;


// Given a row wise sorted matrix of size RxC where R and C are always odd, 
// find the median of the matrix.

// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
// https://www.youtube.com/watch?v=63fPPOdIr2c

// GFG Hard 

int countSmallerThanEqualToMid(vector<int> &row, int mid) {
    int low = 0, high = row.size() - 1;
    while(low <= high) {
        int md = (low + high) / 2;
        if(row[md] <= mid) {
            low = md + 1;
        } else {
            high = md - 1;
        }
    }
    return low;
}
int median(vector<vector<int>> &matrix, int r, int c){
    int low = 0, high = 1e9;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        int count = 0;
        for(int i = 0; i < r; i++) {
            count += countSmallerThanEqualToMid(matrix[i], mid);
        }
        
        if(count <= (r * c) / 2) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}