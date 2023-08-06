class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> dp = {0}; // Initialize dp with empty string

        for (const string& s : arr) {
            int mask = 0;
            bool hasDuplicate = false;
            
            // Check if the current string contains duplicate characters
            for (char ch : s) {
                int bit = 1 << (ch - 'a');
                if ((mask & bit) != 0) {
                    hasDuplicate = true;
                    break;
                }
                mask |= bit;
            }

            // If the current string contains duplicate characters, skip it
            if (hasDuplicate)
                continue;

            // Add the current string to all valid subsequences in dp
            for (int i = dp.size() - 1; i >= 0; --i) {
                if ((dp[i] & mask) == 0) {
                    dp.push_back(dp[i] | mask);
                }
            }
        }

        // Find the maximum length of the valid subsequences
        int maxLength = 0;
        for (int subseq : dp) {
            int length = __builtin_popcount(subseq); // Count the number of set bits in subseq
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};
