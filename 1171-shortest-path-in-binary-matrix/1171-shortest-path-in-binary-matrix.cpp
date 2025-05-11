class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      
        int n=grid.size();
        int m=grid[0].size();
          if(grid[0][0]!=0 || grid[n-1][m-1]!=0) return -1;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{-1,-1},{1,0},{0,1},{1,1},{1,-1},{-1,1}};
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            auto [row,col]=q.front();
            q.pop();
            for(auto it:dir){
                int rows=row+it.first;
                int cols=col+it.second;
                if(rows>=0 && cols>=0 && rows<n && cols<m && grid[rows][cols]==0){
                    if(dist[rows][cols]>dist[row][col]+1){
                        dist[rows][cols]=dist[row][col]+1;
                        q.emplace(rows,cols);
                    }
                }
            }
        }
        return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1];


    }
};