// Given three integers  'A' denoting the first term of an arithmetic sequence , 'C' 
// denoting the common difference of an arithmetic sequence and an integer 'B'. 
// you need to tell whether 'B' exists in the arithmetic sequence or not.

// https://practice.geeksforgeeks.org/problems/arithmetic-number2815/1

#include <bits/stdc++.h>
using namespace std;

int inSequence(int a, int b, int c){
// a -> first term, b-> exists or not, c -> common difference
    
    if(c == 0) { // if common difference is 0
        return a == b; // first num and given num should be the same
    }
    if((b - a) % c == 0 && (b - a) / c >= 0){
    // check 1 -> given num minus first num should be a multiple of common difference
    // check 2 -> given num minus first num should be a positive multiple of c.d.
        return true;
    }
    return false;

}