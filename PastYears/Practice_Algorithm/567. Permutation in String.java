class Solution {
    public boolean isEquals(Map<Character, Integer>m, StringBuilder s3){
        Map<Character, Integer>newMap = new HashMap<>(m);
        for(int i = 0; i < s3.length(); i++){
            Character tmp = s3.charAt(i);
            newMap.put(tmp, newMap.getOrDefault(tmp, 0)-1);
            if(newMap.get(tmp) < 0) return false;
        }
        return true;
    }
    
    public boolean checkInclusion(String s1, String s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        
        if(l1 > l2) return false;
        
        Map<Character, Integer>m = new HashMap();
        for(int i = 0; i < l1; i++){
            Character tmp = s1.charAt(i);
            m.put(tmp, m.getOrDefault(tmp, 0)+1);
        }
        
        for(int i = 0; i <= l2-l1; i++){
            Character tmp = s2.charAt(i);
            if(m.containsKey(tmp)){
                StringBuilder s3 = new StringBuilder();
                for(int j = i; j < i+l1; j++){
                    s3.append(s2.charAt(j));
                }
                if(isEquals(m, s3)) return true;
            }
        }
        return false;
    }
}

class Solution {
    public boolean isEquals(Map<Character, Integer>m1, Map<Character, Integer>m2){
        for(Character key : m1.keySet()){
            Integer subtract = m1.get(key) - m2.getOrDefault(key, 0);
            if (subtract != 0) return false;
        }
        return true;
    }
    
    public boolean checkInclusion(String s1, String s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        
        if(l1 > l2) return false;
        
        Map<Character, Integer>m1 = new HashMap();
        Map<Character, Integer>m2 = new HashMap();
        
        for(int i = 0; i < l1; i++){
            Character tmp1 = s1.charAt(i);
            Character tmp2 = s2.charAt(i);
            m1.put(tmp1, m1.getOrDefault(tmp1, 0)+1);
            m2.put(tmp2, m2.getOrDefault(tmp2, 0)+1);
        }
        
        for(int i = 0; i < l2-l1+1; i++){
            if(isEquals(m1,m2)) return true;
            if(i == l2-l1) return false;
            m2.put(s2.charAt(i+l1), m2.getOrDefault(s2.charAt(i+l1),0)+1);
            m2.put(s2.charAt(i), m2.getOrDefault(s2.charAt(i), 0) - 1);
        }  
        return false;
    }
}

class Solution {
    public boolean isEquals(int[] arr1, int[] arr2){
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]) return false;
        }
        return true;
    }
    
    public boolean checkInclusion(String s1, String s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        
        if(l1 > l2) return false;
        
        int[] arr1 = new int[26];
        int[] arr2 = new int[26];
        
        for(int i = 0; i<l1; i++){
            arr1[s1.charAt(i)-'a']++;
            arr2[s2.charAt(i)-'a']++;
        }
        
        for(int i = 0; i<l2-l1+1; i++){
            if(isEquals(arr1, arr2)) return true;
            if(i == l2-l1) return false;
            arr2[s2.charAt(i)-'a']--;
            arr2[s2.charAt(i+l1)-'a']++;
        }
        return false;
    }
}
