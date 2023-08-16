/**
 * @param {number[][]} triangle - The triangle array.
 * @return {number} - Returns the minimum path sum from top to bottom.
 */
var minimumTotal = function(triangle) {
    const n = triangle.length;
    
    // Use a single array to store the minimum path sum for the current row
    // We initialize with the last row values
    const dp = [...triangle[n - 1]];
    
    // Iterate through the rows of the triangle from bottom to top
    for (let row = n - 2; row >= 0; row--) {
        for (let col = 0; col <= row; col++) {
            // Calculate the minimum path sum for cell (row, col) by choosing the smaller value
            // between the two adjacent cells in the next row and adding the value of the current cell
            dp[col] = Math.min(dp[col], dp[col + 1]) + triangle[row][col];
        }
    }
    
    return dp[0]; // Return the minimum path sum from top to bottom
};
