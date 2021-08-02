// Consider a rat placed at (0, 0) in a square matrix of order N * N. 
// It has to reach the destination at (N - 1, N - 1). 
// Find all possible paths that the rat can take to reach from source to destination. 
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
// Value 0 at a cell in the matrix represents that it is blocked and rat cannot 
// move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time.

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

// https://www.youtube.com/watch?v=bLGZhJlt4y0



void helper(vector<vector<int>> &m, vector<string> &ans, string curr, int i, int j) {
    if(i < 0 || j < 0 || i >= m.size() || j >= m[0].size() ||m[i][j] != 1) { 
    // invalid index
        return;
    }
    
    if(i == m.size() - 1 && j == m[0].size() - 1) {
    // end index is reached
        ans.push_back(curr);
        return;
    }
    
    // intermediate valid index

    m[i][j] = 0;
    
    helper(m, ans, curr + "D", i + 1, j);
    helper(m, ans, curr + "L", i, j - 1);
    helper(m, ans, curr + "R", i, j + 1);
    helper(m, ans, curr + "U", i - 1, j);
    
    m[i][j] = 1;
    
    return;
    
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    
    helper(m, ans, "", 0, 0);
    return ans;
}