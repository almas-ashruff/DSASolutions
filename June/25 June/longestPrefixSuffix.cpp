#include <bits/stdc++.h>
using namespace std;


// Given a string of characters, find the length of the longest proper prefix 
// which is also a proper suffix.
// https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1#

// https://www.algoexpert.io/questions/Knuth%E2%80%94Morris%E2%80%94Pratt%20Algorithm

// SOLUTION

// Uses patterns array creation from KMP algorithm

int lps(string s)
	{
	    int n = s.size();
	    int count = 0;
	    int i = 1;
	    int j = 0;
	    
	    while(i < n) {
	        if(s[i] == s[j]) {
                // if a matching character is found
	            i++;
	            j++;
	            count++;
                // increase the count
	        } else {
                // if that streak is broken
	            if(j == 0) {
                    // if j is at the 0th index, increase i for next matching
	                i++;
	            } else {
                    // if j is not at 0 and the pattern is broken
	                count = 0;
                    // count is 0 as the suffix is not complete
	                i = i - j + 1;
                    // i returns to the next index of the last mathing char for next comparision
	                j = 0;
	                // j returns to 0.

                    // Note -  this program is changing the position of the second index (i) for pattern matching
	            }
	        }
	    }
	    return count;
	}