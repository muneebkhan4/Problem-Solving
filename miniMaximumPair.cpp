class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int ans =INT_MIN;
        sort(nums.begin(), nums.end());
        for(int i=0, j=nums.size()-1;i<nums.size()/2;i++, j--){
            if(ans<nums[i]+nums[j])
                ans=nums[i]+nums[j];
        }
        return ans;
    }
};
// 10 57, 11 14
