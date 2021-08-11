// Given a Directed Acyclic Graph (DAG) with V vertices and E edges.
// Find any Topological Sorting of that Graph.

// https://practice.geeksforgeeks.org/problems/topological-sort/1

// https://www.youtube.com/watch?v=rZv_jHZva34

vector<int> topoSort(int v, vector<int> adj[]) 
{
    // kahn's algorithm (BFS solution)
    vector<int> ans;
    queue<int> q;
    vector<int> help(v, 0);
    
    for(int i = 0; i < v; i++) {
        for(int n : adj[i]) {
            help[n]++;
        }
    }
    
    for(int i = 0; i < v; i++) {
        if(help[i] == 0) {
            q.push(i);
        }
    }
    
    while(q.size()) {
        int n = q.front();
        ans.push_back(n);
        q.pop();
        
        for(int i : adj[n]) {
            help[i]--;
            if(help[i] == 0) {
                q.push(i);
            }
        }
    }
    
    return ans;
    
}