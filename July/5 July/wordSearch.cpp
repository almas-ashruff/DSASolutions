#include <vector>
using namespace std;

// https://leetcode.com/problems/word-search/
// https://www.youtube.com/watch?v=vYYNp0Jrdv0

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, 
// where adjacent cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.

// USE DFS FOR EVERY MATCHING STARTING WORD 

class Solution {
public:
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0] && dfsFunc(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfsFunc(vector<vector<char>> &board, string word, int i, int j, int count) {
        if(count == word.size()){
            return true;
        }
        
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[count]) {
            return false;
        }
        int temp = board[i][j];
        board[i][j] = ' ';
        bool found = dfsFunc(board, word, i + 1, j, count + 1)
            || dfsFunc(board, word, i, j + 1, count + 1)
            || dfsFunc(board, word, i - 1, j, count + 1)
            || dfsFunc(board, word, i, j - 1, count + 1);
        board[i][j] = temp;
        return found;
    }
};