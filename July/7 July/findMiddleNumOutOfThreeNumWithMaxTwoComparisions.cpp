#include <bits/stdc++.h>
using namespace std;

// Given three distinct numbers A, B and C. Find the number with value in middle with two or less comparisions.
// https://practice.geeksforgeeks.org/problems/middle-of-three2926/1

int middle(int A, int B, int C){
    int minNum = min({A, B, C});
    int maxNum = max({A, B, C});
    
    return A ^ B ^ C ^ minNum ^ maxNum; 
    // A number XORed with itself equals 0.
    // we can also return A + B + C - minNum - maxNum;
}