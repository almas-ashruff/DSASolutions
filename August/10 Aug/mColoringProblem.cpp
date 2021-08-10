// Given an undirected graph and an integer M. The task is to determine if the graph can be colored 
// with at most M colors such that no two adjacent vertices of the graph are colored with the same color. 
// Here coloring of a graph means the assignment of colors to all vertices. 
// Print 1 if it is possible to colour vertices and 0 otherwise.

// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

// https://www.youtube.com/watch?v=wuVwUK25Rfc

bool isSafe(int node, int color[], bool graph[101][101], int v, int col) {
    for(int k = 0; k < v; k++) {
        if(k != node && graph[k][node] == 1 && color[k] == col) {
            return false;
        }
    }
    return true;
}

bool helper(int node, int color[], int m, int v, bool graph[101][101]) {
    if(node == v) {
        return true;
    } // base check
    
    for(int i = 1; i < m + 1; i++) {
        if(isSafe(node, color, graph, v, i)) {
            color[node] = i;
            if(helper(node + 1, color, m, v, graph)) {
                return true;
            }
            color[node] = 0;
        } 
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int v)
{
    int color[v] = {0};
    return helper(0, color, m, v, graph);
}
