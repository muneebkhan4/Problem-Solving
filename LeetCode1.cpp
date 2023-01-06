class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        int size = nums.size();
    if(size==0)
        return res;

    int lo = 0, hi = size - 1;
    int mid=0;
    // This below check covers all cases , so need to check
    // for mid=lo-(hi-lo)/2
    while (hi - lo > 1) {
        int mid = (hi + lo) / 2;
        if (nums[mid] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    if( nums[lo]==target){ 
        for(int strt = lo; strt>-1 && nums[strt]==target; res[0] = strt,strt--);
        for(int end = lo; end<nums.size() && nums[end]==target; res[1] = end, end++);
    }
    else if( nums[hi]==target){
        for(int strt = hi; strt>-1 && nums[strt]==target; res[0] = strt,strt--);
        for(int end = hi; end<nums.size() && nums[end]==target; res[1] = end, end++);
    }
        return res;
    }
};
// 7 37  8 17
