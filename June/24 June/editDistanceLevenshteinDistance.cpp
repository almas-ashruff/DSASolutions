#include <bits/stdc++.h>
using namespace std;

// Given two strings str1 and str2. Find the minimum number of operations that need to be performed on str1 to convert it to str2. 
// The possible operations are:
// 1. Insert
// 2. Remove
// 3. Replace

// https://practice.geeksforgeeks.org/problems/edit-distance3702/1#
// https://www.algoexpert.io/questions/Levenshtein%20Distance

// SOLUTION USING DP

// USED IN AUTOCORRECT!!


// The edits DP array stores the number of edits required to change "substrings" from 0 to i and 0 to j.
// The first row and col stores i and j values as it is the number of changes required compared to an empty string.

int editDistance(string str1, string str2) {
    vector<vector<int>> edits(str2.size() + 1, vector<int>(str1.size() + 1, 0));
    for(int i = 0; i < str2.size() + 1; i++) {
        for(int j = 0; j < str1.size() + 1; j++) {
            edits[i][j] = j;
        }
        edits[i][0] = i;
    }
    // Initailization of the DP
    
    for(int i = 1; i < str2.size() + 1; i++) {
        for(int j = 1; j < str1.size() + 1; j++) {
            if(str2[i - 1] == str2[j - 1]) {
                // minus 1 is put here because we are one index ahead in the dp because of the presence of null string
                edits[i][j] = edits[i - 1][j - 1]; 
                // if both chars are equal, diagonally previous value is copied and pasted.
            } else {
                edits[i][j] = 1 + min(edits[i - 1][j - 1], min(edits[i - 1][j], edits[i][j - 1]));
                // if not equal, minimum of the three near values (top, left, diagonal) is taken, and one operation is done on that
            }
        }
    }
    return edits[str2.size()][str1.size()];
    // last value from the dp is returned.
}
