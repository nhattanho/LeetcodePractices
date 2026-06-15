#include <map>
int solution(vector<int> s) {
    map<int, int>m;
    for(auto x:s){
        m[x]++;   
    }
    auto it1 = m.begin();
    auto it2 = m.rbegin();
    int count = 0;
    for(auto i = it1->first + 1; i<it2->first; i++){
        if(m[i] == 0) count++;
    }
    return count;
}

#include <map>
int solution(vector<int> s) {
    int max = *max_element(s.begin(), s.end());
    int min = *min_element(s.begin(), s.end());
    return max-min+1-s.size();
}
