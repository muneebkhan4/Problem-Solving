class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        // Iterate through the array
        for (int i = 0; i < nums.size(); i++) {
            // Check if the absolute difference between the value at index i and i is greater than 1
            // If the difference is greater than 1, it indicates a global inversion that cannot be a local inversion
            if (abs(nums[i] - i) > 1) {
                return false; // Return false as the number of global inversions is not equal to the number of local inversions
            }
        }
        // If no such cases are found, the number of global inversions is equal to the number of local inversions
        return true; // Return true
    }
};
