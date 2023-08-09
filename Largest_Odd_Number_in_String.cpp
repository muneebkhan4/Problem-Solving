class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size(); // Get the length of the input string
        for (int i = n - 1; i >= 0; --i) { // Iterate through the string from right to left
            if ((num[i] - '0') % 2 == 1) { // Check if the current digit is odd
                // If odd digit found, return the substring from the beginning up to the current index
                return num.substr(0, i + 1);
            }
        }
        // If no odd digit found, return an empty string
        return "";
    }
};
