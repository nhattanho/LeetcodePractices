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
