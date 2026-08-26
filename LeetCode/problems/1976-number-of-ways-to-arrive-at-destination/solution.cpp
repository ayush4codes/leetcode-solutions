#define ll long long
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n,vector<int>());
        int mod = 1e9+7;
        for (auto edge : roads) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].push_back(v); adj[u].push_back(t);
            adj[v].push_back(u); adj[v].push_back(t);
        }
        vector<ll> ways(n,0);
        ways[0] = 1;
        priority_queue<pair<ll,int>,
               vector<pair<ll,int>>,
               greater<>> pq;
        pq.push({0LL,0});
        vector<ll> dis(n,1e18);
        dis[0] = 0;
        while (pq.size() != 0) {
            auto [time,node] = pq.top(); pq.pop();
            if (time > dis[node]) continue;
            for (int i = 0;i<adj[node].size();i+=2) {
                int next = adj[node][i];
                int val = adj[node][i+1];
                if (dis[node] + val < dis[next]) {
                    ways[next] = ways[node]%mod;
                    dis[next] = val + dis[node];
                    pq.push({dis[next],next});
                } else if (dis[node] + val ==  dis[next]) {
                    ways[next] = (ways[next] + ways[node])%mod;   
                }
            }
        }
        return ways[n-1];
    }
};