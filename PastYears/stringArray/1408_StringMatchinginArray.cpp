/* Time complexity 0(n^2) */

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int size = words.size();
        vector<string>ans;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(i!=j){
                    if(words[i].find(words[j]) != string::npos){
                        ans.push_back(words[j]);
                        words.erase(words.begin() + j);
                        
                        /* if substring is on the left of main string,
                        need to decrease the position of main string to 1 */
                        if(j < i) i--; 
                        
                        j--;
                        size--;
                    }
                }
            }
        }
        return ans;
    }
};

/* Optimize the code thought the time Complexity is still 0(n^2) */

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int size = words.size();
        vector<string>ans;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(i!=j && words[j].find(words[i]) != string::npos){
                        /* Using i to mark the position of substring, and j points the
                        position of main string instead of using in reverse as the previous solution */
                        ans.push_back(words[i]); // So, don't need to erase element in vector
                        break;
                }
            }
        }
        return ans;
    }
};
