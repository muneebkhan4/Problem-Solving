/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
    let left = 0;
    let right = nums.length - 1;
    
    while (left < right) {
        const mid = Math.floor(left + (right - left) / 2);
        
        if (nums[mid] < nums[mid + 1]) {
            // The peak must be on the right side, move the left pointer
            left = mid + 1;
        } else {
            // The peak must be on the left side or at the mid index
            right = mid;
        }
    }
    
    // At this point, left and right point to the same index, which is a peak
    return left;
};
