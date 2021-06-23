#include <bits/stdc++.h>
using namespace std;

// Union and Intersection of two sorted arrays

// SOLUTION 1
// Use two index variables i and j, initial values i = 0, j = 0 
// If arr1[i] is smaller than arr2[j] then print arr1[i] and increment i. 
// If arr1[i] is greater than arr2[j] then print arr2[j] and increment j. 
// If both are same then print any of them and increment both i and j. 
// Print remaining elements of the larger array.


void union(vector<int> arrayOne, vector<int> arrayTwo){
    int idx1 = 0, idx2 = 0;
    vector<int> result;

    while(idx1 < arrayOne.size() || idx2 < arrayTwo.size()) {
        if(idx1 < arrayOne.size() && idx2 < arrayTwo.size()) {
            if(arrayOne[idx1] < arrayTwo[idx2]) {
                result.push_back(arrayOne[idx1]);
                idx1++;
            } else if(arrayTwo[idx2] < arrayOne[idx1]) {
                result.push_back(arrayTwo[idx2]);
                idx2++;
            } else if(arrayOne[idx1] == arrayTwo[idx2]) {
                result.push_back(arrayOne[idx1]);
                idx1++;
                idx2++;
            }
        } else {
            if(idx1 >= array1.size()) {
                while(idx2 < arrayTwo.size()) {
                    result.push_back(arrayTwo[idx2]);
                    idx2++;
                }
            } else if(idx2 >= arrayTwo.size()) {
                while(idx1 < arrayOne.size()) {
                    result.push_back(arrayOne[idx1]);
                    idx1++;
                }
            }
        }
    }
}

// Use two index variables i and j, initial values i = 0, j = 0 
// If arr1[i] is smaller than arr2[j] then increment i. 
// If arr1[i] is greater than arr2[j] then increment j. 
// If both are same then print any of them and increment both i and j.

void intersection(vector<int> arrayOne, vector<int> arrayTwo){
    int idx1 = 0, idx2 = 0;
    vector<int> result;

    while(idx1 < arrayOne.size() && idx2 < arrayTwo.size()) {
        if(arrayOne[idx1] < arrayTwo[idx2]) {
            idx1++;
        } else if(arrayTwo[idx2] < arrayOne[idx1]) {
            idx2++;
        } else if(arrayOne[idx1] == arrayTwo[idx2]) {
            result.push_back(arrayOne[idx1]);
            idx1++;
            idx2++;
        }
    } 
}