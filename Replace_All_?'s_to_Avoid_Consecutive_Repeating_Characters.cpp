class Solution {
public:
    string modifyString(string s) {
        int n = s.length();
        char lastUsedChar = '\0'; // Initialize with an invalid character

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                char newChar = 'a';
                while (newChar == lastUsedChar || (i < n - 1 && newChar == s[i + 1])) {
                    newChar++;
                }

                s[i] = newChar;
                lastUsedChar = newChar;
            } else {
                lastUsedChar = s[i];
            }
        }

        return s;
    }
};
