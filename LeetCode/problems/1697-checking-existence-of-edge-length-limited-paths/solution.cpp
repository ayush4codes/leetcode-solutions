class Solution {
    vector<int> parent;
    vector<int> size;
public:
    vector<bool> distanceLimitedPathsExist(int V, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        size.resize(V,1);
        for (int i = 0;i<V;i++) parent.push_back(i);

        int n = queries.size();
        vector<bool> answer(n);
        sort(edges.begin(),edges.end(),[](auto &a,auto &b){
            return a[2] < b[2];
        });

        vector<vector<int>> queries2;
        for (int i = 0;i<queries.size();i++) {
            int u = queries[i][0], v = queries[i][1], limit = queries[i][2];
            queries2.push_back({i,limit,u,v});
        }

        sort(queries2.begin(),queries2.end(),[](auto &a,auto &b){
            return a[1] < b[1];
        });

        int edgei = 0;
        for (auto q : queries2) {
            int ogid = q[0], limit = q[1] , u = q[2], v = q[3];

            while (edgei < edges.size() && edges[edgei][2] < limit) {
                int nu = edges[edgei][0], nv = edges[edgei][1], w = edges[edgei][2];
                Union(nu,nv);
                edgei++;
            }

            if (find(u) == find(v)) answer[ogid] = true;
            else answer[ogid] = false;
        }
        return answer;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }
};