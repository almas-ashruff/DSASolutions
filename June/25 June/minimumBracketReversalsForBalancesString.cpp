#include <bits/stdc++.h>
using namespace std;

// Given a string S consisting of only opening and closing curly brackets '{' and '}', 
// find out the minimum number of reversals required to convert the string into a balanced expression.
// A reversal means changing '{' to '}' or vice-versa.

// https://practice.geeksforgeeks.org/problems/count-the-reversals0401/1#
// https://www.youtube.com/watch?v=-n_CsIL3Ts4

// Solution -


int countRev (string s) {

    if(s.size() % 2 == 1) {
        return -1;
    }
    // if string length is odd, brackets cannot be balanced
    
    int open = 0, close = 0;
    // counter of open and closed brackets that are unbalanced.

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '{') {
            open++;
            // if a new opening bracket is added, increase the counter
        } else {
            // if closing bracket is added
            if(open == 0) {
                // if no closing bracket exists to cancel it out
                close++;
                // unbalanced closed bracket exists
            } else {
                open--;
                // else it cancels an opening bracket
            }
        }
    }
    
    // the answer is the sum of the ciel value of the unbalanced opening brackets / 2 and unbalanced closing brackets / 2.
    return ceil((float)open / 2) + ceil((float)close / 2);
    
}