/*Naive Solution with Time Complexity O(n^2), Space O(1)*/
class Solution {
public:
    int countElements(vector<int>& arr) {
        int temp = 0, ans = 0;
        for(int i = 0; i < arr.size(); i++){
            for(int j = 0; j < arr.size(); j++)
                if(arr[i] +1 == arr[j]){
                    ans++;
                    break;
                }
        }
        return ans;
    }
};

/* Optimal Solution with Time Complexity O(n), Space O(n)*/
class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int>fre;//number, fre
        int ans = 0;
        for(auto x: arr) fre[x]++;
        for(auto x:arr) if(fre[x+1] != 0) ans++;
        return ans;
    }
};
