/* https://app.codesignal.com/arcade/intro/level-2/2mxbGwLzvkTCKAJMG */
/* Time complexity O(n), space O(1) */
// https://www.anycodings.com/1questions/1999090/almost-increasing-sequence-java

bool almostIncreasingSequence(std::vector<int> se) {
    int len = se.size();
    int flag = 0, dec = 0;
    int l = 0, r = 1;
    while(r < len){
        if(se[l] < se[r]){
            r++;
            l = r - 1;
            flag = 0;     
        }else{ 
            l--;
            if(l < 0){ // 10 1 3 5 6 8
                r++;
                l = r - 1;
            }else {
                if(se[l] < se[r]){ // 1 3 5 4 5 6
                    r++;
                    l = r - 1;    
                }
                else if (se[l] >= se[r]){ // 1 3 5 2 5 6 or 1 3 5 3 6
                    r++;
                    l++;
                }
            }
            dec++;
            if (dec > 1) return false;
        }
    }
    return true;
}


bool solution(vector<int> s) {
    int left = 0;
    int count = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[left] < s[i])
            left = i;
        else{
            /*If count > 1, we know it must not be followed the requirement
            Then, we just need to check case has count = 1.
            Ex1: 1  4  6  9  7  8  9  10
            Ex2: 1  4  10  11  8  9  10*/
            count++;
            if (i+1 < s.size() && s[left] >= s[i+1]){
                if(left == 0 || (left-1 >= 0&&s[left-1] < s[i])) {
                    left=i;
                }else return false;
            }
        }
    }
    if(count > 1) return false;
    return true;
}
