#include <bits/stdc++.h>
using namespace std;

// Find minimum number of cuts that can be introduced in the string to make sure that 
// ... all partitions are palindromes themselves.
// https://www.algoexpert.io/questions/Palindrome%20Partitioning%20Min%20Cuts

bool isPalindrome(string s);
int palindromePartitioningMinCuts(string s) {
  vector<vector<bool>> palindromes(s.length(), vector<bool>(s.length(), false));
  // Create a boolean array that stores whether a string from char index i to 
  // ... char index j is a palindrome.
	for(int i = 0; i < s.length(); i++) {
		for(int j = 0; j < s.length(); j++) {
			palindromes[i][j] = isPalindrome(s.substr(i, j + 1 - i));
		}
	}

    // cuts array stores the min number of cuts required in the substring till idx i to make sure 
    // ... all portions are palindromes.
	vector<int> cuts(s.size(), INT_MAX);
	for(int i = 0; i < s.size(); i++) {
		if(palindromes[0][i]) {
            // if the substring itself is a palindrome, then zero cuts
			cuts[i] = 0;
		} else {
            // at max, cuts for i equals (value for cuts for i - 1) + 1. (As last single char will be palindrome)
			cuts[i] = cuts[i - 1] + 1;
			for(int j = 0; j < i; j++) {
                // find palindromic substring from j to i, such that cuts of (j - 1) plus 1 is less than 
                // .. current value of cuts i.
				if(palindromes[j][i] && cuts[j - 1] + 1 < cuts[i]) {
					cuts[i] = cuts[j - 1] + 1;
				}
			}
		}
	}
	return cuts[cuts.size() - 1];
}

// checks whether the given string is a palindrome.
bool isPalindrome(string s) {
	int leftIdx = 0, rightIdx = s.size() - 1;
	
	while(leftIdx < rightIdx) {
		if(s[leftIdx] != s[rightIdx]) {
			return false;
		}
		leftIdx++;
		rightIdx--;
	}
	return true;
}