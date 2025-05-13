class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> indegree(n,vector<int>(m,0));
        vector<vector<vector<pair<int, int>>>> adjlist(n, vector<vector<pair<int, int>>>(m));
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(auto it:dir){
                    int row=i+it.first;
                    int col=j+it.second;
                    if(row>=0 && col>=0 && row<n && col<m && matrix[i][j]<matrix[row][col]){
                        adjlist[i][j].push_back({row,col});
                        indegree[row][col]++;
                    }
                }
            }
        }

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(indegree[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int ans=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto [r,c]=q.front();
                q.pop();
                for(auto it:adjlist[r][c]){
                    int ro=it.first,co=it.second;
                    indegree[ro][co]--;
                    if(indegree[ro][co]==0){
                        q.push({ro,co});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};