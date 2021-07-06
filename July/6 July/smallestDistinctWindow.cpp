#include <bits/stdc++.h>
using namespace std;

// Given a string 's'. The task is to find the smallest window length that contains 
// all the characters of the given string at least one time.
// For eg. A = “aabcbcdbca”, then the result would be 4 as of the smallest window will be “dbca”.

// https://practice.geeksforgeeks.org/problems/smallest-distant-window3132/1#
// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/hashmap-and-heaps/smallest-substring-of-a-string-containing-all-unique-characters-of-itself-official/ojquestion

 string findSubString(string str)
    {
        unordered_set<char> set;
        unordered_map<char, int> map;
        
        for(char c : str) {
            set.insert(c);
        }
        int ans = INT_MAX;
        
        // set stores all distinct characters in the array. 
        // map stores all distinct characters in the sliding window.
        // result stores the length of the smallest window.

        for(int i = 0, j = 0; i < str.size(); i++) {
            // acquire chars in the window to the right
            map[str[i]]++;
            
            // release chars from the window from the left
            while(map.size() == set.size() && j < str.size()) {
                map[str[j]]--;
                if(i - j + 1 < ans) {
                    ans = i - j + 1;
                    minString =
                }
                ans = min(ans, i - j + 1);
            }
            j++;
        }
        return ans;
    }