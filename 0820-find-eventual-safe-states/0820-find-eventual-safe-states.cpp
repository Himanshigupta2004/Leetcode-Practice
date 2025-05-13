class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
           int n = graph.size();
        vector<vector<int>> revAdj(n); 
        vector<int> indegree(n, 0); 
        for (int u = 0; u < n; ++u) {
            for (int v : graph[u]) {
                revAdj[v].push_back(u);
                indegree[u]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:revAdj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    // ans.push_back(it);
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};