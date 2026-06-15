/*Let N be the number of characters in the input string and M be the number of characters in the banned list.
Time complexity = Space complexity = O(M+N)*/
class Solution {
public:
    string mostCommonWord(string para, vector<string>& ban) {
        //the answer is lowercase
        //split the words ==> count its frequency ==> check with the banned list
        int len = para.length();
        string word = "";
        map<string, int> fre, banFre;
        
        for(int i = 0; i < len; i++) if(ispunct(para[i])) para[i] = ' ';

        istringstream ss(para);
        while(ss >> word){
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            fre[word]++;
        }
    
        for(auto x: ban) banFre[x]++;
        
        string res;
        int max = 0;
        for(auto x : fre){
            string word = x.first;
            if(banFre[word] == 0) {
                if(x.second > max) {
                    max = x.second;
                    res = word;
                }
            }
        }
        return res;
    }
};
