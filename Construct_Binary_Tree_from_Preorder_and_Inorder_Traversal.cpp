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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                              vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // The first element of the preorder is the root
        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);

        // Find the index of the root in the inorder
        int rootIndex = inStart;
        while (inorder[rootIndex] != rootValue) {
            rootIndex++;
        }

        // Build left and right subtrees recursively
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + (rootIndex - inStart),
                                     inorder, inStart, rootIndex - 1);
        root->right = buildTreeHelper(preorder, preStart + (rootIndex - inStart) + 1, preEnd,
                                      inorder, rootIndex + 1, inEnd);

        return root;
    }
};
