class Solution {

    boolean compareString(String s1, String s2){
        char[] s11 = s1.toCharArray();
        char[] s21 = s2.toCharArray();
        Arrays.sort(s11);
        Arrays.sort(s21);
        String tmp1 = new String(s11);
        String tmp2 = new String(s21);
        if(tmp1.equals(tmp2)) return true;
        return false;
    }

    public List<Integer> findAnagrams(String s, String p) {
        int len1 = s.length();
        int len2 = p.length();
        List<Integer> l = new LinkedList<>();
        for(int i = 0; i <= len1-len2; i++){
            String tmp = s.substring(i, i+len2);
            if(compareString(tmp, p)) l.add(i);
        }
        return l;
    }
}

class Solution {
    boolean compareString(String s1, String s2){
        Map<Character, Integer>m = new HashMap<>();
        for(int i = 0; i < s1.length(); i++){
            char tmp1 = s1.charAt(i);
            if(m.containsKey(tmp1)){
                int value = m.get(tmp1);
                value += 1;
                m.put(tmp1, value);
            }else{
                m.put(tmp1, 1);
            }
            char tmp2 = s2.charAt(i);
            if(m.containsKey(tmp2)){
                int value = m.get(tmp2);
                value -= 1;
                m.put(tmp2, value);
            }else{
                m.put(tmp2, -1);
            }
        }
        for(Character key: m.keySet()){
            if(m.get(key) != 0) return false;
        }
        return true;
    }

    public List<Integer> findAnagrams(String s, String p) {
        int len1 = s.length();
        int len2 = p.length();
        List<Integer> l = new LinkedList<>();
        for(int i = 0; i <= len1-len2; i++){
            String tmp = s.substring(i, i+len2);
            if(compareString(tmp, p)) l.add(i);
        }
        return l;
    }
}


class Solution {

    public boolean compareArray(int[] arr1, int[]arr2){
        for(int i = 0; i < arr1.length; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }

    public List<Integer> findAnagrams(String s, String p) {
        int len1 = s.length();
        int len2 = p.length();
        if(len2 > len1) return new LinkedList<>(){};

        List<Integer>l = new LinkedList<>();

        int[] arrs = new int[26];
        int[] arrp = new int[26];
        Arrays.fill(arrs, 0);
        Arrays.fill(arrp, 0);

        for(int i = 0; i < len2; i++){
            arrs[s.charAt(i)-'a']++;
            arrp[p.charAt(i)-'a']++;
        }
        if(compareArray(arrs, arrp)) l.add(0);

        for(int i = 1; i <= len1-len2; i++){
            arrs[s.charAt(i-1)-'a']--;
            arrs[s.charAt(i+len2-1)-'a']++;
            if(compareArray(arrs, arrp)) l.add(i);
        }
        return l;
    }
}
