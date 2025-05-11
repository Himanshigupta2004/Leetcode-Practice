class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, int>> q;
        const vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    q.emplace(i, j);
                    dist[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (const auto& [dx, dy] : directions) {
                int newRow = row + dx;
                int newCol = col + dy;
                if (newRow >= 0 && newCol >= 0 && newRow < n && newCol < m) {
                    if (dist[newRow][newCol] > dist[row][col] + 1) {
                        dist[newRow][newCol] = dist[row][col] + 1;
                        q.emplace(newRow, newCol);
                    }
                }
            }
        }

        return dist;
    }
};
