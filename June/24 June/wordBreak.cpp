#include <bits/stdc++.h>
using namespace std;

// Given a string A and a dictionary of n words B, find out if A can be segmented into 
// a space-separated sequence of dictionary words. 

// https://practice.geeksforgeeks.org/problems/word-break1352/1#
// https://www.youtube.com/watch?v=2NaaM_z_Jig&ab_channel=Pepcoding

// Watch the video !!

int wordBreak(string str, vector<string> &B) {
    unordered_set<string> dict;
    for(int i = 0; i < B.size(); i++) {
        dict.insert(B[i]);
    }
    // stores the words in the set
    
    vector<int> dp(str.size());
    
    for(int i = 0; i < str.size(); i++) {
        for(int j = 0; j <= i; j++) {
            string wordToCheck = str.substr(j, i - j + 1);
            // word created by characters between j and i

            if(dict.find(wordToCheck) != dict.end()) {
                // if word exists in the dictionary
                if(j > 0) {
                    dp[i] += dp[j - 1];
                    // if the word is not the first word
                } else {
                    dp[i] += 1;
                    // if the word is the first word
                }
            }
        }
    }
    return dp[str.size() - 1];   
}