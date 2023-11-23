class Solution {
public:
    int len;
    int callIndex;
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        len = gas.size();
        for(int i = 0; i < len; i++){
            if(gas[i] >= cost[i]){
                callIndex = i;
                if(checkCircuit(i, gas, cost)) return i;
            }
        }
        return -1;
    }

    // Memory Limit Exceeded
    bool checkCircuit(int index, vector<int> gas, vector<int> cost){
        if(gas[index] < cost[index]) return false;
        int nextIndex = (index+1)%len;
        if(nextIndex == callIndex) return true;
        gas[nextIndex] = gas[index] - cost[index] + gas[nextIndex];
        return checkCircuit(nextIndex, gas, cost); 
    }

    // Time Limit Exceeded
    bool checkCircuit(int index, vector<int> gas, vector<int> cost){
        while(gas[index] >= cost[index]){
            int nextIndex = (index+1)%len;
            if(nextIndex == callIndex) return true;
            gas[nextIndex] = gas[index] - cost[index] + gas[nextIndex];
            index = nextIndex;
        }
        return false;
    }
};

// Optimized solution
/*
index = [0] [1] [2] [3] [4]
gas   = [1,  2,  3,  4,  5] 
cost  = [3,  4,  5,  1,  2]
+ To jump to the next station, at each current station needs to have the current_gas[i] = gas[i] - cost[i] >= 0

+ For any station that can be jumped, start calculating the totalCurrentGas to see if it can jump to the next
Example at index 3, currentGas = 4 - 1 = 3 >= 0, so can be jumped to 4, so at 4, need to check if it can continue
jumping to 0, check currentGas = 3 + 5 - 2 = 6 => can jump to 0, and so on. In case, it can jump:
[3] -> [4] -> [0] -> [1] but not [1] - > [2], we can know that any position from 3 -> 1 could not be jumped as well
and need to restart at [2]. Why? just imagine that:
a[3] + a[4] + a[0] >= 0 since car can jumped means the totalCurrentGas must be >= 0. However, since can not jump 1 -> 2
means a[3] + a[4] + a[0] + a[1] < 0

Explain 1:
==> a[1] must be negative => could not jump from 1
==> a[4] + a[0] + a[1] must be < 0 since a[3] >= 0(starting from 3 mean a[3] >= 0) => could not jump from 4
==> a[0] + a[1]: check below:
a[4] + a[0] + a[1] < 0 (1)
a[1] < 0 (2)
=> if a[4] > 0 => a[0] + a[1] must be < 0 because of (1)
=> if a[4] < 0 => a[0] + a[1] must be < 0 because of (2)
==> could not jump at [0]
==> only can jump at 2

Explain 2:
a[3] + a[4] + a[0] + a[1] < 0 <=> a[1] is really big negative => even a[4] or a[0] or a[1] is > 0, then
a[4] + a[0] + a[1] < 0 => could not jump from 4
a[0] + a[1] < 0 => could not jump from 0
a[1] < 0 => could not jump from 1
=> must restart at 2

+ To go back to the origin station, for example to back to the index 3, we gonna calculate
result = gas[3] - cost[3] + gas[4] - cost[4] + gas[0] - cost[0] + gas[1] - cost[1] + gas[2] - cost[2] =
(gas[0] + gas[1] + gas[2] + gas[3] + gas[4]) - (cost[0] + cost[1] + cost[2] + cost[3] + cost[4]) =
totalGas - totalCost
so if it want to go back to index 3, result >= 0 <=> totalGas >= totalCost

based on above explanation, we briefly have:
+ totalGas >= totalCost
+ can only start at station that gas[i] >= cost[i]
+ calculatiing the totalCurrentGas to see if car can jump to next station
If not, re-start jumping at the next station.
*/
class Solution {
public:
    int len;
    int totalGas;
    int totalCost;
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        len = gas.size();
        for(int i = 0; i < len; i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalGas < totalCost) return -1;

        int currentGas = 0;
        int pos = 0;
        for(int i = 0; i < len; i++){
            currentGas += gas[i] - cost[i];
            if(currentGas < 0){ // current pos could not be moved, go to next pos
                pos = i+1;
                currentGas = 0;
            } else {
              // start continuing calculate the total currentGas before moving next pos
              // line 54
            }
        }
        return currentGas < 0 ? -1 : pos;
    }
};
