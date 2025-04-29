class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=0,cnt=0;
        long long ans=0;
        while(r<n){
            if(nums[r]==mx) cnt++;
            while(l<=r && cnt>=k){
                ans+=(n-r);
                if(nums[l]==mx) cnt--;
                l++;
            }
            r++;
        }
        return ans;
    }
};