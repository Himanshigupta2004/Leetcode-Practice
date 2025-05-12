class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1){
                    grid[i][j]=0;
                    q.emplace(i,j);
                }
            }
        }
        vector<pair<int,int>> dir={{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            for(auto it:dir){
                int rows=row+it.first;
                int cols=col+it.second;
                if(rows>=0 && cols>=0 && rows<n && cols<m && grid[rows][cols]==1){
                    grid[rows][cols]=0;
                    q.emplace(rows,cols);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
};