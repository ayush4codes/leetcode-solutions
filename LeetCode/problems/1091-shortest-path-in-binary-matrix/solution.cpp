class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[] = {0,0,1,-1,1,1,-1,-1};
        int dy[] = {1,-1,0,0,1,-1,1,-1};
        queue<tuple<int,int,int>> q;
        if(grid[0][0] == 0) q.push({0,0,1});
        int n = grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vis[0][0] = true;
        while (q.size() != 0) {
            auto [x,y,dis] = q.front(); q.pop();
            if (x == n-1 && y == n-1) {
                return dis;
            }
            for (int k = 0;k<8;k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx < 0 || nx == n || ny < 0 || ny  == n || grid[nx][ny] == 1) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = true;
                q.push({nx,ny,dis+1});
            }
        }
        return -1;
    }
};