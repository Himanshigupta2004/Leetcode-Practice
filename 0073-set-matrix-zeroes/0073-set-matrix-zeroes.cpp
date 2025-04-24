class Solution {
public:
    void solve(vector<vector<int>>& matrix,int row,int col){
        for(int i=0;i<matrix.size();i++){
            matrix[i][col]=0;
        }
        for(int j=0;j<matrix[0].size();j++){
            matrix[row][j]=0;
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> rows;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0) rows.push_back({i,j});
            }
        }
        for(auto it:rows){
            int i=it[0];
            int j=it[1];
            solve(matrix,i,j);
        }

    }
};