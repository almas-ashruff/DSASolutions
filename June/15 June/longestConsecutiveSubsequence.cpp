#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1
// https://www.youtube.com/watch?v=qgizvmgeyUM


// Sol 1 - Sort the array and find consecutive subsequence.
// simple solution, increment index, chack if value is one greater than previous value.


// Sol 2 - Use hash tables -
// Iterate and store all values in the hash table.
// Iterate again and check if one less than the current value exists in the hash table - 
//      If it does, move on. Keep checking for the value whose previous value does not exist in the hash table.
//      If the previous value to the current value does not exist, this value is the start value of the SUB-SEQUENCE.
//       ... so, keep incrementing one from the value and find the number of values after the current value that exist in the hash table.
//      Update the longest streak. 

int longestConsecutive(vector<int> & nums) {
    set<int> hashSet;

    for(int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if(!hashSet.count(num - 1)) {
            int currentNum = num;
            int currentStreak = 1;

            while(hashSet.count(currentNum + 1)) {
                currentNum++;
                currentStreak++;
            }
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    return longestStreak;
}