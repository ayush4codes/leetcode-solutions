class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        priority_queue<tuple<int,int,int>> pq;
        int dx[4] = {0,1,-1,0};
        int dy[4] = {1,0,0,-1};
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,-1));
        dist[0][0] = grid[0][0] == 1 ? health - 1 : health;
        pq.push({dist[0][0],0,0});

        while (pq.size() != 0) {
            auto [dis,x,y] = pq.top(); pq.pop();
            if (x == n-1 && y ==m-1) {
                if (dis>=1) return true;
            }
            if (dis < dist[x][y]) continue;
            for (int k = 0;k<4;k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx <0 || nx == n || ny < 0 || ny == m) continue;

                if (dist[x][y] - grid[nx][ny] > dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] - grid[nx][ny];
                    pq.push({dist[nx][ny],nx,ny});
                }
            }
        }
        return false;
    }
};