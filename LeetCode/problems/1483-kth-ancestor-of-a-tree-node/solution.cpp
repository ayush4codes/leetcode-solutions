class TreeAncestor {
    vector<vector<int>> up;
public:
    TreeAncestor(int n, vector<int>& parent) {
        up.resize(n,vector<int>(17,0));
        for (int i = 0;i<parent.size();i++) {
            up[i][0] = parent[i];
        }

        for (int k = 1;k<=16;k++) {
            for (int i = 0;i<n;i++) {
                if (up[i][k-1] == -1) up[i][k] = -1;
                else up[i][k] = up[up[i][k-1]][k-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int id = 0;
        while (k!= 0) {
            if (k % 2  == 1) {
                node = up[node][id];
            }
            if (node == -1) return -1;
                id++;
                k /= 2;
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */