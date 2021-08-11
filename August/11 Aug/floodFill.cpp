// An image is represented by an m x n integer grid image where image[i][j] 
// represents the pixel value of the image.

// You are also given three integers sr, sc, and newColor. 
// You should perform a flood fill on the image starting from the pixel image[sr][sc].

// To perform a flood fill, consider the starting pixel, plus any pixels connected 
// 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels 
// connected 4-directionally to those pixels (also with the same color), and so on. 
// Replace the color of all of the aforementioned pixels with newColor.

// Return the modified image after performing the flood fill.

// https://leetcode.com/problems/flood-fill/

// https://www.youtube.com/watch?v=TClRuEZ-uDg

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
    if(image[sr][sc] == newColor) {
        return image;
    }
    
    fillImage(image, sr, sc, image[sr][sc], newColor);
    
    return image;
    
}

void fillImage(vector<vector<int>> &image, int r, int c, int color, int newColor) {
    if(r < 0 || c < 0 || r >= image.size() || c >= image[0].size() || image[r][c] != color) {
        return;
    }
    
    image[r][c] = newColor;
    
    fillImage(image, r, c + 1, color, newColor);
    fillImage(image, r + 1, c, color, newColor);
    fillImage(image, r - 1, c, color, newColor);
    fillImage(image, r, c - 1, color, newColor);
}