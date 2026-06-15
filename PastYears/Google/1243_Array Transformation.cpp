/*
a[i-1] < a[i] > a[i+1] ==> a[i]--
a[i-1] > a[i] < a[i+1] ==> a[i]++
*/

class Solution {
public:
    vector<int> transformArray(vector<int>& a) {
        int len = a.size();
        int count = 0;
        
        while(true){
            bool inc = false;
            bool dec = false;
            if(a[0] < a[1]) inc = true;
            else if (a[0] > a[1]) dec = true;
            else {
                inc = false;
                dec = false;
            }
            for(int i = 1; i < len-1; i++){
                if(inc){
                    if(a[i] > a[i+1]){
                        inc = false;
                        dec = true;
                        a[i]--;  
                    }else if (a[i] < a[i+1]){
                        inc = true;
                        dec = false;
                        count++;
                    }
                    else {
                        dec = false;
                        inc = false;
                        count++;
                    }
                } else if (dec) {
                    if(a[i] < a[i+1]){
                        inc = true;
                        dec = false;
                        a[i]++;   
                    } else if (a[i] > a[i+1]){
                        inc = false;
                        dec = true;
                        count++;
                    } else{
                        inc = false;
                        dec = false;
                        count++;
                    }
                }
                else {
                    count++;
                    if(a[i] < a[i+1]) inc = true;
                    else if (a[i] > a[i+1]) dec = true;
                }
            }
            if(count == len-2) break;
            count = 0;
        }
        return a;
    }
};

/*Easier to read*/
class Solution {
public:
    vector<int> transformArray(vector<int>& a) {
        int len = a.size();
        int count = 0;
        
        while(true){
            int last = a[0];
            for(int i = 1; i < len-1; i++){
                if(a[i] > last && a[i] > a[i+1]){
                    last = a[i];
                    a[i]--;
                }else if(a[i] < last && a[i] < a[i+1]){
                    last = a[i];
                    a[i]++;
                }else{
                    count++;
                    last = a[i];
                }
            }
            if(count == len-2) break;
            count = 0;
        }
        
        return a;
    }
};

/*Or*/
class Solution {
public:
    vector<int> transformArray(vector<int>& a) {
        int len = a.size();
        bool cont = true;
        while(cont){
            cont = false;
            int last = a[0];
            for(int i = 1; i < len-1; i++){
                if(a[i] > last && a[i] > a[i+1]){
                    last = a[i];
                    a[i]--;
                    cont = true;
                }else if(a[i] < last && a[i] < a[i+1]){
                    last = a[i];
                    a[i]++;
                    cont = true;
                }else{
                    last = a[i];
                }
            }
        }
        
        return a;
    }
};
