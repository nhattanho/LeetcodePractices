/* Using DFS */
class Solution {
public:
    void fill(vector<vector<int>>&image, int row, int col, int color, int lenR, int lenC,int oldColor){
        if(row == lenR || col == lenC || row < 0 || col < 0) return;
        if(image[row][col] != oldColor) return;
        image[row][col] = color;
        fill(image, row-1, col, color, lenR, lenC, oldColor);
        fill(image, row+1, col, color, lenR, lenC, oldColor);
        fill(image, row, col-1, color, lenR, lenC, oldColor);
        fill(image, row, col+1, color, lenR, lenC, oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int lenR = image.size(), lenC = image[0].size();
        int oldColor = image[sr][sc];
        if(oldColor != newColor) 
            fill(image, sr, sc, newColor, lenR, lenC, oldColor);
        return image;
    }
};

class Solution {
public:
    void fill(vector<vector<int>>& image, int x, int y, int newColor, int oldColor, lenR, lenC){
        image[x][y] = newColor;
        if (x > 0 && image[x - 1][y] == oldColor) fill(image, x - 1, y, newColor, oldColor, lenR, lenC);
        if (x < lenR-1 && image[x + 1][y] == oldColor) fill(image, x + 1, y, newColor, oldColor, lenR, lenC);
        if (y > 0 && image[x][y - 1] == oldColor) fill(image, x, y - 1, newColor, oldColor, lenR, lenC);
        if (y < lenC-1 && image[x][y + 1] == oldColor) fill(image, x, y + 1, newColor, oldColor, lenR, lenC);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int lenR = image.size(), lenC = image[0].size();
        int oldColor = image[sr][sc];
        if (newColor != oldColor) fill(image, sr, sc, newColor, oldColor, int lenR, int lenC);
        return image;
    }
};

/* Using BFS */
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int lenR = image.size(), lenC = image[0].size(), row, col;
        int oldColor = image[sr][sc];
        if(oldColor == newColor) return image;
        queue<pair<int,int>>nodes;
        nodes.emplace(sr, sc);
        //nodes.push({sr, sc});
        while(!nodes.empty()){
            //we can use: row = nodes.front().first; col = nodes.front().second;
            //auto [row, col] = nodes.front(); // using auto without declaring the variables: row and col
            tie(row, col) = nodes.front(); // if we use tie(row, col), we have to declare the row and col first
            nodes.pop();
            image[row][col] = newColor;
            if(row >= 1 && image[row-1][col] == oldColor) nodes.emplace(row-1, col);
            if(row+1 < lenR && image[row+1][col] == oldColor) nodes.emplace(row+1, col);
            if(col >= 1 && image[row][col-1] == oldColor) nodes.emplace(row, col-1);
            if(col+1 < lenC && image[row][col+1] == oldColor) nodes.emplace(row, col+1);
        }
       return image; 
    }
};
