/*Version1*/
class Solution {
public:
    int balancedStringSplit(string s) {
        int max = 0, countL = 0, countR = 0;
        for(auto x:s){
            if(x=='L') countL++;
            else countR++;
            if(countL == countR){
                max++;
                countL = countR = 0;
            }
        }
        return max;
    }
};

/*Version2*/
class Solution {
public:
    int balancedStringSplit(string s) {
        map<char,int>data;
        int max = 0;
        for(auto x:s){
            data[x]++;
            if(data['L'] == data['R']){
                max++;
                data['L'] = data['R'] = 0;
            }
        }
        return max;
    }
};
