// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 
// which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the minimum time required to rot all oranges. 
// A rotten orange at index [i,j] can rot other fresh orange 
// at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 

// https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1#

// https://www.youtube.com/watch?v=TzoDDOj60zE
// https://www.youtube.com/watch?v=pUAPcVlHLKA

int orangesRotting(vector<vector<int>>& grid) {
    int direction[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int rows = grid.size();
    int cols = grid[0].size();
    int timer = -1;
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 2) { // rotten 
                q.push({i, j});
                grid[i][j] = 0; // so that rotten oranges are not visited again
            }
        }
    }
    
    while(q.size()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;
            
            for(int d = 0; d < 4; d++) {
                int nextR = r + direction[d][0];
                int nextC = c + direction[d][1];
                
                if(nextR >= 0 && nextC >= 0 && nextC < cols && nextR < rows && grid[nextR][nextC] == 1) {
                // checking validity of the new cell, and if it has a fresh orange 
                    grid[nextR][nextC] = 0;
                    q.push({nextR, nextC});
                }
            }
        }
        timer++;
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return timer;
}