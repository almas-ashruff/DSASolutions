#include <bits/stdc++.h>
using namespace std;

// Given a boolean 2D array of n x m dimensions where each row is sorted. 
// Find the 0-based index of the first row that has the maximum number of 1's.
// If no such row exists, return -1.
 
// https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1#
// https://www.youtube.com/watch?v=z092lX-nhik - Third Algo


int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    int ans=-1;  
    int i=0,j=m-1;
    while(i<=n-1 && j>=0) {
        while(arr[i][j]==1 && j>=0) {
            ans=i;
            j--;
        }
        i++;
    }
    return ans;
}