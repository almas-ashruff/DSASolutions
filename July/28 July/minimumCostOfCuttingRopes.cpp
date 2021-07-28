// There are given N ropes of different lengths, we need to connect these ropes into one rope. 
// The cost to connect two ropes is equal to sum of their lengths. 
// The task is to connect the ropes with minimum cost.

// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1#

long long minCost(long long arr[], long long n) {
        priority_queue<long long int,vector<long long int>,greater<long long int>> pq;
        
        for(int i = 0; i < n; i++) {
            pq.push(arr[i]);
        }
        
        long long int sum = 0; // to store the sum 
        
        while(pq.size() > 1) {
            long long len1 = pq.top();
            pq.pop();
            long long len2 = pq.top();
            pq.pop();
            pq.push(len1 + len2);
            
            sum += len1 + len2;
        }
        
        return sum;
    }
};