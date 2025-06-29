class Solution {
public:
    // int count=0;
    const int MOD = 1e9 + 7;
    // void generatesub(int curr,vector<int>& nums,int target,vector<int>& subarr){
    //     if(curr==nums.size()){
    //         if(!subarr.empty()){
    //             int mini=*min_element(subarr.begin(),subarr.end());
    //             int maxi=*max_element(subarr.begin(),subarr.end());
    //             if(mini+maxi<=target){
    //                 count=(count+1)%MOD;
    //             }
    //         }
    //         return;
    //     }
    //     subarr.push_back(nums[curr]);
    //     generatesub(curr+1,nums,target,subarr);
    //     subarr.pop_back();
    //     generatesub(curr+1,nums,target,subarr);
    // }
    int numSubseq(vector<int>& nums, int target) {
    //   vector<int> subarr;
    //   generatesub(0,nums,target,subarr);
    //   return count;

    sort(nums.begin(),nums.end());
    vector<int> power(nums.size(),1);
    for(int i=1;i<nums.size();i++){
        power[i]=(power[i-1]*2)%MOD;
    }
    int left=0,right=nums.size()-1;
    int result=0;
    while(left<=right){
        if(nums[left]+nums[right]<=target){
            result= (result+power[right-left]) % MOD;
            left++;
        }
        else{
            right--;
        }
    }
    return result;
    }
};