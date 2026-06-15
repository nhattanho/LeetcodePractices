/*Brute force, Time Complexity O(n^3) Space O(1) */
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size();
        if(len < 3) return 0;
        int count = 0;
        for(int i = 0; i < len; i++){
            for(int j = i+1; j < len; j++){
                for(int k = j+1; k < len; k++){
                    if( (rating[i] > rating[j] && rating[j] > rating[k]) || (rating[i] < rating[j] && rating[j] < rating[k]) )
                        count++;
                }
            }
        }
        return count;
    }
};

/*Using math to solve, Time Complexity O(n^2) Space O(1)*/
/*Example: 2 8 5 6 7 3  ==> at rating[2] = 5, we can see:
+ 1 number on the left (2) is less than 5
+ 2 number on the right (6, 7) is greater than 5
so for increasing order, we have 1*2 = 2 solution (2, 5, 6) and (2, 5, 7)
Doing the same idea for decreasing order, we came up with this solution*/
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size();
        if(len < 3) return 0;
        int lessLeft, greaterLeft, lessRight, greaterRight;
        int ans = 0;
        for(int i = 0; i < len; i++){
            lessLeft = 0, greaterLeft = 0, lessRight = 0, greaterRight = 0;
            for(int j = 0; j < len; j++){
                if(rating[i] > rating[j]){
                    if(i > j) lessRight++;
                    else lessLeft++;
                } 
                else if (rating[i] < rating[j]){
                    if(i > j) greaterRight++;
                    else greaterLeft++;
                }
            }
            ans+= lessLeft*greaterRight + greaterLeft*lessRight;
        }
        return ans;
    }
};

/*Using DP, Time Complexity O(n^2) Space O(n)*/
/*Example: 2 8 5 6 7 3  ==> at rating[0] = 2, we can see:
because 2 < 8, so we can only find increasing triplets in this cass
==> Among the rest numbers on the right side of 8, the numbers are greater
8 will make a increasing triplets <==> how many number greater than 8 exist,
how many the increasing triplets we will have.
However, we don't have any number on the right side are less than 8 ==> result = 0
Going to next comparison between 2 < 5, there are 2 numbers greater than 5
==> there are two increasing triplets. 2 5 7 and 2 5 7*/
class Solution {
public:
    int numTeams(vector<int>& rating) {
        int len = rating.size();
        if(len < 3) return 0;
        vector<int>greater(len,0), less(len,0);
        int ans = 0;
        for(int i = 0;  i < len; i++){
            for(int j = i+1; j < len; j++){
                //number of elements on the right are less than element at i
                if(rating[i] > rating[j]) less[i]++;
                //number of elements on the right are greater than element at i
                else if(rating[i] < rating[j]) greater[i]++;
            }
        }
        //Using DP table above to count the total results
        for(int i = 0;  i < len; i++){
            for(int j = i+1; j < len; j++){
                if(rating[i] > rating[j]) ans += less[j];
                else if(rating[i] < rating[j]) ans += greater[j];
            }
        }
        return ans;
    }
};
