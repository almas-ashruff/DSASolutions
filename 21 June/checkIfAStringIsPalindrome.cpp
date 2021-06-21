#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

bool isPlaindrome(string s)
{
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}