/* Time complexity 0(n), Space O(n)
 * we want to reduce the parenthesis string, so if we have the left and the right parenthesis
 * consecutive like (), we can cut it. Besides, * was treated as (, ), or empty, so we can have
 * (*, or *) to reduce. Furthermore, with )(, *(, or )*, we cannot reduce. Based on that analysis,
 * if we try to reduce the ) first by using the checking of ( and ), finally, we can have some
 * main cases:
 * 1) ***)) : the * will be before the ) ==> need to check the number of * and )
 * 2) ((**** : the * will be after the ( ==> need to check the number of * and )
 * 3) ***(((( : the * stands before ( ==> always false
 * So, we need to focus on the position and number of star in the original string.
 * This approaching gives me to come up with the solution as below:*/

class Solution {
public:
    bool checkValidString(string s) {
        int len = s.length();
        stack<int>parent, star;//separte the stack for parenthesis and star existed
        for(int i = 0; i<len; i++){
            if(s[i] == '(') parent.push(i);//saving position
            if(s[i] == '*') star.push(i);
            if(s[i] == ')'){
                if(!parent.empty()) parent.pop();//try to reduce ) by using ()
                else if(!star.empty()) star.pop();//uisng *), we can still reduce
                else return false;// )) ==> always in false case
            }
        }
	//after finishing the for_loop, the string just contains the ( and *
        while(!parent.empty()&& !star.empty()){
            //comparing the position of * with parenthesis
            if(parent.top()>star.top()) return false; //like **(((
            else{ //like ((***
                parent.pop();
                star.pop();
            }
        }
        return parent.empty();
    }
};

/* Another approach reduces Space complexity to O(1)
 * Because the * was treated as (, ), or empty, so if we have the string like
 * (((***, the string can be become in 3 cases:
 * 1) (((    ==> * <=> empty, so we need to 3 more ) to reduce this string
 * 2) (((((( ==> * <=> (, so we need to 6 ) to reduce this string, and make it valid
 * 3) ((())) ==> * <=> ), need to 0 ) to reduce
 * so, if we let min is the least of number of ) needed to add to reduce the string,
 * we need subtract min to 1 when we meet the *. With the same idea, if we let max is
 * the largest number of necessary ), we need to plus max to 1 */

class Solution {
public:
    bool checkValidString(string s) {
        int len = s.length();
        int max = 0, min = 0;
        for(auto x:s){
            if(x == '('){
                max++;
                min++;
            }else if(x == ')'){
                max--;
                min--;
            }
            else if (x == '*'){
                min--;
                max++;
            }
            if(max < 0) return false;//#) > #( + #*, like (((***))))))))
	    //min < 0 means we don't need to received any ) and the current
	    //string at position we are checking has been valid already.
	    //reset min to prepare for the next checking. 
            if(min < 0) min = 0;
        }
	//if(min < 0) min = 0;//do not reset here, ex: ((***))(
        return min==0;//if min!=0, that means we need to add more than 1 ) ==> do not valid currently
    }
};
