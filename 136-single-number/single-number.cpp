class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int xorr = 0;

        // XOR all elements. Duplicates cancel out, leaving the single element.
        for (int i = 0; i < n; i++) {
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};