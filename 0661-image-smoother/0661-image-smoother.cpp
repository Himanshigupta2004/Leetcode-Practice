class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n, 0));
        
        vector<pair<int,int>> dir = {
            {-1,0}, {1,0}, {0,-1}, {0,1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}, {0,0}
        };
        
        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                q.push({i, j});
            }
        }
        
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            int sum = 0, count = 0;
            
            for(auto d : dir) {
                int row = i + d.first;
                int col = j + d.second;
                
                if(row >= 0 && row < m && col >= 0 && col < n) {
                    sum += img[row][col];
                    count++;
                }
            }
            
            result[i][j] = floor(sum / count);
        }
        
        return result;
    }
};
