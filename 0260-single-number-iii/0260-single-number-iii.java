class Solution {
    public int[] singleNumber(int[] nums) {
        int[] res = new int[2];
        Set<Integer> set = new HashSet<>();

        for(int i=0;i<nums.length;i++){
            if(set.contains(nums[i])) set.remove(nums[i]);
            else set.add(nums[i]);
        }

        int count = 0;
        for(int x:set){
            res[count++] = x;
            if(count == 2) break;
        }
        return res;
    }
}