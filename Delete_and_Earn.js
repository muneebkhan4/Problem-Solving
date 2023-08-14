var deleteAndEarn = function(nums) {
    // Count the frequency of each number
    const count = {};
    for (const num of nums) {
        count[num] = (count[num] || 0) + num;
    }
    
    // Find the maximum number in the input array
    const maxNum = Math.max(...nums);
    
    // Initialize dynamic programming arrays
    const dp = new Array(maxNum + 1).fill(0);
    dp[1] = count[1] || 0;
    
    // Calculate the maximum points using dynamic programming
    for (let i = 2; i <= maxNum; i++) {
        dp[i] = Math.max(dp[i - 1], (count[i] || 0) + (dp[i - 2] || 0));
    }
    
    // The final result is the last element in the dp array
    return dp[maxNum];
};
