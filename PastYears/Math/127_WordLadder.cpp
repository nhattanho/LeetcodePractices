/* Using one-end BFS teachnique like the question Mnimum Genetic Mutation
 * Time Complexity O(m*n), m is length of wordList, n is length of word
 * Space O(m*n)*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dlist(wordList.begin(), wordList.end());
        queue<pair<string,int>>qsave;
        pair<string, int>pcheck;
        qsave.push({beginWord, 1});
        while(qsave.size() != 0){//m times in worst case
           pcheck = qsave.front();
           qsave.pop();
           string word = pcheck.first;
           if(word == endWord) return pcheck.second;
           for(int i = 0; i < beginWord.length(); i++){
               char backup = word[i];//n times
               for(char j = 'a'; j <= 'z'; j++){
                   word[i] = j ;
                   if(dlist.count(word) != 0){
                       qsave.push({word,pcheck.second+1});
                       dlist.erase(word);
                   }
               }
               word[i] = backup;
           }
        }
        return 0;
    }
};

/*We can reduce extra space and increase performance by using as code below*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dlist(wordList.begin(), wordList.end());
        queue<string>qsave;
        qsave.push(beginWord);
        int count = 0;
        while(qsave.size() != 0){
            count++;
            int qsize = qsave.size();
            for(int c = 0; c < qsize; c++){//BFS, using queue
                string word = qsave.front();
                qsave.pop();
                if(word == endWord) return count;
                for(int i = 0; i < beginWord.length(); i++){
                    char backup = word[i];
                    for(char j = 'a'; j <= 'z'; j++){
                        word[i] = j ;
                        if(dlist.count(word) != 0){
                            qsave.push(word);
                            dlist.erase(word);
                        }
                    }
                    word[i] = backup;
                }
            }
        }
        return 0;
    }
};

/*We can do better by using bidirectional BFS*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dlist(wordList.begin(), wordList.end());
        if(!dlist.count(endWord))  return 0;
        unordered_set<string>s1, s2, current;
        int count = 0;
        s1.insert(beginWord);
        s2.insert(endWord);
        while(s1.size() != 0 && s2.size() != 0){
            count++;
            if(s1.size() > s2.size()) //switch to the search direction having less node to reduce searching time
                swap(s1,s2);    
            for(auto x:s1){
                cout << "x: " << x << endl;
                for(int i = 0; i < x.length(); i++){
                    char backup = x[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        x[i] = c;
                        if(dlist.count(x)!=0){
                            //we go from both side for checking the encounter
                            //so if we use x to check with endWord, we will get
                            //false logic in case s1 start cheking from the end.
			    //That means s1.size > s2.size ==> s1 become to start
			    //from beginning.So, we just check whether x exisits
			    //in s2 or not.
                            //if(x == endWord) return count+1;==>false logic
                            dlist.erase(x);
                            current.insert(x);
                        }
                        if(s2.count(x)!=0) return count+1;
                    }
                    x[i] = backup;
                }
            }
            cout << current.size() << endl;
            s1 = current;//BFS, get level
            current.clear();
        }
        return 0;
    }
};
/*               dot -> dog   
 *              /          \
 * hit -> hot ->            -> cog 
 *              \          /
 *               lot -> log
 *
 * Just like going to find the shortest path from start to the end point.
 */
