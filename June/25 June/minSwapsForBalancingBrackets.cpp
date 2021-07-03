#include <bits/stdc++.h>
using namespace std;

// You are given a string S of 2N characters consisting of N ‘[‘ brackets 
// and N ‘]’ brackets. A string is considered balanced 
// if it can be represented in the for S2[S1] where S1 and S2 are 
// balanced strings. We can make an unbalanced string balanced 
// by swapping adjacent characters. Calculate the minimum number of 
// swaps necessary to make a string balanced.
// Note - Strings S1 and S2 can be empty.

// https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1#


// The trick here is whenever you traverse from left to right, 
// count of left parenthesis will be greater than equal to the 
// count of right parenthesis for a balanced state.

// Maintain counters for left and right parenthesis
// Suppose you're going from left to right:-

// If you see a right parenthesis(increment your counter) and 
// you haven't seen any left parenthesis before to balance it out, 
// that is, the count of right parenthesis went up than the count of left parenthesis, 
// then there is imbalance.

// Who will remove this imbalance, any left parenthesis which comes ahead.

// So whenever you see a left parenthesis and 
// count of right parenthesis > count of left parenthesis, 
// then there is an imbalance and this left parenthesis will 
// help remove / reduce the imbalance. 
// You'll need (count of right - count of left) swaps 
// to balance out the first unbalanced right parenthesis you saw, 
// after this you increment the count of left parenthesis.

    
int minimumNumberOfSwaps(string S){
    int left = 0, right = 0;
    int n = S.size(), swaps = 0;
    for(int i = 0;i < n;i++) {
        if(S[i] == '[' ) {
            if(right > left){
                swaps += (right - left);
            }
            left++;
        }
        if(S[i] == ']') {
            right++;
        }
     }
    return swaps;
}