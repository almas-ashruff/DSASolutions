#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT HARD QUESTION
// Move right to left and put a value one greater than the previous value,
// when a value greater than the orevious value is found.
// Move left to right anf put the value which is maximum between
// current value at the index and the value of the (index + 1) plus 1 when the value is greater than the next value


int minRewards(vector<int> scores){
    vector<int> rewards = vector<int>(scores.size(), 1);

    for(int i = 1; i < scores.size(); i++){
        if(scores[i] > scores[i - 1]){
            rewards[i] = rewards[i - 1] + 1;
        }
    }

    for(int i = scores.size() - 2; i >= 0; i--){
        if(scores[i] > scores[i + 1]){
            rewards[i] = max(rewards[i], rewards[i + 1] + 1);
        }
    }

    int totalReward = 0;
    for(int reward : rewards){
        totalReward += reward;
    }

    return totalReward;
}