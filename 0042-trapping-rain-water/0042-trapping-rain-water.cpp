class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax=INT_MIN,rightmax=INT_MIN;
        int left=0,right=height.size()-1;
        int total=0;
        while(left<right){
            if(height[left]>height[right]){
                if(height[right]>rightmax){
                    rightmax=height[right];
                }
                else{
                    total+=rightmax-height[right];
                }
                right--;
            }
            else{
            if(height[left]>leftmax){
                leftmax=height[left];
            }
            else{
                total+=leftmax-height[left];
            }
            left++;
            }
        }
        return total;
    }
};