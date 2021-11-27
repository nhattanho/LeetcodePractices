/*
we need to find the new position after rotating for each element in the matrix.
We can easily realize that with [r][c] ==> [newrow][newcol], with
newrow = c
newcol = cols-1-r
==>[r][c] => [c][cols-1-r]
Since rotating the square ==> need to rotate 4 times
==> m[r][c] => m[c][cols-1-r] => m[cols-1-r][cols-1-c] => m[cols-1-c][r] => m[r][c]
Then pseudo code:
m[c][cols-1-r] = m[r][c] ==> need to save the left side first ==> temp1 = m[c][cols-1-r]
m[cols-1-r][cols-1-c] = m[c][cols-1-r] ==> need to save the left side temp2 = m[cols-1-r][cols-1-c]
m[cols-1-c][r] = m[cols-1-r][cols-1-c]
m[r][c] = m[cols-1-c][r]

The next thing is that we need to find the constrain of row and col.
We go from the outside to inside of matrix
 *   * * * * * * *   *
 
 *   * * * * * * *   *
 *   * * * * * * *   *
 *   * * * * * * *   *
 *   * * * * * * *   *
 *   * * * * * * *   *
 *   * * * * * * *   *
 *   * * * * * * *   *
 
 *   * * * * * * *   *
 
 As we can see, with r = 0, we will go swap value for the outbound of the matrix
 and when r is increasing, we go to inner matrix ==> col = r -> cols-1-r
*/

class Solution {
public: 
    void rotate(vector<vector<int>>& m) {
        int rows = m.size();
        int cols = m[0].size();
        int temp1 = 0, temp2 = 0;
        for(int r = 0;  r <= rows/2; r++)    {
            for(int c = 0 + r; c < cols-1-r; c++){
                /*m[r][c] => [c][cols-1-r] => [cols-1-r][cols-1-c] => [cols-1-c][r] => [r][c]*/

                temp1 = m[c][cols-1-r];//save 3
                m[c][cols-1-r] = m[r][c];//1
                
                temp2 = m[cols-1-r][cols-1-c];
                m[cols-1-r][cols-1-c] = temp1;
                
                temp1 = m[cols-1-c][r];
                m[cols-1-c][r] = temp2;
                m[r][c] = temp1;
            }
        }
    }
};

/*We can go another way*/
class Solution {
public:
    
    void rotate(vector<vector<int>>& m) {
        int rows = m.size();
        int cols = m[0].size();
        int temp = 0;
        for(int r = 0;  r <= rows/2; r++)    {
            for(int c = 0 + r; c < cols-1-r; c++){
                // m[r][c] => [c][cols-1-r] => [cols-1-r][cols-1-c] => [cols-1-c][r] => [r][c]
                
                temp = m[r][c];
                m[r][c] = m[cols-1-c][r];
                m[cols-1-c][r] = m[cols-1-r][cols-1-c];
                m[cols-1-r][cols-1-c] = m[c][cols-1-r];
                m[c][cols-1-r] = temp;
            }
        }
    }
};
