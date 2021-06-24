#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT HARD QUESTION
// https://www.algoexpert.io/questions/Min%20Number%20Of%20Jumps

// SOLN. 1
// Min number of jumps to reach a place = min of current number of jumps 
// ... and number of jumps to reach from another another position

// O(n^2) time and O(n) space

int minNumberOfJumps(vector<int> array){
    vector<int> jumps(array.size(), INT_MAX);
    jumps[0] = 0;

    for(int i = 1; i < array.size(); i++){
        for(int j = 0; j < i; j++){
            if(array[j] > i - j){
                jumps[i] = min(jumps[j] + 1, jumps[i]));
            }
        }
    }
    return jumps[jumps.size() - 1];
}

//SOLN. 2
// find the max index that can be reached at every step.
// keep a count of jumps, and the steps that can be taken from an index.
// check max reach from an index at every step.
// decrease steps as you are going forward.
// when steps = 0, jump.
// add new value of step.
//return jump + 1

// O(n) time and O(1) space

int minNumberOfJumps(vector<int> array){
    if(array.size() == 1){
        return 0;
    }
    int jumps = 0; 
    int maxReach = array[0];
    int steps = array[0];

    for(int i = 1; i < array.size() - 1; i++){
        maxReach = max(maxReach, i + array[i]);
        steps--;
        if(steps == 0){
            jumps++;
            steps = maxReach - i;
        }
    }
    return jumps + 1;
}