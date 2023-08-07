
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp(1 << n, -1);
        return dfs(0, 0, nums1, nums2, dp);
    }

    int dfs(int i, int mask, vector<int>& nums1, vector<int>& nums2, vector<int>& dp) {
        int n = nums1.size();
        if (i == n) {
            return 0;
        }

        if (dp[mask] != -1) {
            return dp[mask];
        }

        int min_xor = numeric_limits<int>::max();
        for (int j = 0; j < n; j++) {
            if ((mask & (1 << j)) == 0) {
                int xor_sum = (nums1[i] ^ nums2[j]) + dfs(i + 1, mask | (1 << j), nums1, nums2, dp);
                min_xor = min(min_xor, xor_sum);
            }
        }

        dp[mask] = min_xor;
        return min_xor;
    }
};
