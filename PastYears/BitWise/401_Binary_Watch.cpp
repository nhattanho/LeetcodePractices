/*
Max hour is 11 <=> 1011
Max minutes is 59 <=> 111011
==> max bits 1 is 8
*/
class Solution {
public:
    vector<string> readBinaryWatch(int turn) {
        if(turn > 8) return {};
        vector<string>res;
        for(int h = 0; h < 12; h++){
            for(int m = 0; m < 60; m++){
                if (bitset<10>((h<<6)|m).count() == turn){
                    string minute = m<10?("0"+(to_string(m))):to_string(m);
                    res.push_back(to_string(h) + ":" + minute);
                }
            }
        }
        return res;
    }
};

/*Idea from https://leetcode.com/problems/binary-watch/discuss/88465/Straight-forward-6-line-c%2B%2B-solution-no-need-to-explain*/
vector<string> readBinaryWatch(int num) {
    vector<string> res;

    // iterate through all possible times
    for (int h = 0; h < 12; h++) 
    for (int m = 0; m < 60; m++)
        // Now store the time in bitset of size 10
        // where first 4 digits represent hours and
        // last 6 digits represent minutes, that's why
        // hours is left shifted 6 bits. If the count of
        // set bits equals num then append this time in our result
        if (bitset<10>(h << 6 | m).count() == num)
            // if minutes is single digit append 0 in front of it
            res.emplace_back(to_string(h) + (m < 10 ? ":0" : ":") + to_string(m));

    return res;
}
