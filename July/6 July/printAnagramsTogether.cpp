#include <bits/stdc++.h>
using namespace std;

// Given an array of strings, return all groups of strings that are anagrams. 
// The groups must be created in order of their appearance in the original array.

// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
// https://www.algoexpert.io/questions/Group%20Anagrams (not exactly implemented, but similar)

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    vector<vector<string>> result;
    unordered_map<string, vector<string>> stringMap;
    // stores the sorted version of the string and the vector of words that can produce the string
    
    for(string current : string_list) {
        string sortedString = current;
        sort(sortedString.begin(), sortedString.end());
        stringMap[sortedString].push_back(current);
    }
    
    for(auto current : stringMap) {
        result.push_back(current.second);
        // adds the array of strings to the result
    }
    
    return result;
}