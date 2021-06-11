#include <bits/stdc++.h>
using namespace std;



// Given an array of N integers arr[] where each element represents the 
// max number of steps that can be made forward from that element. 
// Find the minimum number of jumps to reach the end of the array 
// (starting from the first element). 
// If an element is 0, then you cannot move through that element.

// SOLN 1 - O(n) 


int minJumps(int arr[], int n){
    //maxReach: upcoming maximum index reachable.
    //k: maximum index reachable from current max jump.
    int k = arr[0];
    int jumps = 1; 
    int maxReach = 0;

    if (k == 0) {
        return -1;
    } // if first value is negative

    for (int i = 1; i < n; i++) {
    
        //calculating upcoming maximum idx reachable, if I jump from here.
        maxReach = max(maxReach, i + arr[i]);
    
        //No need to update on last index
        if (i == n-1) {
            break;
        } 
    
        //Current idx == maximum index reachable, update it with upcoming idx reachable.
        if (i == k) {
            k = maxReach;
        
            //After update, if maximum idx reachable is equal to current
            //then we can't go beyond this.
            if (k == i) {
                return -1;
            }
            jumps++;
        }
    
    }
    return jumps;
}
    


// Soln 2
// dynamic programming solution.
// store the minimum number of jumps required to reach index i. Keep updating.
// AlgoExpert
// Edge cases not handled



int minNumberOfJumps(vector<int> array){
    vector<int> jumps(array.size(), INT_MAX);
    jumps[0] = 0;

    for(int i = 1; i < array.size(); i++){
        for(int j = 0; j < i; j++){
            if(array[j] >= i - j){
                jumps[i] = min(jumps[j] + 1, jumps[i]);
            }
        }
    }
    return jumps[jumps.size() - 1];
}


// soln 3.
// simpler version of top solution, does not work for 0 in the array. 
// Edge cases not handled
// AlgoExpert

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