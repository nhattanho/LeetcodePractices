class TwoSum {
public:
    vector<int>v;
    unordered_map<long, int>m;
    TwoSum() {
        
    }
    /*O(1)*/
    void add(int number) {
        v.push_back(number); 
        m[number]++;
    }
    
    /*O(n)*/
    bool find(int value) {
        for(auto x:v){
            long comp = long(value)-x;
            if(comp != x && m.count(comp) && m.count(x)) return true;
            if(comp == x && m[x] > 1) return true;
        }
        return false;
    }
};
