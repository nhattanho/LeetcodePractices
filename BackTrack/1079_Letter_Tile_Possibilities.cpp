/*Based on idea https://www.youtube.com/watch?v=6Sux9KoPJsc
We can represent this problem like a tree below
                                     "AAB"
                          /            |            \
                        A[0]          A[1]           B[2]
                     /   |   \      /   |   \      /   |   \        
                   A[0] A[1] B[2] A[0] A[1] B[2]  A[0] A[1] B[2]
                   |      |
                 same    diff ...................................
               position  form "AB"
               ==>return "AA" 
*/

class Solution {
public:
    unordered_set<string>s;/*Reduce duplicated, Space complexity #nodes in the tree*/
    
    void getString(string tiles, string word, unordered_map<int, int>&m){
        if(word.length() == tiles.length()) return;
        /*M depth of tree, and worst case has M^M path*/
        for(int i = 0; i<tiles.length(); i++){/*Backtrack => Time complexity M * M^M with M is the length of tiles*/
            if(m[i] == 0){
                word += tiles[i];
                s.insert(word);
                m[i] = 1; /*mean the current character has been used so far*/
                getString(tiles, word, m);
                word.pop_back();
                m[i] = 0;/*reset flag for the next combination*/
            }
            
        }
    }
    
    int numTilePossibilities(string tiles) {
        string word = "";
        unordered_map<int,int>m;
        getString(tiles, word, m);
        return s.size();
    }
};
/*More optimal*/
class Solution {
public:
    unordered_set<string>s;
    int count = 0;
    
    void getString(string tiles, string word, unordered_map<int, int>&m){
        if(word.length() == tiles.length()) return;
        
        for(int i = 0; i<tiles.length(); i++){
            if(m[i] == 0){
                word += tiles[i];
                if(s.count(word)){/*Duplicated regconization in the set => move to the next checking*/
                    word.pop_back();
                    continue;
                }
                count++;
                m[i] = 1; 
                getString(tiles, word, m);
                word.pop_back();
                m[i] = 0;
            }
            
        }
    }
    
    int numTilePossibilities(string tiles) {
        string word = "";
        unordered_map<int,int>m;
        getString(tiles, word, m);
        return count;
    }
};

/*Using BFS*/
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string>s;
        queue<pair<string, unordered_set<int>>>q;
        q.push({"",{-1}});
        int count = 0;
        
        /*Time complexity <=> go every possible node in the tree => M^M, M is the length of tiles */
        while(!q.empty()){
            pair<string, unordered_set<int>> top = q.front();
            q.pop();
            
            for(int i = 0; i < tiles.length(); i++){
                top.first += tiles[i];
                /*s reduces duplicated string while top.second reduces the 
                wrong case that the character connect with itself like AAB,
                then A at index 0 connects with itself to create AA*/
                if(s.count(top.first) == 0 && !top.second.count(i)){
                    count++;
                    s.insert(top.first);
                    unordered_set<int> temp = top.second;
                    temp.insert(i);
                    q.push({top.first, temp});
                }
                top.first.pop_back();
            }
        }
        return count;
        //return s.size();
    }
};

/*More optimal than above solution*/
class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string>s;
        queue<pair<string, unordered_set<int>>>q;
        q.push({"",{-1}});
        int count = 0;
        
        /*Time complexity <=> go every possible node in the tree => M^M, M is the length of tiles */
        while(!q.empty()){
            pair<string, unordered_set<int>> top = q.front();
            q.pop();
            
            /*can stop checking here and backtrack*/
            if(top.first.length() == tiles.length()) continue;
            
            for(int i = 0; i < tiles.length(); i++){
                top.first += tiles[i];
                /*s reduces duplicated string while top.second reduces the 
                wrong case that the character connect with itself like AAB,
                then A at index 0 connects with itself to create AA*/
                if(s.count(top.first) == 0 && !top.second.count(i)){
                    count++;
                    s.insert(top.first);
                    unordered_set<int> temp = top.second;
                    temp.insert(i);
                    q.push({top.first, temp});
                }
                top.first.pop_back();
            }
        }
        return count;
        //return s.size();
    }
};
