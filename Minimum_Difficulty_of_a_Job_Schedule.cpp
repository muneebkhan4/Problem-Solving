class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1; // If there are more days than jobs, no valid schedule exists

        // Initialize a 2D DP array with dimensions (d+1) x (n+1)
        // dp[day][job] represents the minimum difficulty for scheduling 'day' jobs out of the first 'job' jobs
        vector<vector<long long>> dp(d + 1, vector<long long>(n + 1, INT_MAX));
        dp[0][0] = 0; // Base case: Zero difficulty for zero jobs

        // Loop through each day
        for (int day = 1; day <= d; ++day) {
            // Loop through each job
            for (int job = 1; job <= n; ++job) {
                long long maxDifficulty = 0; // Initialize the maximum difficulty for the current scenario
                // Loop through the previous jobs to find the optimal difficulty
                for (int k = job; k >= day; --k) {
                    maxDifficulty = max(maxDifficulty, (long long)jobDifficulty[k - 1]);
                    // Calculate the minimum difficulty for the current day and job combination
                    dp[day][job] = min(dp[day][job], dp[day - 1][k - 1] + maxDifficulty);
                }
            }
        }

        // The final result is stored in dp[d][n], representing the minimum difficulty of scheduling 'd' jobs out of 'n' total jobs
        return dp[d][n];
    }
};
