/**
 * @param {number[]} nums
 * @return {number}
 */
var reductionOperations = function(nums) {
    const freq = {};  // Object to store the frequency of each element
    let maxElement = 0;  // Max element encountered
    let operations = 0;
    
    for (const num of nums) {
        freq[num] = (freq[num] || 0) + 1;  // Count the frequency of each element
        maxElement = Math.max(maxElement, num);
    }
    
    let total = 0;  // Total count for the nextLargest value
    for (let i = maxElement; i > 0; i--) {
        if (freq[i]) {
            total += freq[i];  // Update the total count
            operations += total - freq[i];  // Add to operations count
        }
    }
    
    return operations;
};
