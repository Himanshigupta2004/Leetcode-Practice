class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<int> dist(n+1, 1e8);
        dist[k] = 0;
        for (int i = 0; i < n - 1; i++) {

            for (const auto& it : times) {
                int a = it[0];
                int b = it[1];
                int wt = it[2];
                if (dist[a] != 1e8 && dist[a] + wt < dist[b]) {
                    dist[b] = dist[a] + wt;
                }
            }
        }
        int delay=0;
        for(int i=1;i<=n;i++){
          if(dist[i]==1e8) return -1;
          delay=max(delay,dist[i]);
        }
        return delay;
    }
};