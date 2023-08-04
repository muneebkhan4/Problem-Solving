class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        
        // Function to count subarrays with at most k distinct elements
        auto atMostKDistinct = [&](int k) {
            vector<int> freq(n + 1, 0);
            int left = 0, distinct = 0, result = 0;
            
            for (int right = 0; right < n; ++right) {
                if (freq[nums[right]] == 0) {
                    ++distinct;
                }
                ++freq[nums[right]];
                
                while (distinct > k) {
                    --freq[nums[left]];
                    if (freq[nums[left]] == 0) {
                        --distinct;
                    }
                    ++left;
                }
                
                result += right - left + 1;
            }
            
            return result;
        };
        
        // The count of subarrays with at most k distinct elements is
        // the difference between atMostKDistinct(k) and atMostKDistinct(k - 1)
        return atMostKDistinct(k) - atMostKDistinct(k - 1);
    }
};
