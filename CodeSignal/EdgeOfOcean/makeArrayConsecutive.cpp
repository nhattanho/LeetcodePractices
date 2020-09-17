/* https://app.codesignal.com/arcade/intro/level-2/bq2XnSr5kbHqpHGJC */

int makeArrayConsecutive2(std::vector<int> st) {
    int len = st.size();
    int count = 0;
    map<int,int> temp;
    for(int i = 0; i < len; i++){
        /* each number is unique, so if the frequency of current value is not equal 0
        <=> we have already increased it at line 22. However, in this process, we also
        increase the count value, so here, we need to subtract count by 1 */
        if(temp[st[i]] != 0) count--;
        else temp[st[i]]++;
        
        if(i == len-1) return count;
        
        int l = st[i];
        int r = st[i+1];
        if(st[i] < st[i+1]){
            l = st[i+1];
            r = st[i];
        }
        
        while(l > r){
            if(temp[l] == 0) {
                temp[l]++;
                count++;
            }
            l--;
        }
    }
    return count;
}
