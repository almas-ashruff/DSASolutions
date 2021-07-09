// Given a number n. The task is to find the smallest number 
// whose factorial contains at least n trailing zeroes.

// https://practice.geeksforgeeks.org/problems/smallest-factorial-number5929/1
// https://www.youtube.com/watch?v=fx8rUY_iIms

int numberOfZeros(int n) {
    int count = 0;
    int fives = 5;
    while(n / fives > 0) {
        count += n / fives;
        fives *= 5;
        // watch the video to understand
    }
    return count;
}

int findNum(int n)
{
    if(n == 1) {
        return 5;
    }
    
    int low = 0; int high = 5 * n;
    int ans;
    while (low <= high) {
        // binary search to find the number
        int mid = (low + high) / 2;
        if(numberOfZeros(mid) >= n) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}