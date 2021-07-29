// Given a positive integer N, print count of set bits in it. 

// https://practice.geeksforgeeks.org/problems/set-bits0143/1#

// https://www.youtube.com/watch?v=I475waWiTK4

int setBits(int n) {
    int count = 0;
    while(n > 0) {
        n -= n & (-n); // calculates last set bit mask
        count++;
    }
    return count;
}