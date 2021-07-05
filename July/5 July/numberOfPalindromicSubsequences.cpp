#include <vector>
using namespace std;

// Given a string str of length N, you have to find number of 
// palindromic subsequence (need not necessarily be distinct) which could be formed from the string str.

// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1#
// https://www.youtube.com/watch?v=YHSjvswCXC8 Watch the DP creation part first
    
// Make a dp which stores the number of palindromic subsequences in the string
// ... made of starting chat string[i] to ending point string[j].
// Here, if the two extreme (starting and ending chars) are equal in the string, we find the number as - 
// ... dp[i][j] = answer without the first char + answer without the last char + answer without both starting and ending chars.
// ... else, if both extreme chars are not equal, 
// ... dp[i][j] = answer without the first char + answer without the ending char - 1.

int countPS(string s) {
    long long int mod = 1000000007;
    int n = s.length();
    int dp[n][n];
    for(int g = 0; g < n; g++){
        for(int j = g, i = 0; j < n; i++, j++){
            if(g == 0){
                dp[i][j] = 1;
            }
            else if(g == 1){
                if(s[i] == s[j]){
                    dp[i][j] = 3;
                } 
                else{
                    dp[i][j] = 2;
                } 
            }
            else if(s[i] == s[j]){
                dp[i][j] = (dp[i][j-1]+ dp[i+1][j] + 1) % mod;
                }
                else{
                    long long a = (dp[i][j-1] + dp[i+1][j])%mod;
                    long long b = dp[i+1][j-1];
                    dp[i][j] = ((a - b) % mod + mod) % mod;
                }
            }
        }
        return dp[0][n-1];
    }
     