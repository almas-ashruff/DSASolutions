// https://www.spoj.com/problems/EKO/
// https://www.youtube.com/watch?v=tkoucfh10SI


#include <bits/stdc++.h>
using namespace std;

int maxHeight(vector<int> arr, int woodLength) {
    int low = 0, high = 0;
    for(int i = 0; i < arr.size(); i++) {
        high = max(high, arr[high]);
        // high is set to the height of the tallest tree;
    }

    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(satisfies(arr, mid, woodLength) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

bool satisfies(vector<int> arr, int bound, int woodLength) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(bound < arr[i]) {
            sum += arr[i] - bound;
        }
    }
    if(sum < woodLength) {
        return false;
    }
    return true;
}