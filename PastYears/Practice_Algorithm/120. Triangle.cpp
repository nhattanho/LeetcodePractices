class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int row = tri.size();
        int col = tri[0].size();
        int sum = tri[0][0];
        int j = 0;
        for(int i = 0; i < row-1; i++){
            sum += min(tri[i+1][j], tri[i+1][j+1]);
            j = tri[i+1][j] > tri[i+1][j+1] ? j+1 : j;
        }
        return sum;
    }
};

/*
            2                            2                           2                           11   ===> min sum from the top to bottom
         3     4                      3       4                   9     10                     9    10
       6    5     7       ^  ==>    7     6     10      ==>    7     6      10       ==>    7    6     10
     4   1     8     3    |       4    1     8    3          4    1      8      3         4    1    8      3


*/
class Solution {/*Combine between BFS and DP*/
public:
    int minimumTotal(vector<vector<int>>& v) {
        int row = v.size();  
        for(int r = row-2; r >= 0; r--){
            for(int c = 0; c < v[r].size(); c++){
                v[r][c] += min(v[r+1][c], v[r+1][c+1]);
            }
        }
        return v[0][0];
    }
}

/*Fancy DFS ==> check all paths of the BT => Time complexity 0(2^N)*/
class Solution {
public:
    int minV = 0;
    int findMin(vector<vector<int>>& v, int r, int c){
        if(r == v.size()-1) return v[r][c];
        
        int left = findMin(v, r+1, c);
        int right = findMin(v, r+1, c+1);
        return (v[r][c]+min(left, right));  
    }
    
    int minimumTotal(vector<vector<int>>& v) {
        int row = v.size();  
        return findMin(v, 0, 0);
    }
};
