class Solution {
public:
    void processFill(vector<vector<int>>& image, int r, int c, int color, int origin){
        if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size() || image[r][c] != origin){
            return;
        }
        image[r][c]=color;
        //right
        processFill(image, r, c+1, color, origin);
        //up
        processFill(image, r+1, c, color, origin);
        //left
        processFill(image, r, c-1, color, origin);
        //down
        processFill(image, r-1, c, color, origin);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origin = image[sr][sc];
        if(origin==color) return image;
        processFill(image, sr, sc, color, origin);
        return image;
    }
};
