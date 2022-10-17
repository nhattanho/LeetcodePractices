class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer>m = new HashMap<>();
        for(int i = 0;  i < nums.length; i++){
            int remain = target - nums[i];
            if(m.containsKey(remain)){
                int pos = m.get(remain);
                return new int[]{pos, i};
            }else{
                m.put(nums[i], i);
            }
        }
        return new int[2];
    }
}
