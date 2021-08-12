// Given a weighted, undirected and connected graph of V vertices and E edges, 
// Find the shortest distance of all the vertex's from the source vertex S.
// Note: The Graph doesn't contain any negative weight

// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1#

// https://www.youtube.com/watch?v=jbhuqIASjoM


vector <int> dijkstra(int v, vector<vector<int>> adj[], int source)
{
    vector<int> dist(v, INT_MAX);
    vector<bool> vis(v, false);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    pq.push({0, source});
    
    dist[source] = 0;
    
    while(pq.size()) {
        int n = pq.top().second;
        pq.pop();
        
        for(auto i : adj[n]) {
            if(dist[i[0]] > dist[n] + i[1]) {
                dist[i[0]] = dist[n] + i[1];
                pq.push({dist[i[0]], i[0]});
            }
        }
    }
    
    return dist;
}