class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        long long total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total+=grid[i][j];
            }
        }

        if(total%2 !=0) return false;
        long long row=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                row+=grid[i][j];
            }
            if(row*2==total) return true;
        }

        vector<long long> col(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                col[j]+=grid[i][j];
            }
        }

        long long csum=0;
        for(int j=0;j<m-1;j++){
            csum+=col[j];
            if(csum*2==total) return true;
        }

        return false;



    }
};