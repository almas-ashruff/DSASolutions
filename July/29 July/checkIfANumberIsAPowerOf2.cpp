// Given a non-negative integer N. The task is to check if N is a power of 2. 
// More formally, check if N can be expressed as 2x for some x.

// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1#

// https://www.youtube.com/watch?v=I80Ovvi_nRU


// There is only one set bit in a pow of two
bool isPowerofTwo(long long n){
    
    if(n == 0) {
        return false;
    }
    return (n & (n - 1)) == 0;
    
}