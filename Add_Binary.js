/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function(a, b) {
    const result = []; // Use an array to store the binary sum
    let carry = 0; // Initialize the carry to 0
    
    // Start from the last digit of both binary strings and move towards the first digit
    let i = a.length - 1, j = b.length - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        // Get the current digits of 'a' and 'b'. If a digit doesn't exist, consider it as 0.
        const digitA = i >= 0 ? parseInt(a[i]) : 0;
        const digitB = j >= 0 ? parseInt(b[j]) : 0;
        
        // Calculate the sum of the current digits and the carry from the previous operation
        const sum = digitA + digitB + carry;
        
        // The current digit of the result is the sum modulo 2 (0 or 1)
        result.unshift(sum % 2); // Insert the sum at the beginning of the result array
        
        // Update the carry for the next iteration. It's 1 if the sum is greater than or equal to 2, else 0.
        carry = sum >= 2 ? 1 : 0;
        
        // Move to the next digits of 'a' and 'b'
        i--;
        j--;
    }
    
    // Convert the result array back to a binary string
    return result.join('');
};
