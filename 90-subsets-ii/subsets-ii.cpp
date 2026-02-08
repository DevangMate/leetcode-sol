class Solution {
public:
    void findpowsetopt(int start, vector<int>& current,
                    vector<vector<int>>& result, vector<int>& arr) {
        result.push_back(current);
        for (int i = start; i < arr.size(); i++) {
            if (i > start && arr[i - 1] == arr[i])
                continue;
            current.push_back(arr[i]);
            findpowsetopt(i + 1, current, result, arr);
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findpowsetopt(0, ds, ans, nums);
        return ans;
    }
};