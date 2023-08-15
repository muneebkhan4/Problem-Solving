/**
 * @param {number[]} nums - An array of integers representing the numbers on the chalkboard.
 * @return {boolean} - Returns true if Alice wins, otherwise false.
 */
var xorGame = function(nums) {
    // If the number of elements is even, Alice wins immediately.
    // She can always remove elements to keep the number of elements even.
    if (nums.length % 2 === 0) {
        return true;
    }
    
    // Calculate the XOR of all elements in the array.
    // This will help us determine if the XOR sum of all elements can become 0.
    const xorSum = nums.reduce((acc, num) => acc ^ num, 0);
    
    // If the XOR sum is already 0, Alice wins immediately.
    // This is because Alice can just remove any element, making the sum 0.
    if (xorSum === 0) {
        return true;
    }
    
    // If neither of the above conditions is met, it means that Alice's optimal strategy
    // would be mirrored by Bob, and Bob wins.
    return false;
};
