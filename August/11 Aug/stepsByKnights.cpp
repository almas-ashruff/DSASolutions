// Given a square chessboard, the initial position of Knight and position of a target. 
// Find out the minimum steps a Knight will take to reach the target position.

// Note:
// The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

// https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

bool isValid(int x, int y, int row, int col) {
    return x >= 0 && x < row && y >= 0 && y < col;
}


int minStepToReachTarget(vector<int>&knightPos,vector<int>&targetPos,int n)
{
    queue<vector<int>> q; 
    // we need a BFS approach for the shortet path, not DFS
    
    q.push({knightPos[0] - 1, knightPos[1] - 1, 0}); 
    // {x index, y index, distance travelled}
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    
    int dx[] = {-2, -1, -1, -2, 2, 2, 1, 1};
    int dy[] = {-1, -2, 2, 1, -1, 1, -2, 2};
    
    vis[knightPos[0] - 1][knightPos[1] - 1] = true;
    
    while(q.size()) {
        auto node = q.front();
        q.pop();
        
        int x = node[0], y = node[1], dist = node[2];
        
        if(x == targetPos[0] - 1 && y == targetPos[1] - 1) {
            return dist;
        }
        
        for(int i = 0; i < 8; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            
            if(isValid(nextX, nextY, n, n) && !vis[nextX][nextY]) {
                q.push({nextX, nextY, dist + 1});
                vis[nextX][nextY] = true;
            }
        }
    }
    return 0;
}