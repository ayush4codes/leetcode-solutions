class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,0);
        for (int i = 0;i<n;i++) {
            if (color[i] == 0) {
                color[i] = 1;
                if (!bipartiteBatao(graph,i,color)) return false;
            }
        }
        return true;
    }
    bool bipartiteBatao(vector<vector<int>> &adj,int node,vector<int> &color) {
        int curr = color[node];
        for (int next : adj[node]) {
            if (color[next] != 0) {
                if (curr == color[next]) return false;
            } else {
                color[next] = -1*curr;
                bool check = bipartiteBatao(adj,next,color);
                if (!check) return false; 
            }
        }
        return true;
    }
};