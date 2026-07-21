class Solution {
    public int findMin(int[] nums) {
        int mini=nums[0];
        for(int i=0;i<nums.length;i++){
            if(mini>nums[i]){
                mini=nums[i];
            }
        }
        return mini;
    }
}