#include <bits/stdc++.h>
using namespace std;


// Given a string s, find the length of the longest substring 
// without repeating characters.

// https://leetcode.com/problems/longest-substring-without-repeating-characters/
// https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

// Solution 1

// Find the start index and the end index between which the substring exists.
// How? o(n) time, o(d) space, d = number of unique chars
// Maintain a hash table which contains the last index of appearance of each char.
// Iterate through the string. Check if the given character exists in the table
// If it does - 
//      set the start index of the subarray to the max of (startIndex) -> 
//      -> if the char's last appearance was before the current startIndex.
//      Or the (last appearance + 1)th index, since now char is being repeated.
// Update the last appearance of the current char in the hash map
// Check of the current maximum length ((endIndex - startIndex) + 1) is the greatest.



int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charLastIndex;
    int startIndex = 0;
    int maximumLength = 0;
    
    for(int endIndex = 0; endIndex < s.size(); endIndex++) {
        if(charLastIndex.find(s[endIndex]) != charLastIndex.end()) {
            startIndex = max(startIndex, charLastIndex[s[endIndex]] + 1);
        }
        charLastIndex[s[endIndex]] = endIndex;
        maximumLength = max(maximumLength, (endIndex - startIndex) + 1);
    }
    return maximumLength;
}
