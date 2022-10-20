class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String>l = new ArrayList<>();
        l.add("");
        
        for(int i = 0; i < s.length(); i++){
            int size = l.size();
            for(int c = 0; c < size; c++){
                StringBuilder word1 = new StringBuilder(l.get(0));
                StringBuilder word2 = new StringBuilder(l.get(0));
                l.remove(0); //take more time
                Character ch = s.charAt(i);
                if(Character.isAlphabetic(ch)){
                    l.add(word1.append(Character.toLowerCase(ch)).toString());
                    l.add(word2.append(Character.toUpperCase(ch)).toString());
                }else{
                    l.add(word1.append(ch).toString());
                }
            }
        }
        return l;
    }
}

class Solution {
    public List<String> letterCasePermutation(String s) {
        List<String>l = new ArrayList<>();
        l.add("");
        
        for(int i = 0; i < s.length(); i++){
            int size = l.size();
            for(int c = 0; c < size; c++){
                StringBuilder word1 = new StringBuilder(l.get(c));
                StringBuilder word2 = new StringBuilder(l.get(c));
                Character ch = s.charAt(i);
                if(Character.isAlphabetic(ch)){
                    word1.append(Character.toLowerCase(ch));
                    l.set(c,word1.toString());
                    l.add(word2.append(Character.toUpperCase(ch)).toString());
                }else{
                    l.set(c,(word1.append(ch).toString()));
                }
            }
        }
        return l;
    }
}
