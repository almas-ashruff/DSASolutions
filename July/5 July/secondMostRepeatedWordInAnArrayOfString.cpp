#include <bits/stdc++.h>
using namespace std;


// Given a sequence of strings, the task is to find out 
// the second most repeated (or frequent) string in the given sequence.

// https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1#

string secFrequent (string arr[], int n)
{
    unordered_map<string, int> count;
    for(int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    
    int max1 = 0;
    
    for(auto pair : count) {
        if(pair.second > max1) {
            max1 = pair.second;
        }
    }
    
    int max2 = 0;
    string ans;
    for(auto pair : count) {
        if(pair.second > max2 && pair.second < max1) {
            max2 = pair.second;
            ans = pair.first;
        }
    }
    
    return ans; 
}