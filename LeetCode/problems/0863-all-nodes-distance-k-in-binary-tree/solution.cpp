class Solution {
    unordered_map<TreeNode*,TreeNode*> parent;
    vector<int> answer;
    int k;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->k = k;
        dfs(root,nullptr);
        dfs(target,nullptr,0);
        return answer;
    }
    void dfs(TreeNode* root,TreeNode* path,int dis) {
        if(root == nullptr) return;
        if (dis == k) {
            answer.push_back(root->val);
            return;
        }
        if (root->left != path) dfs(root->left,root,dis+1);
        if (root->right != path) dfs(root->right,root,dis+1);
        if (parent[root] != path) dfs(parent[root],root,dis+1);
    }
    void dfs(TreeNode* root,TreeNode* p) {
        if (root == nullptr) return;
        parent[root] = p;
        dfs(root->left,root);
        dfs(root->right,root);
    }
};