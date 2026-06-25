class Solution {
    vector<vector<int>> adj;
    vector<int> answer;
    int k;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        this->k = k;
        adj.resize(501,vector<int>());
        dfs(root,nullptr);
        queue<pair<int,int>> q;
        q.push({target->val,-1});
        int depth = -1;
        while (q.size()) {
            depth++;
            int size = q.size();
            for (int i = 0;i<size;i++) {
                auto [node,parent] = q.front(); 
                q.pop();
                if (depth == k) answer.push_back(node);
                for (int next : adj[node]) {
                    if (next == parent) continue;
                    q.push({next,node});
                }
            }
            if (depth == k) return answer;
        }
        return answer;
    }
    void dfs(TreeNode* root,TreeNode* parent) {
        if (root == nullptr) return;

        int u = root->val;
        if (parent != nullptr) {
            int v = parent->val;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(root->left, root);
        dfs(root->right, root);
    }
};