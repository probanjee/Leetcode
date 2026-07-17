class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {

                int x = -(nums[i] + nums[j]);

                if (binary_search(nums.begin() + j + 1, nums.end(), x)) {
                    st.insert({nums[i], nums[j], x});
                }
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};