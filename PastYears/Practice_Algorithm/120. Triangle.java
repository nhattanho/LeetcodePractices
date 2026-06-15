class Solution {
    public int minimumTotal(List<List<Integer>> l) {
        int row = l.size();
        for(int r = row-2; r>= 0; r-- ){
            for(int c = 0; c < l.get(r).size(); c++){
                int minV = Math.min(l.get(r+1).get(c), l.get(r+1).get(c+1));
                l.get(r).set(c, l.get(r).get(c)+minV);
            }
        }
        return l.get(0).get(0);
    }
}
