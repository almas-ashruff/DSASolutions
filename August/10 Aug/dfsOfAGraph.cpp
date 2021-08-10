// Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
// Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal 
// of the graph starting from the 0th vertex,  from left to right according to the graph. 
// Also, you should only take nodes directly or indirectly connected from Node 0 in consideration.

// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// https://www.youtube.com/watch?v=uDWljP2PGmU

vector<int>bfsOfGraph(int v, vector<int> adj[])
{
    vector<int> ans;
    vector<bool> vis(v + 1, false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
            
    while(q.size()) {
       int node = q.front();
       q.pop();
       ans.push_back(node);
                
       for(auto n : adj[node]) {
           if(!vis[n]) {
               q.push(n);
               vis[n] = true;
           }
       }
    }
    return ans;
}