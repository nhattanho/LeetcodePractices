/* Using DFS - Time complexity = Space complexity = O(m*n) */
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

/*Other approach BFS
Time Complexity O(m*n)
Space complexity <=> maximum of #element in queue <=> number of elements in diagonal <=> min(m,n)
Prove: https://imgur.com/gallery/M58OKvB
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>>v = {{-1,0},{1,0},{0,-1},{0,1}};
        
        queue<pair<int, int>>q;
        q.push({sr,sc});
        
        int original = image[sr][sc];
        image[sr][sc] = newColor;
        
        while(!q.empty()){
            pair<int, int>top = q.front();
            q.pop();
            /*r-1, c; r+1,c; r, c-1, r,c+1* up down left right*/
            for(int i = 0; i < v.size(); i++){
                int newrow = top.first + v[i][0];
                if(newrow < 0 || newrow >= image.size()) continue;
                int newcol = top.second + v[i][1];
                if(newcol < 0 || newcol >= image[0].size()) continue;
                if(image[newrow][newcol] == original && image[newrow][newcol] != newColor)
                {
                    image[newrow][newcol] = newColor;
                    q.push({newrow, newcol});
                }
            }   
        }
        
        return image;
    }
};

