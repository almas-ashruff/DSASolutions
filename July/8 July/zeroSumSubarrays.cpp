#include <bits/stdc++.h>
using namespace std;

// You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.

// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1#
// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/count-of-all-subarrays-with-zero-sum-official/ojquestion

findSubarray(vector<int> arr, int n ) {
    unordered_map<int, int> map;
    map[0] = 1;
    int sum = 0; int count = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        map[sum]++;
        if(map[sum] > 1) {
             count = count + map[sum] - 1; 
             // this is important as for every repeated sum, we get multiple subarrays with 0 sum, not just 1 extra
        }
    }
    return count;
}