#include <bits/stdc++.h>
using namespace std;

// Give a binary string s, return the number of non-empty substrings that have the same number of 
// 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.
// Substrings that occur multiple times are counted the number of times they occur.
// https://leetcode.com/problems/count-binary-substrings/
// https://www.youtube.com/watch?v=MGPHPadxhtQ&ab_channel=AlgorithmsMadeEasy
 

 // SIMILAR BUT NOT SAME QUESTION -
// Given a binary string str of length N, the task is to find 
// the maximum count of consecutive substrings str can be divided into such that 
// all the substrings are balanced i.e. they have equal number of 0s and 1s. 
// If it is not possible to split str satisfying the conditions then print -1.
// https://www.geeksforgeeks.org/split-the-binary-string-into-substrings-with-equal-number-of-0s-and-1s/

int countBinarySubstrings(string s) {
    int count = 0, prev = 0, curr = 1;
    // See the test cases from the leetcode link
    // count keeps a count of the total such substrings
    // current keeps count of the total number of occurances of current character - either 0 or 1
    // prev keeps count of the total number of occurances of previous character - either 0 or 1

    for(int i = 1; i < s.size(); i++) {
        if(s[i] != s[i - 1]) {
        // check if there is a change from previous char
            count += min(prev, curr);
            // if yes, count gets incremented by the min of the 
            // current chars count and the previour chars count
            prev = curr;
            // since there is a change of char, prev count takes the value of the current count, and the current count becomes 1
            curr = 1;
        } else {
            curr++;
            // if there is no change, current count increases by 1
        }
    }
    return count += min(prev, curr);
    // this is done to push the last set of counts, as the loop will terminate and there wont be a change of char
}
