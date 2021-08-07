// You are given N identical eggs and you have access to a K-floored building from 1 to K.

// There exists a floor f where 0 <= f <= K such that any egg dropped at a floor 
// higher than f will break, and any egg dropped at or below floor f will not break. 
// There are few rules given below. 

// An egg that survives a fall can be used again.
// A broken egg must be discarded.
// The effect of a fall is the same for all eggs.
// If the egg doesn't break at a certain floor, it will not break at any floor below.
// If the eggs breaks at a certain floor, it will break at any floor above.
// Return the minimum number of moves that you need to determine with certainty what the value of f is.

// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1#

// https://www.youtube.com/watch?v=UvksR0hR9nA WATCH



int eggDrop(int n, int k) 
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    
    for(int i = 1; i <= n; i++){
		dp[i][1] = 1;
	}
	//if number of eggs == 1
	for(int i = 1 ; i <= k; i++){
		dp[1][i] = i;
	}


	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= k; j++){
			dp[i][j] = INT_MAX;
			int maxVal = INT_MIN;
			for(int f = 1; f <= j; f++){
				maxVal = 1 + max(dp[i - 1][f - 1], dp[i][j - f]);
				if(maxVal < dp[i][j]){
					dp[i][j] = maxVal;
				}
			}
		}
	}
	return dp[n][k];
} 