class Solution {
    public void addList(List<List<Integer>>res, int start, int k, List<Integer>l, int n){
        if(k == 0) {
            res.add(new ArrayList<>(l));
            return;
        }
        for(int i = start; i <= n; i++){
            l.add(i);
            addList(res, i+1, k-1, l, n);
            l.remove(l.size()-1);
        }
    }
    
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>>res = new ArrayList<>();
        for(int i = 1; i <= n-k+1; i++){
            List<Integer>l = new ArrayList<>();
            l.add(i);
            addList(res, i+1, k-1, l, n);
        }
        return res;
    }
}
