// Given a binary grid. Find the distance of nearest 1 in the grid for each cell.
// The distance is calculated as |i1 – i2| + |j1 – j2|, where i1, j1 are the row number and column number 
// of the current cell and i2, j2 are the row number and column number of the nearest cell having value 1.

// https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#


vector<vector <int>> nearest(vector< vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans(n, vector<int> (m, INT_MAX - 1));
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < m; j++){ 
            if(grid[i][j] == 1) {
                ans[i][j] = 0; 
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] != 1){
                if(j - 1 >= 0){
                    ans[i][j] = min(ans[i][j], ans[i][j-1] + 1);
                }
              
                if(i-1 >= 0){
                    ans[i][j] = min(ans[i][j], ans[i-1][j] + 1);
                }
                if(j+1 < m){ 
                    ans[i][j] = min(ans[i][j], ans[i][j+1] + 1); 
                }
                if(i+1 < n){
                    ans[i][j] = min(ans[i][j], ans[i+1][j] + 1); 
                }
            }
        }
    }
    for(int i = n - 1 ; i >= 0; i--){
        for(int j = m - 1;j >= 0; j--){
            if(grid[i][j] != 1){
                if(j - 1 >= 0){
                    ans[i][j] = min(ans[i][j], ans[i][j-1] + 1);
                }
                if(i - 1 >= 0){
                    ans[i][j] = min(ans[i][j], ans[i-1][j] + 1);
                }
                if(j + 1 < m){ 
                    ans[i][j] = min(ans[i][j], ans[i][j+1] + 1); 
                }
                if(i + 1 < n){
                    ans[i][j] = min(ans[i][j], ans[i+1][j] + 1);
                }
            }
        }
    }
    return ans;
}