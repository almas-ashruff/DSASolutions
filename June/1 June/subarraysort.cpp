#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT HARD QUESTION
// https://www.algoexpert.io/questions/Subarray%20Sort


// TO FIND THE NECESSARY RANGE, FIND THE MINIMUM AND MAXIMUM VALUES
// ... IN THE RANGE OF NUMBERS THAT ARE OUT OF ORDER.
// THE CORRECT POSITION OF THOSE TWO NUMBERS IS THE RANGE OF INDICES OUT OF ORDER.

bool isOutOfOrder(int idx, int num, vector<int> array);

vector<int> subarraySort(vector<int> array){
    int minOutOfOrder = INT_MAX;
    int maxOutOfOrder = INT_MIN;

    for(int i = 0; i < array.size(); i++){
        int num = array[i];

        if(isOutOfOrder(i, num, array)){
            minOutOfOrder = min(minOutOfOrder, num);
            maxOutOfOrder = max(maxOutOfOrder, num);
        }
    }

    if(minOutOfOrder == INT_MAX){
        return vector<int>{-1, -1};
    }

    int subarrayLeftIdx = 0, subarrayRightIdx = array.size() - 1;
    
    while(minOutOfOrder >= array[subarrayLeftIdx]){
        subarrayLeftIdx++;
    }
    while(maxOutOfOrder <= array[subarrayRightIdx]){
        subarrayRightIdx--;
    }

    return vector<int> {subarrayLeftIdx, subarraRightIdx};
}

bool isOutOfOrder(int idx, int num, vector<int> array){
    if(idx == 0){
        return num > array[idx + 1];
    }

    if(idx == array.size() - 1){
        return num < array[idx - 1];
    }

    return num < array[idx - 1] || num > array[idx + 1];
}