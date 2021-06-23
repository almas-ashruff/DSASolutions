#include <bits/stdc++.h>
using namespace std;


// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an array of the 
// non-overlapping intervals that cover all the intervals in the input.

// https://leetcode.com/problems/merge-intervals/

// Solution - O(nLogn) time


vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    for (int i = 0; i < intervals.size(); i++) {
        vector<int> interval = intervals[i];
        // if the list of merged intervals is empty or if the current
        // interval does not overlap with the previous, simply append it.
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        }
        // otherwise, there is overlap, so we merge the current and previous
        // intervals.
        else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    return merged;
}


