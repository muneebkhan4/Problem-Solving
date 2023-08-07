class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp(1 << n, -1); // Memoization array to store the minimum XOR sum for each state (bitmask).

        // Call the recursive function with the initial state (i=0, mask=0) and return the result.
        return dfs(0, 0, nums1, nums2, dp);
    }

    int dfs(int i, int mask, vector<int>& nums1, vector<int>& nums2, vector<int>& dp) {
        int n = nums1.size();

        // Base case: If we have reached the end of the nums1 array, return 0 (no more elements to process).
        if (i == n) {
            return 0;
        }

        // Check if the result for the current state (i, mask) is already computed and stored in the dp array.
        if (dp[mask] != -1) {
            return dp[mask];
        }

        int min_xor = numeric_limits<int>::max(); // Initialize min_xor to maximum value.

        // Try all possible permutations of nums2 elements and calculate the XOR sum at each step.
        for (int j = 0; j < n; j++) {
            // Check if the jth element of nums2 is not used in the current permutation (mask bit is 0).
            if ((mask & (1 << j)) == 0) {
                int xor_sum = (nums1[i] ^ nums2[j]) + dfs(i + 1, mask | (1 << j), nums1, nums2, dp);
                // Update min_xor with the minimum XOR sum among all possible permutations.
                min_xor = min(min_xor, xor_sum);
            }
        }

        // Store the minimum XOR sum for the current state (i, mask) in the dp array.
        dp[mask] = min_xor;

        // Return the minimum XOR sum for the current state (i, mask).
        return min_xor;
    }
};
