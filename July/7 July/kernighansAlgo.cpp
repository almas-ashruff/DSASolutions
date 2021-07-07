#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#
// https://www.youtube.com/watch?v=I475waWiTK4  
// https://www.youtube.com/watch?v=XcSr6TIMl7w

// Kernighan's algo is used to count the number of 'set-bits', i.e. 1's in the binary representation of a numbr.
// For this, we use the property that find the right most set bit mask.
// Right-most set bit mask is the last appearing one, followed by 0s in the binary representation of a number.
// eg - RSB Mask of 0010010100 is 0000000100
// RSB Mask can be found by the & operation of the actual number and the 2s compliment of the number (negative of the number). 
// eg - RSB Mask of 68 is 68 & (-68).

// Kernighan's algo - 

int kernighans(int num) {
    int count = 0;
    while(num != 0) {
        int rsbm = num & (num * -1);
        num -= rsbm;
        count++
    }
    return count;
}