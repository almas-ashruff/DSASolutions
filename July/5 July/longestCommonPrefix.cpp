#include <bits/stdc++.h>
using namespace std;

// Write a function to find the longest common prefix string amongst an array of strings.
// https://leetcode.com/problems/longest-common-prefix/

// explanatory

string longestCommonPrefix(vector<string>& strs) {
    string result = "";
    
    if(!strs.size()){
        return result;
    }
    int index = 0;
    for(char c : strs[0]){
        for(int i = 1; i < strs.size(); i++) {
            if(index > strs[i].size() || c != strs[i][index]) {
                return result;
            }
        }
        result += c;
        index++;
    }
    return result;
}