/* https://app.codesignal.com/arcade/intro/level-2/2mxbGwLzvkTCKAJMG */
/* Time complexity O(n), space O(1) */

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
