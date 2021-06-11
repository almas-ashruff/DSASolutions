#include <bits/stdc++.h>
using namespace std;


//SOLUTION 1
vector<int> reverseArray(vector<int> array){
    int startIdx = 0, endIdx = array.size() - 1;
    while(startIdx < endIdx){
        swap(array[startidx], array[endIdx]);
    }
    return array;
}

//SOLUTION 2 : RECURSIVE
vector<int> reverseArray(vector<int> array){
    reverseArrayHelper(array, 0, &array.size() - 1);
    return arrayy;
}

void reverseArrayHelper(vector<int> &array, int startIdx, int endIdx){
    if(startIdx >= endIdx){
        return;
    }
    swap(array[startIdx], array[endIdx]);
    reverseArrayHelper(array, startIdx + 1, endIdx - 1);
}
