/* Suppose to have A(x0,y0), B(x1,y1), C(x2,y2), D(x3,y3), if (x1-x0)/(y1-y0) = (x2-x1)/(y2-y1)
==> Vector(AB) // vector(CB) ==> A, B, and C has to be on the same line. Then if
(x3-x2)/(y3-y2) = (x1-x0)/(y1-y0) or vector(CD) // vetor(AB). Also, A, B, C are on the same line,
so A, B, C, and D are on the same line too. */
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int numer = coordinates[1][0] - coordinates[0][0]; //x1-x0
        int denom = coordinates[1][1] - coordinates[0][1]; //y1-y0
        int numer1, denom1;
        for(int i = 1; i < coordinates.size()-1; i++){
            numer1 = coordinates[i+1][0] - coordinates[i][0];
            denom1 = coordinates[i+1][1] - coordinates[i][1];
            if( numer1*denom != denom1*numer ) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0];
        int x2 = coordinates[1][0];
        int y1 = coordinates[0][1];
        int y2 = coordinates[1][1];
        int x, y;
        for(int i = 2; i < coordinates.size(); i++){
            x = coordinates[i][0];
            y = coordinates[i][1];
            if( (x-x1)*(y-y2) != (x-x2)*(y-y1) ) return false;
        }
        return true;
    }
};
