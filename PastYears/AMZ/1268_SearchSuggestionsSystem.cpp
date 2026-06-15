class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //variable
        int lenpro = products.size();
        int lensea = searchWord.length();
        vector<vector<string>>res(lensea, vector<string>{});
        
        // sort product <=> s* nlogn, s is the longest length of each producst, n is the number of products
        sort(products.begin(), products.end());
        
        //find substring of searchword in products
        int i = 0;
        string word="";
        // m is the length of searchWord ==> m*n
        for(auto x: searchWord){
            word += x;
            for(auto y:products){ // n products
                int lenword = word.length();
                if(y.substr(0,lenword) == word){
                    res[i].push_back(y);
                    if(res[i].size() == 3) break;
                }
            }
            i++;
        }  
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        //variable
        int lenpro = products.size();
        int lensea = searchWord.length();
        vector<vector<string>>res(lensea, vector<string>{});
        
        // sort product <=> s* nlogn, s is the longest length of each producst, n is the number of products
        sort(products.begin(), products.end());
        
        //find substring prefix of searchword in products
        string word="";

        int index = 0;
        for(auto x: searchWord){ // m is the length of searchWord ==> mlogn
            word += x;
            
            int start = lower_bound(products.begin(), products.end(), word) - products.begin(); // 0(logn)

            for(int i = start; i < start+3; i++){
                if(i < lenpro && products[i].substr(0,word.length()) == word) res[index].push_back(products[i]);
                else break;
            }
            index++;
        }
        
        return res;
        
        
    }
};
