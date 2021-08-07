// You are given N pairs of numbers. In every pair, the first number is always smaller 
// than the second number. A pair (c, d) can follow another pair (a, b) if b < c. 
// Chain of pairs can be formed in this fashion. You have to find the longest chain which 
// can be formed from the given set of pairs. 
 
// https://practice.geeksforgeeks.org/problems/max-length-chain/1#

// https://www.youtube.com/watch?v=dgNdDMMb8Rk


int maxChainLen(struct val p[],int n)
{
    sort(p,p+n,[&](val &a,val &b){
        return a.first<b.first || (a.first==b.first && a.second<b.second);
    }); // sort based on first, then second
    
    vector<int> dp(n, 1);
    int ans = 1;
    
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(p[j].second < p[i].first) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    return ans;
}