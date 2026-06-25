class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) return new TreeNode(val);
        else if (root->val > val) {
            TreeNode* newLeft = insertIntoBST(root->left,val);
            root->left = newLeft;
        } else {
            TreeNode* newRight = insertIntoBST(root->right,val);
            root->right = newRight;
        }
        return root;
    }
};