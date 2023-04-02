class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        //Note: The copy matrix visited can be avoided by updating the original matrix grid but changing the input 
        // parameter is not considered under good practices. That's why we are taking extra 2d matrix visited
        vector<vector<int>> visited = grid;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 1) 
                    q.push({i, j});
            }
        }
        if (q.empty() || q.size() == n * n) 
            return -1;
        int distance = -1;
        // visit all four direction i.e. right, left, up, down
        vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : dirs) {
                    int i = x + dx, j = y + dy;
                    if (i >= 0 && i < n && j >= 0 && j < n && visited[i][j] == 0) {
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
            distance++;
        }
        return distance;
    }
};


/************** DFS TLE ***************/
// class Solution {
// public:
//     void dfs(vector<vector<int>>& g, int i, int j, int dist = 1) {
//         if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size() || (g[i][j] != 0 && g[i][j] <= dist)) 
//             return;
//         g[i][j] = dist;
//         dfs(g, i - 1, j, dist + 1), dfs(g, i + 1, j, dist + 1), dfs(g, i, j - 1, dist + 1), dfs(g, i, j + 1, dist + 1);
//     }
//     int maxDistance(vector<vector<int>>& g, int mx = -1) {
//         for (auto i = 0; i < g.size(); ++i)
//             for (auto j = 0; j < g[i].size(); ++j)
//             if (g[i][j] == 1) {
//                 g[i][j] = 0;
//                 dfs(g, i, j);
//         }
//         for (auto i = 0; i < g.size(); ++i)
//             for (auto j = 0; j < g[i].size(); ++j)
//             if (g[i][j] > 1) mx = max(mx, g[i][j] - 1);
//         return mx;
//     }
// };
