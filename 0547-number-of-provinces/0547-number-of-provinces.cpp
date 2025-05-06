class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjlist(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                queue<int> q;
                q.push(i);
                vis[i] = 1;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto neighbours : adjlist[node]) {
                        if (!vis[neighbours]) {
                            vis[neighbours]=1;
                            q.push(neighbours);
                        }
                    }
                }
            }
        }
        return provinces;
    }
};