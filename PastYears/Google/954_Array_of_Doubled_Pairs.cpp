class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int len = arr.size();
        if (len % 2 != 0) return false;
        
        unordered_map<int, int> m;

        for(auto& x: arr) {
            m[x]++;
        }
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < len; i++){
            if(arr[i] < 0 && arr[i]%2 == 0){
                if(m[arr[i]/2] != 0 && m[arr[i]] != 0){
                    m[arr[i]/2]--;
                    m[arr[i]]--;
                }   
            } else if (arr[i] >= 0 && m[arr[i]] != 0 && m[arr[i]*2] != 0){
                m[arr[i]]--; 
                m[arr[i]*2]--;
                /*For special case that is [6,3,0,1]*/
                if(m[arr[i]] < 0) return false;
            }  
        }
        for(auto x:m){
            if(x.second > 0) return false;
        }
        return true;
    }
};

/*Optimal for easier to read*/
class Solution {
public:
    /*[-4,-2,2,4] => [-2,2,-4,4]*/
    static bool cmp (int a1, int a2){
        return abs(a1) < abs(a2);
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        int len = arr.size();
        if (len % 2 != 0) return false;
        
        unordered_map<int, int> m;

        for(auto& x: arr) {
            m[x]++;
        }
        
        sort(arr.begin(), arr.end(), cmp);
        
        for(int i = 0; i < len; i++){
            if (m[arr[i]] != 0 && m[arr[i]*2] != 0){
                m[arr[i]]--; 
                m[arr[i]*2]--;
                /*For special case that is [6,3,0,1]*/
                if(m[arr[i]] < 0) return false;
            }  
        }
        for(auto x:m){
            if(x.second > 0) return false;
        }
        return true;
    }
};
