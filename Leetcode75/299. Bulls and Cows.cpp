/*
#bulls: correct position <=> x
#cows:  in secrest number but wrong position <=> y
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> m1;
        map<pair<char, int>, int>m2;
        for(int i = 0; i < secret.length(); i++){
            m1[secret[i]]++;
            m2[{secret[i],i}]++;
        }
        vector<int>index;
        /*Find bull first*/
        for(int i = 0; i < guess.length(); i++){
            char c = guess[i];
            if(m2[{c, i}] != 0) {
                bulls++;
                m1[c]--;
            }else index.push_back(i);//save the position for checking cows
        }
        for(auto x: index){
            if(m1[guess[x]] != 0) {
                cows++;
                m1[guess[x]]--;
            }
        }
        string res = to_string(bulls) + "A" + to_string(cows) + "B";
        return res;
    }
};
