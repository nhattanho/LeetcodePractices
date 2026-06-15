/*
a[1][0] = max (

a[0][0] + a[1][0] - abs(0-0);
a[0][1] + a[1][0] - abs(1-0);
a[0][2] + a[1][0] - abs(2-0);
)

a[i][j] = max (

a[i-1][0-> cols-1] + a[i][j] - abs(j1-j)

)
= max(a[i-1][k] - abs(k-j)) + a[i][j]

*/
class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int rows = p.size();
        int cols = p[0].size();
        long long res = *max_element(p[0].begin(), p[0].end());
        for(int i = 1; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int max1 = 0;
                for(int run = 0; run < cols; run++){
                    max1 = max(max1, p[i][j] + p[i-1][run] - abs(run-j));
                }
                p[i][j] = max1;
                if(i == rows - 1)
                    if(res < max1) res = max1;
            }
        }
        return res;
        
    }
};

/*Optimal Solution
As above, we have: a[i][j] = max(a[i-1][k] - abs(k-j)) + a[i][j], k run from 0 -> cols

+ k >= j <=> in the right side of the current column j, then 
a[i][j] = max(a[i-1][k] - k + j) + a[i][j] = max(a[i-1][k] - k) + a[i][j] + j (1)

+ k <= j <=> in the left side of the current column j, then
a[i][j] = max(a[i-1][k] - j + k) + a[i][j] = max(a[i-1][k] + k) + a[i][j] - j (2)

Since a[i][j] + j or a[i][j] - j is constant ==> the max value will based on the max(a[i-1][k] - k) or max(a[i-1][k] + k)

For each previous row:
Let maxLeft[k] = max(a[i-1][k] + k) is the maximum value go from the left with 0 <= k <= j
==> should be max(maxLeft[k-1], a[i-1][k] + k)

Let maxRight[k] = max(a[i-1][k] - k) is the maximum value go from the right with j <= k <= cols-1
==> should be max(maxRight[k+1], a[i-1][k] - k)

Finally, the a[i][j] = max( (1), (2) )
*/
class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int rows = p.size();
        int cols = p[0].size();
        
        vector<int>left(cols), right(cols);
        long long res = 0;

        for(int i = 1; i < rows; i++){
            left[0] = p[i-1][0];
            for(int k = 1; k < cols; k++){
                left[k] = max(p[i-1][k]+k, left[k-1]);
            }
            
            right[cols-1] = p[i-1][cols-1] - cols + 1;
            for(int k = cols - 2; k >= 0; k--){
                right[k] = max(right[k+1], p[i-1][k] - k);
            }
            
            for(int j = 0; j < cols; i++) {
                p[i][j] += max(left[j] - j, right[j] + j);
            }
        }
        
        res = *max_element(p[rows-1].begin(), p[rows-1].end());
        return res;
        
    }
};

/*Resolve the problem between int and long long type*/

class Solution {
public:
    long long maxPoints(vector<vector<int>>& p) {
        int rows = p.size();
        int cols = p[0].size();
        
        vector<long long>left(cols), right(cols);
        long long res = 0;
      
        //save the comparison value for the previous rows.
        vector<long long> temp(cols);
        
        for(int i = 0; i < cols; i++)
            temp[i] = p[0][i];
        
        for(int i = 1; i < rows; i++){
            left[0] = temp[0];
            for(int k = 1; k < cols; k++){
                left[k] = max(temp[k]+k, left[k-1]);
            }
            
            right[cols-1] = temp[cols-1] - cols + 1;
            for(int k = cols - 2; k >= 0; k--){
                right[k] = max(right[k+1], temp[k] - k);
            }
            
            for(int j = 0; j < cols; j++) {
                temp[j] = p[i][j] + max(left[j] - j, right[j] + j);
            }
        }
        
        res = *max_element(temp.begin(), temp.end());
        return res;  
    }
};
