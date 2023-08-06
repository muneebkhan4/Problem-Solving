#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> uniqueIntegers;
        int n = word.length();
        int i = 0;
        bool onlyZeros = false;

        while (i < n) {
            // Skip non-digit characters
            while (i < n && !isdigit(word[i])) {
                i++;
            }

            // Process the digits
            if (i < n) {
                int start = i;
                while (i < n && isdigit(word[i])) {
                    i++;
                }
                string num = word.substr(start, i - start);
                removeLeadingZeros(num);
                if (!num.empty()) {
                    uniqueIntegers.insert(num);
                }
                else if(!onlyZeros){
                    uniqueIntegers.insert("0");
                    onlyZeros = true;
                }
            }
        }

        return uniqueIntegers.size();
    }

private:
    // Remove leading zeros from the string
    void removeLeadingZeros(string& num) {
        int i = 0;
        while (i < num.length() && num[i] == '0') {
            ++i;
        }
        num = num.substr(i);
    }
};
