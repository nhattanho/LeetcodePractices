class Solution {
    public int lengthOfLongestSubstring(String s) {
        int len = s.length();
        int l = 0, res = 0;
        Map<Character, Integer>m = new HashMap<>();
        for(int i = 0; i < len; i++){
            Character key = s.charAt(i);
            if(m.containsKey(key)){
                Integer pos = m.get(key);
                if(pos >= l){
                    res = Math.max(res, i-l);  
                    l = pos+1;
                }else{
                   res = Math.max(res, i-l+1); 
                }
                
            }else{
                res = Math.max(res, i-l+1);
            }
            m.put(key,i);
        }
        return res;
    }
}
