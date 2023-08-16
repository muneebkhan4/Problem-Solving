/**
 * @param {string} s
 * @return {number}
 */
var minFlips = (s) => {
    // Check if the input string is empty or null
    if (!s || s.length < 1) return 0;

    // Get the initial length of the string
    const initialLen = s.length;
    
    // If the initial length is odd, double the string to account for circular behavior
    if (initialLen % 2 === 1) s += s;

    // Initialize counters for even and odd comparisons, and minimum flips
    let evenCmp = 0;
    let oddCmp = 0;
    let minFlips = Infinity;
    let end = 0;
    let start = 0;

    // Loop through the string
    while (end < s.length) {
        // Compare with even position and increment counters if needed
        if (end % 2 !== Number(s[end])) evenCmp++;
        
        // Compare with odd position and increment counters if needed
        if ((end % 2 ^ 1) !== Number(s[end])) oddCmp++;

        // If the end position is beyond the initial length, adjust counters for sliding window
        if (end >= initialLen) {
            if (start % 2 !== Number(s[start])) evenCmp--;
            if ((start % 2 ^ 1) !== Number(s[start])) oddCmp--;
            start++;
        }

        // If the end position is within the valid range, update the minimum flips
        if (end >= initialLen - 1) {
            minFlips = Math.min(evenCmp, oddCmp, minFlips);
        }
        
        // Move to the next position
        end++;
    }

    // Return the minimum flips needed
    return minFlips;
};

// Test case
console.log(minFlips("01001001101")); // Output: 2
