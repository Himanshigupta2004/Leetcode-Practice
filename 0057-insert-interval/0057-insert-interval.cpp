class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        if(intervals.empty()) return{};
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=0;i<intervals.size();i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(ans.back()[1]<s){
                ans.push_back({s,e});
            }
            else{
                ans.back()[1]=max(ans.back()[1],e);
            }
        }
        return ans;
    }
};