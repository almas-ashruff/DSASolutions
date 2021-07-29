// Given an array A containing 2*N+2 positive numbers, out of which 
// 2*N numbers exist in pairs whereas the other two number occur exactly once 
// and are distinct. Find the other two numbers.

// https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1#

// https://www.youtube.com/watch?v=pnx5JA9LNM4



vector<int> singleNumber(vector<int> nums) {
    int XxorY = 0;
    

    // Find the XOR of all numbers. 
    // All repeating number are cancelled out. 
    // The XOR of the two non repeating values, x and y is the answer
    for(int num : nums) {
        XxorY = XxorY ^ num;
    } 
    
    // find the right most set bit mask of the xor ans -> something like 0000010
    int rsbm = XxorY & (-XxorY); // rightmost set bit mask
    

    // declare the two answer values
    int x = 0, y = 0;
    

    // now, the numbers can be divided into two sets.
    // values in one set will have 1 at the RSBM, 
    // values in the other set will have 0.
    // The two non repeating values will always end up in different sets.
    // Now, XOR the two sets among themselves. 
    // The reamining value in each set will be the answers
    for(int num : nums) {
        if((num & rsbm) == 0) {
            x = x ^ num;
        } else {
            y = y ^ num;
        }
    }
    
    if( x < y) {
        return {x, y};
    } 
    
    return {y, x};
}



