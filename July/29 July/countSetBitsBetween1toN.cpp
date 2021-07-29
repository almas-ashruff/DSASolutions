// You are given a number N. Find the total count of set bits 
// for all numbers from 1 to N (both inclusive).

// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1#

// https://www.youtube.com/watch?v=g6OxU-hRGtY


// Function to find the max power of 2 before a num
int largestPowOf2(int n) {
    int x = 0;
    while((1 << x) <= n) { // 1 << x means 2^x
        x++;
    }
    return x - 1; // because we exceed one pow as x++ comes later
}


int countSetBits(int n)
{
    if(n == 0) {
        return 0;
    }
    
    int x = largestPowOf2(n);
    
    // formula for number of set bits till 2^(x - 1)
    int bitsTillPowOf2 = x * (1 << (x - 1));

    // formula for number of set bits between 2^(x - 1) and 2^x
    int msbCountTillPowOf2 = (n - (1 << x)) + 1;
    
    // get the number range greater than 2^x and smaller than n.
    // recursively fine its number of set bits
    int restNums = n - (1 << x);
    
    int ans = bitsTillPowOf2 + msbCountTillPowOf2 + countSetBits(restNums);
    
    return ans;
}