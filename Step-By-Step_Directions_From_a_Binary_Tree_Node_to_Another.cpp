/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode *root, int x, string &str) {
        if (root->val == x) return true;
        //If node exists in left subtree, then we would get the true from left
        //hence we need to go to left subtree from the current root node
        if (root->left && getPath(root->left, x, str))  str += 'L';
        else if (root->right && getPath(root->right, x, str))   str += 'R';
        return str.size() > 0;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s, d;
        getPath(root, startValue, s);
        getPath(root, destValue, d);
        //since the paths are stored in reverse order
        //we know that for a common ancestor to exist
        //there will be some common path between the two string
        while(min(s.size(), d.size()) > 0 && s.back() == d.back()) {
            s.pop_back();
            d.pop_back();
        }
        return string(s.size(), 'U') + string(rbegin(d), rend(d));
    }
};
