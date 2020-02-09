//Author: Nhat Ho
//davisho2411@gmail.com
/*Find the identical characters of two strings using map*/
class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int>maps;
        map<char, int>mapt;
        int count = 0;
        for(auto x:t) mapt[x]++;
        for(auto x:s) maps[x]++;
        for(auto x:mapt){
            /*
            for(auto y:maps){
                if(x.first == y.first){
                    count += (x.second>y.second?y.second:x.second);
                }
            }
            */
            if(maps[x.first]) count += (x.second>maps[x.first]?maps[x.first]:x.second);
        }
        return s.length()-count;
    }
};

/*Find the different characters of 2 strings using map*/
class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int>maps;
        map<char, int>mapt;
        int count = 0;
        for(auto x:t) mapt[x]++;
        for(auto x:s) maps[x]++;
		for(int i = 0; i < 26; i++){
			char c = i + 'a';
			count += abs(mapt[c]-maps[c]);
		}
		return count/2;
	}
};

/*Find the different characters of 2 strings using vector*/
class Solution {
public:
    int minSteps(string s, string t) {
		int alpha[26];
        int count = 0;
        for(auto x:t) alpha[x-'a']++;
        for(auto x:s) alpha[x-'a']--;
		for(int i = 0; i < 26; i++) count += abs(alpha[i]);
		return count/2;
    }
};
