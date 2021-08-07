// Given a binary string of 0s and 1s. The task is to find the maximum difference 
// of the number of 0s and the number of 1s (number of 0s – number of 1s) in the substrings of a string.

// Note: In the case of all 1s, the answer will be -1.

// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1#

int maxSubstring(string S)
{
    int sum = 0, maxSum = 0;
    
    for(char c : S) {
        int num = c - '0';
        if(num == 1) {
            sum += -1;
        } else {
            sum += 1;
        }
        maxSum = max(sum, maxSum);
        sum = max(sum, 0);
    }
    return maxSum == 0 ? -1 : maxSum;
}
	
	
int maxSubstring(string S)
{
    int max_so_far=(S[0]=='1'?-1:1),curr_max=max_so_far;
    for(int i=1;i<S.length();i++)
    {
        int x=(S[i]=='1'?-1:1);
        curr_max=max(curr_max+x,x);
        max_so_far=max(max_so_far,curr_max);
    }
    return max_so_far<0?-1:max_so_far;
}