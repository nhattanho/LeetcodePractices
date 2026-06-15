class Solution {
    public:
        void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
            if(n == 0) return;
            int left1 = 0;
            int left2 = 0;        
            while(left1 < m){
                if(n1[left1] > n2[left2]){
                    swap(n1[left1], n2[left2]);
                    left1++;
                    adjust(n2, left2);
                }else{
                    left1++;
                }
            }
            for(int i = m; i < m+n; i++){
                n1[i] = n2[i-m];
            }
        }

        void adjust(vector<int>& v, int pos){
            while(pos < v.size() - 1 && v[pos] > v[pos+1]){
                swap(v[pos], v[pos+1]);
                pos++;
            }
            return;
        }
};


/*Second approach with Optimization*/
class Solution {
    public:
        void merge(vector<int>& n1, int m, vector<int>& n2, int n) {
            int first = m-1;
            int second = n-1;
            int pos = m+n-1;
            while(second >= 0){
                if(first >= 0 && n1[first] > n2[second]){
                    n1[pos] = n1[first];
                    pos--;
                    first--;
                }else{
                    n1[pos] = n2[second];
                    pos--;
                    second--;
                }
            }
        }
};
