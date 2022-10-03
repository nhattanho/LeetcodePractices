class Solution {
    public void processFlood(int[][] image, int r, int c, int origin, int color){
        if(r < 0 || r >= image.length || c < 0 || c >= image[0].length || image[r][c] != origin) return;
        image[r][c] = color;
        processFlood(image, r, c+1, origin, color);
        processFlood(image, r+1, c, origin, color);
        processFlood(image, r, c-1, origin, color);
        processFlood(image, r-1, c, origin, color);
    }
    
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int origin = image[sr][sc];
        if(origin == color) return image;
        processFlood(image, sr, sc, origin, color);
        return image;
    }
}
