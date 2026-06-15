class Solution {
    public boolean isSubsequence(String s, String t) {
        int l = 0; 
        if(s.length() > t.length()) return false;
        if(s.length() == 0) return true;
        for(int i = 0; i < t.length(); i++){
            if(t.charAt(i) == s.charAt(l)){
                l++;
                if(l == s.length()) return true;
            }
        }
        return l==s.length()?true:false;
    }
}
