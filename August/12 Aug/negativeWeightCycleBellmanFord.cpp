// Given a weighted directed graph with n nodes and m edges. 
// Nodes are labeled from 0 to n-1, the task is to check if it contains 
// a negative weight cycle or not.
// Note: edges[i] is defined as u, v and weight.

// https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#

// https://www.youtube.com/watch?v=FtN3BYH2Zes&ab_channel=AbdulBari
// https://www.youtube.com/watch?v=75yC1vbS8S8&ab_channel=takeUforward
    
 
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    
    
    vector<int> dist(n, INT_MAX);
    
    dist[0] = 0;
    
    for(int i = 0; i < n + 1; i++) {
        for(auto edge : edges) {
            if(dist[edge[0]] != INT_MAX && dist[edge[1]] > dist[edge[0]] + edge[2]) {
                dist[edge[1]] = dist[edge[0]] + edge[2];
                
                if(i == n) {
                    return 1;
                }
            }
        }
    }
    return 0;
}