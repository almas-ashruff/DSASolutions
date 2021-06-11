#include <bits/stdc++.h>
using namespace std;

// Put all negative numbers to one side of the array
// SOLUTION 1

void rearrange(vector<int> array) {
    int frontIdx = 0;
    int i = array.size() - 1;
    while(i > frontIdx){
        if(array[i] < 0) {
            swap(array[i], array[frontIdx]);
            frontidx++;
        } else {
            i--;
        }
    }
}

// NOTICE THE IF ELSE CONDITION i.e. THE DECREMENT CONDITION