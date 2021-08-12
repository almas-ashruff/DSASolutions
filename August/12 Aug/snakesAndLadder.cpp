// Given a 5x6 snakes and ladders board, find the minimum number of 
// dice throws required to reach the destination or last cell (30th cell) 
// from the source (1st cell).

// You are given an integer N denoting the total number of snakes and ladders 
// and an array arr[] of 2*N size where 2*i and (2*i + 1)th values denote 
// the starting and ending point respectively of ith snake or ladder. 
// The board looks like the following.

// https://practice.geeksforgeeks.org/problems/snake-and-ladder-problem4816/1#

// https://leetcode.com/problems/snakes-and-ladders/discuss/396710/BFS-intuition-diagrams-and-tests-c%2B%2B-12ms


int minThrow(int n, int arr[]){
    int board[31];
    
    for(int i = 1; i < 31; i++) {
        board[i] = i;
    }
    
    // Assigning the values of array given (snakes or ladder)
    for(int i = 0; i < 2 * n; i += 2) {
        board[arr[i]] = board[arr[i + 1]];
    }
    
    
    // Queue for storing the current index and the jumps that made
    queue<pair<int, int>> q;
    q.push({1, 0});
    
    while(q.size()) {
        auto curr = q.front();
        q.pop();
        
        // reaching the destination
        if(curr.first == 30) {
            return curr.second;
        }
        
        // roll the dice for all possible outcomes
        
        for(int i = 1; i <= 6 && (curr.first + i < 31); i++) {
            q.push({board[curr.first + i], curr.second + 1});
        }
    }
    
    return 0;
}