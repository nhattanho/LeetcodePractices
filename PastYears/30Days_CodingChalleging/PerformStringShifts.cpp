/* Time Complexity O(n), Space O(1) 
 * [0,1] + [0,5] + [1,4] + [1,2] //shift to left by 1 + shift left by 5 <=> shift-left by 6
 *     [0,6] + [1,4] + [1,2] // shift-left by 6 + shift-right by 4 <=> shift-left by 2
 *         [0,2] + [1,2]//shift-left by 2 + shift-right by 2 <=> no shifting
 *              [0,0] 
 * Besides, "abcdef" ==> len: 6, shift-left/right by 13 <=> shift-left/right by 13%6 = 1*/
class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int len = s.length();
        int direction = 0, amount = 0, temp = 0;
        for(auto x:shift){
	    temp = (x[1] >= amount)?x[0]:direction;
            amount = (x[0] == direction)?(amount + x[1]):abs(amount-x[1]);
	    direction = temp;
	    /*
            if(x[0] == direction) amount = amount + x[1];
            else{
                direction = (x[1] >= amount)?x[0]:direction;
                amount = abs(amount-x[1]);
            }
	    */
        }
        amount %=len;
        string ans;
	if(direction == 1) temp = len-amount;
        else temp = amount;
        ans = s.substr(temp, len- temp) + s.substr(0, temp);
        return ans;
	/*
        if(direction == 1)
            ans = s.substr(len-amount, amount) + s.substr(0, len-amount);
        else
            ans = s.substr(amount, len-amount) + s.substr(0, amount);
        return ans;
	*/
    }
};
