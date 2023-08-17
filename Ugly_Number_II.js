/**
 * @param {number} n - The value of n for which to find the nth ugly number.
 * @return {number} - The nth ugly number.
 */
var nthUglyNumber = function(n) {
    // Initialize an array to store the ugly numbers.
    const uglyNumbers = [1];
    
    // Initialize pointers for each prime factor (2, 3, and 5).
    let pointer2 = 0;
    let pointer3 = 0;
    let pointer5 = 0;
    
    // Calculate the next ugly number based on the existing ugly numbers.
    // Keep increasing n until we have the required number of ugly numbers.
    while (uglyNumbers.length < n) {
        const nextUgly = Math.min(
            uglyNumbers[pointer2] * 2,
            uglyNumbers[pointer3] * 3,
            uglyNumbers[pointer5] * 5
        );
        
        // Update the pointers for each prime factor based on the calculated next ugly number.
        if (nextUgly === uglyNumbers[pointer2] * 2) pointer2++;
        if (nextUgly === uglyNumbers[pointer3] * 3) pointer3++;
        if (nextUgly === uglyNumbers[pointer5] * 5) pointer5++;
        
        // Add the next ugly number to the array.
        uglyNumbers.push(nextUgly);
    }
    
    // Return the nth ugly number.
    return uglyNumbers[n - 1];
};
