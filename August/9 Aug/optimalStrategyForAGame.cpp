// You are given an array A of size N. The array contains integers and is of even length. 
// The elements of the array represent N coin of values V1, V2, ....Vn. 
// You play against an opponent in an alternating way.
// In each turn, a player selects either the first or last coin from the row, 
// removes it from the row permanently, and receives the value of the coin.
// You need to determine the maximum possible amount of money you can win if you go first.
// Note: Both the players are playing optimally.

// https://practice.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1#

// https://www.youtube.com/watch?v=ww4V7vRIzSk

long long maximumAmount(int arr[], int n){
    int dp[n][n];
    
    for(int g = 0; g < n; g++) {
        for(int i = 0, j = g; j < n; i++, j++) {
            if(g == 0) {
                dp[i][j] = arr[i];
            } else if(g == 1) {
                dp[i][j] = max(arr[i], arr[j]);
            } else {
                int val1 = arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
                int val2 = arr[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
                
                dp[i][j] = max(val1, val2);
            }
        }
    }
    return dp[0][n - 1];
}