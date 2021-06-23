#include <bits/stdc++.h>
using namespace std;

// ALGOEXPERT HARD QUESTION
// Self explanatory

bool outOfBounds(int row, int col, int height, int width);

vector<int> zigzagTraverse(vector<vector<int>> array){
    vector<int> result = {};
    int row = 0;
    int col = 0;
    int height = array.size() - 1;
    int width = array[0].size() - 1;
    bool goingDown = true;

    while(!outOfBounds(row, col, height, width)){
        result.push_back(array[row][col]);
        if(goingDown){
            if(col == 0 || row == height){
                goingDown = false;
                if(row == height){
                    col++;
                } else{
                    row++;
                }
            } else{
                row++;
                col--;
            }

        }  else {
            if(row == 0 || col == width){
                goingDown = true;
                if(col == width){
                    row++;
                } else {
                    col++;
                }
            } else {
                row--;
                col++;
            }
        }
    }
    return result;
}

bool outOfBounds(int row, int col, int height, int width){
    return row < 0 || row > height || col < 0 || col > width;
}