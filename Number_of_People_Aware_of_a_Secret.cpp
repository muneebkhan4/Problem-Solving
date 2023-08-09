static const int MOD = 1e9 + 7;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n + 1, 0); // Stores the number of people aware of the secret up to day i
        
        dp[0] = 0; // No one is aware initially
        
        for (int i = 1; i <= n; ++i) {
            long result = 1; // Current contribution of 1 person who knows the secret
            
            for (int j = delay; j < forget; ++j) {
                if (i - j >= 0) {
                    // Increment the result by the number of people who found out after forwarding
                    result = (result + dp[i - j]) % MOD;
                }
            }
            
            dp[i] = result;
        }
        
        // Subtract the number of people who found out before `n - forget` day as observed
        long answer = (dp[n] - dp[max(0, n - forget)] + MOD) % MOD;
        
        return static_cast<int>(answer);
    }
};
