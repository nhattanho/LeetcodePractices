/* Following the requirements, we need to remove the k elements in the given string in order to
make the smallest number ==> Firstly, we need to focus on how to remove elements to make the
smaller number. So, to make it, we have to remove the right greater element. For ex: 
19239, assume we delete 1 digit, then 1239(removing the second digit) < 1923 (removing the last once)
Besides, for 9288679, because 9>2==> remove 9, having 288679, 2<8, still keep 2, 8<=8 ==> keep 8,
8>6 ==> remove 8, 28679, we continue comparing 6 with the previous numbers of it ==> 8>6
and 2<6 ==> 2679. Now, 6<7 and 7<9, so we finish the comparation as the first step. The next steps
is described in the code. */

class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length();
        if(k >= len) return "0";
        if(k == 0) return num;
        string temp; // Can use stack instead of using temp string
        for(int i = 0; i < num.length(); i++){
            while(!temp.empty() && temp.back() > num[i] && k > 0){
                temp.pop_back();
                k--;
            }
            temp+=num[i];
        }
        /* the element numbers in string are in order now, and k is still > 0, so
        we just need to pop_back, like 1579 ==> minimum will be 157, 15, or 1 */
        while(k>0){
            temp.pop_back();
            k--;
        }
        int count = 0;
        // remove all 0s in front of the string, like 0000235
        for(int  i = 0; i < temp.length(); i ++){
            if(temp[i] == '0'){
                count++;
                if(count == temp.length()) return "0"; // in case, temp = "0000..0"
            }
            else break; // with "000123" ==> break with 123
        }
        temp = temp.substr(count, temp.length()-count);
        return temp == ""?"0":temp; 
    }
};
