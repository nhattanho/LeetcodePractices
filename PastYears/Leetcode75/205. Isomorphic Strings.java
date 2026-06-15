class Solution {
    public boolean isIsomorphic(String s, String t) {
        int l1 = s.length();
        Map<Character, Character> m = new HashMap<>();
        Map<Character, Character> m1 = new HashMap<>();
        for(int i = 0; i<l1; i++){
            Character k = s.charAt(i);
            if(!m.containsKey(k)){
                Character t1 = t.charAt(i);
                if(!m1.containsKey(t1)) {
                    m.put(k, t1);
                    m1.put(t1, k);
                }
                else {
                    Character keyof = m1.get(t1);
                     if(keyof != k) return false;
                }
            }else if (m.get(k) != t.charAt(i)) {
                return false;
            }
        }
        return true;
    }
}

class Solution {
    public boolean isIsomorphic(String s, String t) {
        int[] m1 = new int[256];
        int[] m2 = new int[256];
        Arrays.fill(m1, -1);
        Arrays.fill(m2, -1);
        for(int i = 0; i < s.length(); i++){
            Character s1 = s.charAt(i);
            Character t1 = t.charAt(i);
            if(m1[s1] == -1 && m2[t1] == -1) {
                m1[s1] = t1;
                m2[t1] = s1;
            }
            else if(m1[s1] == -1 && m2[t1] != -1) return false;
            else if (m1[s1] != -1 && m1[s1] != t1) return false;
        }
        return true;
    }
}
