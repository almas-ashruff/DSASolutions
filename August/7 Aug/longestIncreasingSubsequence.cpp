// Given an array of integers, find the length of the longest (strictly) increasing subsequence 
// from the given array.

// https://www.geeksforgeeks.org/lower_bound-in-cpp/

// https://www.algoexpert.io/questions/Longest%20Increasing%20Subsequence

// OPTIMIZED DP - O(N Log N) - solution. Can also be solved using less complex DP solution in O(N ^ 2)

int longestSubsequence(int n, int a[])
{
    vector<int> dp;
    dp.push_back(a[0]);
   
    for(int i = 0; i < n; i++) {
        if(dp.back() < a[i]) {
            dp.push_back(a[i]); 
        // if the current value in the array is greater than the 
        // last value in the DP, push the current value in the DP at the end
        } else { // if the current array value is smaller
            int index = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            // The lower_bound() method in C++ is used to return an iterator 
            // pointing to the first element in the range [first, last) 
            // which has a value not less than val.
            // https://www.geeksforgeeks.org/lower_bound-in-cpp/
           
           
           // index = the first index that has the value 
           // greater than or equal to current array value.
           // You have to subtract the begining index to get 
           // the index in the array
           
            dp[index] = a[i];
        }
    }
    return dp.size();
}