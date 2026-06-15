class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        bool inc = false;
        for(int i = 0; i < a.size()-1; i++){  
            if (i == 0){
                while(a[i] == a[i+1]){
                    i++;
                    if(i == a.size()-1) return true;
                }
                if(a[i] < a[i+1]) inc = true;
            }
            if(a[i] < a[i+1] && !inc) return false;
            if(a[i] > a[i+1] && inc) return false;
        }
        return true;
    }
};

/*Or*/
class Solution {
public:
    bool isMonotonic(vector<int>& a) {
        bool inc = true;
        bool dec = true;
        for(int i = 0; i < a.size()-1; i++){
            if(a[i] > a[i+1]) inc = false;
            if(a[i] < a[i+1]) dec = false;
        }
        return inc || dec;
    }
};
