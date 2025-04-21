class Solution {
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis,
             vector<vector<int>>& graph) {
        vis[node] = 1;
        pathvis[node] = 1;
        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathvis, graph) == true)
                    return true;
            } else if (pathvis[it] == 1)
                return true;
        }
        pathvis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> vec;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
               (dfs(i, vis, pathvis, graph));
            }
        }
        for(int i=0;i<n;i++){
            if(pathvis[i]==0){
                     vec.push_back(i);
            }
           
        }
        return vec;
    }
};