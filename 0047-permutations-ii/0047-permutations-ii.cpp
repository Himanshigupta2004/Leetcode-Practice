class Solution {
public:
    void solve(int ind,set<vector<int>>& ans,vector<int>& nums){
        if(ind>=nums.size()){
            ans.insert(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[ind],nums[i]);
            solve(ind+1,ans,nums);
            swap(nums[ind],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(0,ans,nums);
        vector<vector<int>> result(ans.begin(),ans.end());
        return result;
    }
};