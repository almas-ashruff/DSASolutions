#include <bits/stdc++.h>
using namespace std;

// Given a string S, find the longest palindromic substring in S. 
// Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
// Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. 
// Incase of conflict, return the substring which occurs first ( with the least starting index).


// https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
// https://www.algoexpert.io/questions/Longest%20Palindromic%20Substring



vector<int> getLongestPalindrome(string s, int leftIndex, int rightIndex);

string longestPalin (string str) {
    vector<int> currentLongest {str.length() - 1, str.length() - 2};
    
    for(int i = str.length() - 1; i >= 0; i--) {
        vector<int> odd = getLongestPalindrome(str, i - 1, i + 1); 
        // returns the end indices of the odd length palindrome with current index as center.
        vector<int> even = getLongestPalindrome(str, i - 1, i);
        // returns the end indices of the even length palindrome with current index as center.

        vector<int> longest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
        // check which palindrome is longer

        currentLongest = currentLongest[1] - currentLongest[0] > longest[1] - longest[0] ? currentLongest : longest;
        // update the longest palindromic end indices
    }
    return str.substr(currentLongest[0], currentLongest[1] - currentLongest[0]);
    // return the substring
}

vector<int> getLongestPalindrome(string s, int leftIndex, int rightIndex) {
    
    // return the end indices of the longest palindrome
    while(leftIndex >= 0 && rightIndex < s.size()) {
        if(s[leftIndex] != s[rightIndex]) {
            break;
        }
        leftIndex--;
        rightIndex++;
    }
    return vector<int> {leftIndex + 1, rightIndex};
}
