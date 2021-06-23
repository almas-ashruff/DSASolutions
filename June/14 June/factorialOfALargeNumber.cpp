#include <bits/stdc++.h>
using namespace std;

// Given an integer N, find its factorial.

// https://practice.geeksforgeeks.org/problems/factorials-of-large-numbers2508/1#


// From left to right, each array index stores a digit.
// That digit in that index is multipled by 'mul' at each iteration
// length is incremented for each new index added.


vector<int> factorial(int num){
    int mul = 2;
    vector<int> result;
    result.push_back(1);
    int length = 1;
    
    int idx = 0;
    int carry = 0;
    
    while(mul <= num) {
        carry = 0;
        idx = 0;
        
        while(idx < length) {
            result[idx] = result[idx] * mul;
            result[idx] += carry;
            carry = result[idx] / 10;
            result[idx] = result[idx] % 10;
            idx++;
        }
        // the below loop is executed after the above loop is finished, i.e., the multiplication round is over.
        // It appends the remainder of the digits from the carry to the result array
        while(carry != 0) {
            result.push_back(carry % 10);
            carry = carry / 10;
            length++;
        }
        mul++;
    }
    reverse(result.begin(), result.end());
    // reverse the array, so that the 0th index stores the most significant digit. 
    // for the num 1234, 1 is stored at index 0 after reversal.
    return result;
}