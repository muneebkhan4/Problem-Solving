class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mpp; // Store elements based on the diagonal sum
        vector<int> ans;
        int maxCols = 0; // To keep track of the maximum number of columns
        
        // Find the maximum number of columns
        for (auto &row : nums) {
            maxCols = max(maxCols, static_cast<int>(row.size()));
        }
        
        // Traverse the 2D array and populate the mpp
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                int diagonalSum = i + j; // The sum of indices gives the diagonal value
                mpp[diagonalSum].push_back(nums[i][j]);
            }
        }
        
        // Traverse the mpp and add elements to the result
        for (int sum = 0; sum < nums.size() + maxCols - 1; ++sum) {
            int numRowsInDiagonal = mpp[sum].size();
            
            // Push elements in reverse order for even diagonals
            for (int i = (numRowsInDiagonal - 1); i >= 0; --i) {
                ans.push_back(mpp[sum][i]);
            }
        }
        
        return ans;
    }
};
