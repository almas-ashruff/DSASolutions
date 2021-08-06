// Given a value N, find the number of ways to make change for N cents, 
// if we have infinite supply of each of S = { S1, S2, .. , SM } 
// valued coins.

// https://practice.geeksforgeeks.org/problems/coin-change2448/1#

// https://www.algoexpert.io/questions/Number%20Of%20Ways%20To%20Make%20Change

long long int count( int coins[], int m, int sum)
{
    vector<long long int> ways(sum + 1, 0);
    ways[0] = 1;
   
    for(int coin = 0; coin < m; coin++) {
        for(int i = 1; i < sum + 1; i++) {
            if(coins[coin] <= i) {
                ways[i] += ways[i - coins[coin]];
            }
        }
    }
    return ways[sum];
}