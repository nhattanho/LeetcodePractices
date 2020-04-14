/* Naive Solution*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int len = stones.size();
        for(int i = len-1; i > 0; i--){
            if(stones[i] == stones[i-1]){
                stones.pop_back();
                stones.pop_back();
                i -= 1;
            }else{
                int temp = abs(stones[i] - stones[i-1]);
                stones.pop_back();
                stones[i-1] = temp;
                sort(stones.begin(), stones.end());
            }
        }
        return (stones.size()==0)?0:stones[0];
    }
};

/* Better Solution */
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q(stones.begin(), stones.end());
        int len = q.size(), temp1, temp2, check_len;
        for(check_len = len; check_len > 1; check_len--){
            temp1 = q.top();
            q.pop();
            temp2 = q.top();
            q.pop();
            check_len--;
            if(temp2 != temp1){
                q.push(abs(temp2-temp1));
                check_len++;
            }
        }
        return (check_len == 0)?0:q.top();
    }
};
