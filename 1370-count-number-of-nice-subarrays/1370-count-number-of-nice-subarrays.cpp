class Solution {
public:
    int solve(vector<int>& nums,int k){
        int i=0,j=0;
        int ans=0;
        int sum=0;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>k){
                sum-=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        return solve(nums,k)-solve(nums,k-1);
    }
};