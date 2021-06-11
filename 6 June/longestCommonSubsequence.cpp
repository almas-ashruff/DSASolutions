#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT HARD QUESTION
//Dynamic Programming


vector<char> longestCommonSubsequence(string str1, string str2){
    //using a char array instead of string in the solution. So, 3D array is declared.
    // The 0th rows and columns of the matrice is Null values;
    // We go from 0 to size plus one to accomodate the first row and column of null char.
    //adding columns
    //then filling those columns with empty string values.
    vector<vector<vector<char>>> lcs;
    for(int i = 0; i < str2.length() + 1; i++){
        lcs.push_back(vector<vector<char>>());

        for(int j = 0; j < str1.length() + 1; j++){
            lcs[i].push_back(vector<char>());
        }
    }

    // we are starting the solution at 1st index of the matrix as 0th is empty char.
    // We match the chars of the two strings. If it exists -
    // We take the largest subsequence till then from the top left diagonal position and
    // add the character there and save it in the array at its position.
    // Else -
    // We choose the largest subsequence till now from the left and top positions in the matrix corresponding to the current index and copy it to the current index
    // We return the final position of the matrix.
    for(int i = 1; i < str2.length() + 1; i++){
        for(int j = 1; j < str1.length() + 1; j++){
            if(str2[i - 1] == str1[j - 1]){
                vector<char> topLeftDiagonalStringCopy = lcs[i - 1][j - 1];
                topLeftDiagonalStringCopy.push_back(str2[i - 1]);
                lcs[i][j] = topLeftDiagonalStringCopy;
            } else {
                lcs[i][j] = lcs[i - 1][j].size() > lcs[i][j - 1].size() ? lcs[i - 1][j] : lcs[i][j - 1];
            }
        }
    }
    return lcs[str2.length()][str1.length()];
    
}