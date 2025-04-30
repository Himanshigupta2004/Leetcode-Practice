class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(auto num:nums){
            string str=to_string(num);
            if(str.length() %2 ==0){
                count++;
            }
        }
        return count;
    }
};