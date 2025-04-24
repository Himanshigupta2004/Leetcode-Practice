class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int> mp,mp1;
        for(auto it:nums){
            mp1[it]++;
        }
        int uniqueele=mp1.size();
        int cnt=0;
        while(j<n){
            mp[nums[j]]++;
            while(i<=j && mp.size()==uniqueele){
                cnt+=(n-j);
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return cnt;

    }
};