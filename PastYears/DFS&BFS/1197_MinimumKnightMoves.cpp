// Time complexity 0(m*n), space complexity 0(m,n) with m and n are sequence length of row and column
int findDirection(int startx, int starty, int endx, int endy){
    if(endx <startx && endy < starty) return 0;// first quad
    else if(endx < startx && endy >= starty) return 2;// second quadrant
    else if(endx >= startx && endy > starty) return 4;
    else return 6;
}

class Solution {
public:
    vector<vector<int>>direction = { {-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2} };
    int minKnightMoves(int x, int y) {
        if(abs(x) + abs(y) == 2) return 2;
        if(x == 0 && y == 0) return 0;
        unordered_set<string>visited;
        queue<pair<int, int>>pos;
        pos.push({0,0});
        visited.insert("0#0");
        int res=0;
        while(pos.size()>0){
            int size = pos.size();
            while(size > 0){
                pair<int, int> point = pos.front();
                pos.pop();
                
                int dir = findDirection(point.first, point.second, x, y);
                for(int i = dir; i<= dir+1; i++){
                    int newx = point.first + direction[i][0];
                    int newy = point.second + direction[i][1];
                    if(newx == x && newy == y) return res+1;
                    string temp = to_string(newx) + "#" + to_string(newy);
                    if(visited.find(temp) == visited.end()){ 
                        visited.insert(temp);
                        pos.push({newx, newy});
                    }
                }
                size--;
            }
            res++;
        }
        return -1;
    }
};