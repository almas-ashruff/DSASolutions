// Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not. 

// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1#

// https://www.youtube.com/watch?v=A8ko93TyOns

bool checkForCycle(int i, int v, vector<int> adj[], vector<bool> &vis) {
    queue<pair<int, int>> q;
    vis[i] = true;
    q.push({i, -1});
    
    while(q.size()) {
        int node = q.front().first;
        int prev = q.front().second;
        
        q.pop();
        
        for(auto n : adj[node]) {
            if(!vis[n]) {
                vis[n] = true;
                q.push({n, node});
            } else if(prev != n) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int v, vector<int>adj[])
{
    vector<bool> vis(v, false);
    
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            if(checkForCycle(i, v, adj, vis)) {
                return true;
            }
        }
    }
    return false;
}