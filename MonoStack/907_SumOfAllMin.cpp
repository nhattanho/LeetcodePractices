/* Using DP, Time complexity O(n^2) */
class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int len = 0, j;
        int sum = 0;
        int mod = pow(10, 9) + 7;
        vector<vector<int>>dp(a.size(),vector<int>(a.size(),0));
        while(len < a.size()){
            len++;
            for (int i = 0;  i < a.size()-len+1; i++) {
                j = len-1+i;
                if (len == 1) {
                    dp[i][j] = a[i];
                }
                else {
                    dp[i][j] = min(dp[i][j-1], dp[i+1][j]);      
                }
                sum %= mod;
                sum += (dp[i][j]%mod);
                
            }
        }
        return sum;
    }
};

/* Using Monotonous Stack, Time complexity O(n) */
/* Reference: https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step */
class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int size = a.size();
        int ans = 0;
        int mod = pow(10, 9) + 7;
        stack<pair<int, int>> stackP, stackN;//value, position
        vector<int> lessR(size), lessL(size);
        for(int i = 0; i < size; i++) {
            //For some cases we can not find the less value for current position from the left
            //Example: 1. the first position doesn't have any less-left value than it =>distance = 0 + 1 = 1
            //2. 6 8 9 4 ==> at position 3, it doesn't have any less-left value ==> distance = 3 + 1 = 4
            lessL[i] = i + 1;  
            
            //For some cases we can not find the less value for current position from the right
            //Example: 1. 6 8 9 10 ==> at position 0, it doesn't have any less-right value ==> distance = 4 - 0
            lessR[i] = size-i;
        }
        
        for (int i = 0; i < size; i++){
            
            //stackP saves the previous of less value
            while(!stackP.empty() && stackP.top().first > a[i]){ 
                stackP.pop();// Remove untill we get the less value of current i position
                
            }
            if(!stackP.empty()){
                //lessL[i] = stack.top().second; // save the position of the less-left for the current position i
                lessL[i] = i - stackP.top().second; // instead of saving the position, we saved the distance from the left. still work for stackP.top().first = a[i]
            }
            stackP.push({a[i], i});
            
            while(!stackN.empty() && stackN.top().first > a[i]){ //stackN saves the current value
                lessR[stackN.top().second] = i - stackN.top().second;
                stackN.pop(); // remove the value from stack when we found its less value
            }
            stackN.push({a[i], i});
        }
        
        for(int i=0; i<size; i++){
            ans = ans%mod;
            ans = ans + (a[i]*lessL[i]*lessR[i])%mod;
        }
        return ans;
    }
};

/* Optimize the Mono Stack */
class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        int mod = pow(10, 9) + 7;
        int ans = 0;
        int len = a.size();
        stack<int>st;
        vector<int> left(len), right(len);
        for(int i = 0; i < len; i++) {
            left[i] = i+1;
            right[i] = len-i;
            while(!st.empty()){
                if(a[st.top()] <= a[i]){
                    left[i] = i - st.top();//Found the left-less ==> save the distance
                    break;
                } else if (a[st.top()] > a[i]) {
                    right[st.top()] = i - st.top();//Found the right-less ==>save the distance
                    st.pop();//==> found the left and the right ==> pop it out the stack
                }
            }
            st.push(i);//save the previous value prepairing for the next step
        }
        for(int i=0 ; i < len; i++){
            ans = ans%mod;
            ans = ans + (a[i]*left[i]*right[i])%mod;
        }
        return ans;
    }
};
