class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        // Change all negative numbers to their nearest positive multiples of value
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                nums[i] += ((abs(nums[i]) / value) * value); // Adjust to the nearest positive multiple
                if (nums[i] < 0) nums[i] += value; // Ensure the number becomes positive
            }
        }

        // Create an array to store frequencies of remainders
        vector<int> freq(value, 0);

        // Store the frequencies of all the remainders
        for (auto& num : nums) {
            freq[num % value]++;
        }

        int n = nums.size() / value + 1; // Estimate the possible number of remainders

        // Iterate through frequencies and find the remainder that is missing
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < value; i++) {
                if (freq[i] == j) {
                    return value * j + i; // Return the MEX value
                }
            }
        }

        return 0; // Return 0 if no valid MEX is found
    }
};
