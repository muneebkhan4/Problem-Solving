class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int Res =0;
        for(int i=0;i<n;i++){
        int j=i+1;
        int k=n-1;
    
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                
                if(abs(sum-target) < diff)
                {
                    diff=abs(sum-target);
                    Res=sum;
                }
                
                if(sum > target) k--;
                
                else j++;
            }

        }
        return Res;
    }
};
