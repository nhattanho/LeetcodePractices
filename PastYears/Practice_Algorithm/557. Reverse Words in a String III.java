class Solution {
    public void BuildString(String s, StringBuilder str, int start, int end){
        for(int i = end-1; i >= start; i--){
            str.append(s.charAt(i));
        }
        if(end != s.length()) str.append(' ');
    }
    
    public String reverseWords(String s) {
        int len = s.length();
        int start = 0, end = -1;
        StringBuilder str = new StringBuilder();;
        for(int  i =0; i < len; i++){
            if(s.charAt(i) == ' ' || i == len-1){
                start = end+1;
                end = (i==len-1)?i+1:i;
                BuildString(s, str, start, end);
            }
        }
        String res = new String(str);
        return res;
    }
}
