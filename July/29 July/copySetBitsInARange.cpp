// Given two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. 
// Find the set bits of y in range [l, r] and set these bits in x also.

// https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/1

int setSetBit(int x, int y, int l, int r){
    int m = x;
    
    for(int i = l; i <= r; i++) {
        if(y & (1 << (i - 1))) {
            m = m | (1 << (i - 1));
        }
    }
    return m;
}