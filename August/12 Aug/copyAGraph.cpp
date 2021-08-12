Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

https://leetcode.com/problems/clone-graph/

https://leetcode.com/problems/clone-graph/discuss/42313/C%2B%2B-BFSDFS

// BFS
unordered_map<Node*, Node*> copies;
Node* cloneGraph(Node* node) {
    if(!node) {
        return NULL;
    }
    
    Node *copy = new Node(node -> val, {});
    copies[node] = copy;
    
    queue<Node *> q;
    q.push(node);
    
    while(q.size()) {
        Node *curr = q.front();
        q.pop();
        
        for(Node *neighbor : curr -> neighbors) {
            if(copies.find(neighbor) == copies.end()) {
                copies[neighbor] = new Node(neighbor -> val, {});
                q.push(neighbor);
            }
            copies[curr] -> neighbors.push_back(copies[neighbor]);
        }
    }
    return copy;
}



// DFS

unordered_map<Node*, Node*> copies;
Node* cloneGraph(Node* node) {
    if (!node) {
        return NULL;
    }
    if (copies.find(node) == copies.end()) {
        copies[node] = new Node(node -> val, {});
        for (Node* neighbor : node -> neighbors) {
            copies[node] -> neighbors.push_back(cloneGraph(neighbor));
        }
    }
    return copies[node];
}