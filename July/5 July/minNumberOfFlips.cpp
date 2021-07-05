#include <bits/stdc++.h>
using namespace std;

// Given a binary string, that is it contains only 0s and 1s. We need to make this string a sequence of 
// alternate characters by flipping some of the bits, our goal is to minimize the number of bits to be flipped.

// https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1


int minFlips (string s)
{
    int count0 = 0, count1 = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if(i % 2 == 0) {
            if(s[i] != '0') {
                count0++;
            } else {
                count1++;
            }
        } else {
            if(s[i] != '0') {
                count1++;
            } else {
                count0++;
            }
        }
    }
    return min(count0, count1);
}