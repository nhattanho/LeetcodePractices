/*Naive solution with time complexity O(n^2), but space O(1)

0----------------------------------------------------30
0------------------------------------------------29                                   ==> need 1 more room
      5--------------10                                                               ==> need 1 more room
           8-----------------14                                                       ==> need 1 more room
                         12---------------18                                          ==> has 1 free room at [5-10] ==> no need more room
                                 16------------28                                     ==> has 1 free room at [8-14], not two because [5-10] was replaced by [12-18] ==> no need more room
                                                      30-------------------35         ==> all previous room are available ==> no need more room
 */
 
 class Solution { 
public:
    int minMeetingRooms(vector<vector<int>>& inter) {
        int len = inter.size();
        if(len == 0) return 0;
        int count = 0, res = 1;
        sort(inter.begin(), inter.end(), [](
            vector<int>v1, vector<int>v2) -> bool {
                return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
            }
        );
        
        for(int i = 0; i < len; i++){
            count++;
            for(int j = 0; j < i; j++){
                
                int start = inter[j][0];
                int end = inter[j][1];
                
                if(start == -1 && end == -1) continue;
                if(inter[i][0]>= end){ 
                    
                    // the room has already filled or replaced by the current room at position i
                    start = -1;
                    end = -1;
                    
                    count--; 
                    break;
                }
            }
        }
        return count;
    }
};

/*Reducing time complexity to O(nlogn), space 0(n)*/
class Solution { 
public:
    int minMeetingRooms(vector<vector<int>>& inter) {
        int room = 0, sum = 0;
        map<int, int>interval;
        for(auto x: inter){ // N times
            interval[x[0]]++; //logN
            interval[x[1]]--;
        }
        for(auto x: interval){
            sum += x.second;
            room = max(room, sum);
        }
        return room;
    }
};

/* The other way */
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> checkTime; // priority queue with the top is the smallest number
        int maxRooms = 0;
        
        sort(intervals.begin(),intervals.end(),[](auto& i1,auto& i2){return i1[0]<i2[0];});
        for (int i = 0; i < intervals.size(); ++i) {
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];
            // Remove meetings that have concluded
            while (checkTime.size() && checkTime.top() <= curStart) // we have at least one room available like 0-------------9 and 12---------------30, and 12 >= 9 ==> we don't need to add 1 more room
                checkTime.pop();
            // Add our meeting and see how many rooms are in use
            checkTime.push(curEnd); // adding for updating the top of priority queue
            maxRooms = max(maxRooms, checkTime.size());
        }
        
        return maxRooms;
    }
};
