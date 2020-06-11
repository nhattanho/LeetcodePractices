/* Time complexity O(n) */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int lenJ = J.length();
        if(lenJ == 0) return 0;
        map<char, int> check;
        int count = 0;
        for(auto x:J)
            check[x]++;
        for(auto x:S)
            if(check[x] == 1) count++;
        return count;
    }
};

/* The other solution */
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int lenJ = J.length();
        if(lenJ == 0) return 0;
        unordered_map<char, int> check;
        int count = 0;
        for(auto x:S)
            check[x]++;
        for(auto x:J)
            count += check[x];
        return count;
    }
};
