class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subsets = 1 << n;
        vector<vector<int>> ans;
        for (int num = 0; num < subsets; num++) {
            // Temporary vector to hold the current subset
            vector<int> subset;

            // Iterate through each bit of the number
            for (int i = 0; i < n; i++) {
                // If the ith bit is set, include nums[i] in the subset
                if (num & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }

            // Add the constructed subset into the result
            ans.push_back(subset);
        }

        // Return all subsets
        return ans;

 
    }
};