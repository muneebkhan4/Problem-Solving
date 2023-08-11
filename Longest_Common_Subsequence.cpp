class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        // Create a 2D DP table to store the lengths of common subsequences
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // Populate the DP table based on the characters in the strings
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    // If the characters match, extend the common subsequence
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If the characters don't match, take the maximum of the two previous states
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // The value in the bottom-right cell of the DP table represents the longest common subsequence
        return dp[m][n];
    }
};
