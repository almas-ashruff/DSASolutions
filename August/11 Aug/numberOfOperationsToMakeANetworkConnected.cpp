// There are n computers numbered from 0 to n-1 connected by ethernet cables connections 
// forming a network where connections[i] = [a, b] represents a connection between computers a and b. 
// Any computer can reach any other computer directly or indirectly through the network.

// Given an initial computer network connections. You can extract certain cables between two 
// directly connected computers, and place them between any pair of disconnected computers to make them 
// directly connected. Return the minimum number of times you need to do this in order to make all 
// the computers connected. If it's not possible, return -1. 

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/


void dfs(vector<vector<int>> &adj, vector<bool> &vis, int idx) {
    vis[idx] = true;
    for(int i : adj[idx]) {
        if(!vis[i]) {
            dfs(adj, vis, i);
        }
    }
}


int makeConnected(int n, vector<vector<int>>& connections) {
    if(connections.size() < n - 1) {
        return -1;
    }
    
    vector<vector<int>> adj(n);
    
    for(auto v : connections) {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
        
    vector<bool> vis(n, false);
        
    int components = 0;
        
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            dfs(adj, vis, i);
            components++;
        }
        
    }
    return components - 1;
}