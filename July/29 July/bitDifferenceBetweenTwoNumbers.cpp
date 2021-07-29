// You are given two numbers A and B. The task is to count the number of 
// bits needed to be flipped to convert A to B.

// https://practice.geeksforgeeks.org/problems/bit-difference-1587115620/1#

// https://www.youtube.com/watch?v=YvYGhJjQPTI


// Find the XOR of the two numbers. 
// XOR has a value 1 when the bits are different in the two numbers.
// Use Kernighan's algorithm to count the number of 1s in the XORed value
int countBitsFlip(int a, int b){
    int aXorB = a ^ b;
    int count = 0;
    while(aXorB) {
        aXorB -= aXorB & (-aXorB);
        count++;
    }
    return count;
}