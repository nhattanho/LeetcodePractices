/* Ultimately, the requirement is to find the sub-array having the max length and has only two types of number*/
/* The first way */
class Solution {
public:
    
    int max (int a, int b) {
        return a > b ? a : b;
    }
    
    int totalFruit(vector<int>& tree) {
        int first = 0, second = 0;
        int lastFirst = 0, lastSecond = 0;
        int firstType =-1;
        int secondType = -1;
        int count = 0, curFre = 0;
        
        
        for (int i = 0; i < tree.size(); i++) {     //[3,3,3,1,2,1,1,1,3,3,4] [1 1 1 1 1 1 1 1]
            if(tree[i] != firstType && tree[i] != secondType) {
                count++;
                //save the first type of the fruit
                if (count == 1){
                    firstType = tree[i];//3
                    lastFirst = i;
                }
                //save the second type of the fruit
                else if (count == 2){
                    secondType = tree[i];//1
                    lastSecond = i;
                }
                else {  
                    curFre = max(curFre, i-first);
                    //update the 2 new types of the fruits
                    firstType = tree[i-1];
                    secondType = tree[i];
                    
                    //Update the start and last position of the first type of the 2 new types of fruits
                    if (lastFirst > lastSecond) first = lastSecond + 1;
                    else {
                        first = lastFirst+1;
                        lastFirst = lastSecond;
                    }
                    
                    //Update the start and last position of the second type of the new 2 types of fruits
                    second = i; 
                    lastSecond = i;
                    count--;
                }
            } else if (tree[i] == firstType) lastFirst = i;//2
            else if (tree[i] == secondType) lastSecond = i;//4
        }
        curFre = max(curFre, tree.size()-first);
        return curFre;
    }
};

/* The second way */
class Solution {
public:
    int totalFruit(vector<int>& tree) {
        map<int,int> temp; //key, frequency
        vector<int> fres;
        int count = 0; // type of the fruit
        int curFre = 0;
        int left = 0;
        
        for (int i = 0; i < tree.size(); i++) {     //  0 1 2  3   4 5 6 7 8 9 10
            if (temp[tree[i]] != 0) { // [3,3,3, 1  ,2,1,1,2,3,3,4]
                temp[tree[i]]++;  
                curFre++;
            } else {
                count++; // 3
                if (count <= 2) {
                    temp[tree[i]]++;
                    curFre ++;
                }
                else {
                    fres.push_back(curFre);
                    while(temp[tree[left]] != 0){
                        temp[tree[left]]--; // temp[1] = 0 temp[2] = 1
                        curFre--;
                        // if(temp[tree[left]] == 0) {
                        //     left++;
                        //     break;
                        // }
                        left++;
                        if(temp[tree[left-1]] == 0) break;
                    } 
                    count--;
                    temp[tree[i]]++;
                    curFre++;
                }
            }
        }

        fres.push_back(curFre);
        return *max_element(fres.begin(), fres.end());
    }
};

/* The third way */
class Solution {
public:
    
    int max (int a, int b) {
        return a > b ? a : b;
    }
                                        
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int>map; 
        int left = 0;
        int maxFre = 0;
        for (int i = 0;  i < tree.size(); i++) {
            map[tree[i]]++;
            if(map.size() > 2) {
                maxFre = max(maxFre, i-left);
                while(map[tree[left]] != 0){
                    map[tree[left]]--;  
                    if(map[tree[left]] == 0){
                        map.erase(tree[left]);
                        left++;
                        break;
                    } 
                    left++;
                }
            }
        }
        maxFre = max(maxFre, tree.size()-left);
        return maxFre;
    }
};

/* Note: If we expand this problem by adding one more requirement that the sub array having maximum two type of value, and if it has 2 type of
value, the distance of two types value in the sub-array can not larger than 1.
For example:  [1 1 1 1 3 3 2 3] ==> the sub-arr having maximum 2 type of value are: [1 1 1 1], [1 1 1 1 3 3], [3 3], and [3 3 2 3]. We can see the lenght of sub-arr
[1 1 1 1 3 3] is maximum, however, the distance from 3 to 1 <=> 3-1 = 2 ==> it is not satisfied requirement ==> the max valid subarr is: [3 3 2 3] or [1 1 1 1] */
/* Time complexity O(n), the steps in the while loop should be a constant. Just check the worst case of while loop: 1 1 1 1 1 1 1 1 1 1 1 1 3 ==> from position 0 -> 11,
just take 1 step, from the postion 12, we run the while loop in 11 steps ==> the total steps = 2*11 <=> 2n ==> bigO is still O(n)
Space complexity O(n), because when we have the arr: [1 2 3 4 5 6 7 8 9] <=> the worst of space ==> create the map having 9 elements = n ==> Space: O(n) */

class Solution {
public:
    
    int max (int a, int b) {
        return a > b ? a : b;
    }
                                        
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int>map; 
        int left = 0;
        int maxFre = 0;
        for (int i = 0;  i < tree.size(); i++) {
            map[tree[i]]++;
            
            if(map.size() > 2 || ((map.size() == 2) && abs(tree[i] - tree[left]) > 1) ){
                maxFre = max(maxFre, i-left);
                while(map[tree[left]] != 0){
                    map[tree[left]]--;  
                    if(map[tree[left]] == 0){
                        map.erase(tree[left]);
                        left++;
                        break;
                    } 
                    left++;
                }
            }
            /* We can use lines below to replace for the if(map.size() > 2 || ((map.size() == 2) && abs(tree[i] - tree[left]) > 1) )*/
            // if(map.size() > 2) {
            //     maxFre = max(maxFre, i-left);
            //     while(map[tree[left]] != 0){
            //         map[tree[left]]--;  
            //         if(map[tree[left]] == 0){
            //             map.erase(tree[left]);
            //             left++;
            //             break;
            //         } 
            //         left++;
            //     }
            // }else if (map.size() == 2) {
            //     maxFre = max(maxFree, i - left);
            //     if(abs(tree[i] - tree[left]) > 1){
            //         while(true){
            //             map[tree[left]]--;
            //             if(map[tree[left]] == 0) {
            //                 map.erase(tree[left]);
            //                 left++;
            //                 break;
            //             }
            //             left++;
            //         }
            //     }
            // }
        }
        maxFre = max(maxFre, tree.size()-left);
        return maxFre;
    }
};
