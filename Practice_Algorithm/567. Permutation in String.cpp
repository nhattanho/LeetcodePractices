class Solution {
public:
    bool compairString(string s1, string s2){
        sort(s1.begin(), s1.end());//0(l1Log(l1))
        sort(s2.begin(), s2.end());
        if(s1 == s2) return true;
        return false;
    }
    //Time Complexity: l2*l1*Log(l1)
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        for(int i = 0; i < len2-len1+1; i++){//0(L2)
            char tmp = s2[i];
            auto found = s1.find(tmp);//0(L1)
            if(found != string::npos) {
                string s3 = s2.substr(i, len1);//0(L1)
                if(compairString(s1, s3)) return true;//0(l1Log(l1))
            }
        }
        return false;
    }
};

class Solution {
public:
    /*0(l1)*/
    bool compareString(string s, unordered_map<char, int>m){
        for(auto x: s){
            m[x]--;
            if(m[x] < 0) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        unordered_map<char, int>m1, m2;
        
        for(auto x: s1) m1[x]++;

        /*0(l2*l1)*/
        for(int i = 0; i < len2-len1+1; i++){
            char tmp = s2[i];
            if(m1.count(tmp)){
                string s3 = s2.substr(i, len1);
                if(compareString(s3, m1)) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    /*0(l1)*/
    bool compareString(string s, unordered_map<char, int>m){
        for(auto x: s){
            m[x]--;
            if(m[x] < 0) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        unordered_map<char, int>m1;
        
        for(auto x: s1) m1[x]++;

        /*0(l2*l1)*/
        for(int i = 0; i < len2-len1+1; i++){
            char tmp = s2[i];
            if(m1.count(tmp)){
                string s3 = "";
                for(int j = i; j < len1+i; j++) s3+=s2[j];
                if(compareString(s3, m1)) return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    /*0(l1)*/
    bool matching(int arr1[], int arr2[]){
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 > len2) return false;
        
        int array1 [26] = {0}, array2[26] = {0};
        
        for(int i = 0; i < len1; i++){
            array1[s1[i]-'a']++;
            array2[s2[i] -'a']++;
        }
        
        for(int i = 0; i < len2-len1+1; i++){
            if(matching(array1, array2)) return true;
            if(i == len2-len1) return false;
            int tmp = s2[i+len1]-'a';
            array2[tmp]++;
            array2[s2[i]-'a']--;
        }
        return false;
    }
};
