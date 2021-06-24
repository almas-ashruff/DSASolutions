#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT HARD QUESTION
// https://www.algoexpert.io/questions/Max%20Sum%20Increasing%20Subsequence

vector<vector<int>> buildSequence(vector<int> array, vector<int> sequences, int currentIdx, int sum);

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array){
    vector<int> sequences(array.size(), INT_MIN);
    // stores the index of the last value that got added to the current index for the max sum
    vector<int> sums = array;
    // stores the max sum of the subsequence for the current index
    int maxSumIdx = 0;

    for(int i = 0; i < array.size(); i++){
        int currentNum = array[i];
        for(int j = 0; j < i; j++){
            int otherNum = array[j];
            if(otherNum < currentNum && sums[j] + currentNum >= sums[i]){
                sums[i] = currentNum + sums[j];
                sequences[i] = j;
            }
        }
        if(sums[i] >= sums[maxSumIdx]){
            maxSumIdx = i;
        }
    }
    return buildSequence(array, sequences, maxSumIdx, sums[maxSumIdx]);
}

vector<vector<int>> buildSequence(vector<int> array, vector<int> sequences, int currentIdx, int sum){
    vector<vector<int>> sequence = {{}, {}};
    sequence[0].push_back(sum);
    while(currentIdx != INT_MIN){
        sequence[1].insert(sequence[1].begin(), array[currentIdx]);
        currentIdx = sequences[currentIdx];
    }
    return sequence;
}
