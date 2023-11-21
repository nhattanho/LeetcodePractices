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
        return pos;
    }
};
