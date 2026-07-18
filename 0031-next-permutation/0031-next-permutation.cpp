class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return;
        int l = n - 2;
        int r;
        bool flag = false;
        while (l >= 0) {
            r = n - 1;
            while (r > l) {
                if (nums[r] > nums[l]) {
                    swap(nums[r], nums[l]);
                    flag = true;
                    break;
                }
                r--;
            }
            if (flag) break;
            l--;
        }
        l++;
        r = n - 1;
        while (l < r) {
            if (nums[r] < nums[l]) swap(nums[r], nums[l]);
            r--;
            l++;
        }
        return;
    }
};