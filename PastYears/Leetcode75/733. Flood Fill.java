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

class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        Queue<int[]>q = new LinkedList<>();
        int original = image[sr][sc];
        q.add(new int[]{sr,sc});
        int row = image.length;
        int col = image[0].length;

        int[][]dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(q.size()!=0){
            int[]top = q.poll();
            int r = top[0];
            int c = top[1];
            image[r][c] = color;

            for(int i = 0; i < 4; i++){
                int newr = r+dir[i][0];
                int newc = c+dir[i][1];
                if(newr >=0 && newr < row && newc >= 0 && newc < col && image[newr][newc] == original)
                    q.add(new int[]{newr, newc});
            }
        }
        return image;
    }
}

