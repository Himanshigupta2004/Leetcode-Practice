class Solution {
public:
    void bfs(vector<vector<char>>& grid,vector<vector<int>>& vis,int i,int j){
        int n=grid.size();
        int m=grid[0].size();
        vis[i][j]=1;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            for(auto it:dir){
                int rows=row+it.first;
                int cols=col+it.second;
                if(rows>=0 && cols>=0 && rows<n && cols<m && grid[rows][cols]=='1' && !vis[rows][cols]){
                    vis[rows][cols]=1;
                    q.push({rows,cols});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return cnt;
    }
};