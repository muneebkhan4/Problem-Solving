class TrieNode {
public:
    // Array to represent child nodes for each character ('a' to 'z')
    TrieNode* children[26];
    // Flag to mark the end of a word
    bool isEndOfWord;

    TrieNode() {
        // Initialize all child nodes to null
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        // Initialize the root of the Trie
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        // Traverse the Trie while inserting each character
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                // If the child node doesn't exist, create it
                node->children[index] = new TrieNode();
            }
            // Move to the child node
            node = node->children[index];
        }
        // Mark the end of the word
        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        // Traverse the Trie while searching for each character
        for (char c : word) {
            int index = c - 'a';
            if (!node->children[index]) {
                // If the child node doesn't exist, the word is not in the Trie
                return false;
            }
            // Move to the child node
            node = node->children[index];
        }
        // Return true if the word exists and is marked as the end of a word
        return (node != nullptr && node->isEndOfWord);
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        // Traverse the Trie while checking for each character
        for (char c : prefix) {
            int index = c - 'a';
            if (!node->children[index]) {
                // If the child node doesn't exist, the prefix is not present
                return false;
            }
            // Move to the child node
            node = node->children[index];
        }
        // Return true if the prefix exists (no need to check for the end of the word)
        return (node != nullptr);
    }
};
